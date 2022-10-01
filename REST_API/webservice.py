from flask import Flask, request, jsonify, redirect
import requests
app = Flask(__name__)
app.config["DEBUG"] = True

employees =[
    {
        'name':'Ramesh',
        'id':'1221',
        'salary':'15000',
        'age':'30'
    },
    {
        'name':'Suresh',
        'id':'1222',
        'salary':'17000',
        'age':'32'
    },
    {
        'name':'Rajesh',
        'id':'1121',
        'salary':'10000',
        'age':'24'
    }
]

@app.route('/') 
def welcome():
    #print("Welcome to Python Web Service")
    return "<h1>Welcome to Python Web Service</h1><h3><b>Done By :</b><br>Maalolan K<br>18BLC1077</h3><p>Click <a href = \"/employee/getEmployees\">here</a> to view all employees</p>"

@app.route('/employee/getEmployees', methods = ['GET'])
def getEmployees():
    return jsonify(employees)

@app.route('/employee/getEmployee/<id>', methods = ['GET'])
def getEmployee(id):
    employ = [emp for emp in employees if(emp['id'] == id)]
    return jsonify(employ)

@app.route('/employee/updateEmployee/<id>', methods = ['PUT'])
def updateEmployee(id):
    employ = [emp for emp in employees if(emp['id'] == id)]
    if('id' in request.json):
        print("Student Available")
    if('name' in request.json):
        employ[0]['name'] = request.json['name']
    return(jsonify(employ))

@app.route('/employee/addEmployee', methods = ['POST'])
def addEmployee():
    emp = {
        'name':request.json['name'],
        'id':request.json['id'],
        'salary':request.json['salary'],
        'age':request.json['age']
    }
    employees.append(emp)
    return "<h2>SUCCESSFULLY ADDED. CLICK <a href = \"/employee/getEmployees\">HERE</a></h2>"

@app.route('/employee/deleteEmployee/<empid>', methods = ['DELETE'])
def deleteEmployee(empid):
    employ = [emp for emp in employees if (emp['id']==empid)]
    if(len(employ)>0):
        employees.remove(employ[0])
    return "<h2>SUCCESSFULLY DELETED. CLICK <a href = \"/employee/getEmployees\">HERE</a></h2>"

if(__name__ == "__main__"):
    app.run()