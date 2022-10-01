import cv2
from pyzbar.pyzbar import decode
import requests

import numpy as np
import mysql.connector as sql
import json

db = sql.connect(
    host="sql6.freesqldatabase.com",
    user="sql6514192",
    passwd="cPeZlsijGB",
    database="sql6514192",
    port="3306"
)


def execute(query):
    try:
        cursor = db.cursor()
        cursor.execute(query)
        res = cursor.fetchall()
        db.commit()
        return res

    except sql.Error as err:
        print(err)
        return -1


def verify_qr(purpose):
    url = "http://192.168.43.1:8080/shot.jpg"

    while True:
        raw_image = requests.get(url)
        img_arr = np.array(bytearray(raw_image.content), dtype=np.uint8)
        img = cv2.imdecode(img_arr, -1)

        for barcode in decode(img):
            myData = barcode.data.decode('utf-8')

            query = f""" 
                    SELECT * 
                    FROM Student
                    WHERE shahash = "{myData}";
                    """
            res = execute(query)
            if len(res) > 0:
                if purpose == 1:
                    if res[0][2] == 0:
                        print("\n\t", res[0][0], "Authorizing for Entry.")
                        query = f"""
                                UPDATE Student SET entrystatus = {1}
                                WHERE shahash = "{myData}";
                                """
                        execute(query)
                    else:
                        print(res[0][0], "Already Authorized for Entry.")

                if purpose == 2:
                    if res[0][3] != 0:
                        print("\n\t", res[0][0], "Authorizing for Food.")
                        query = f"""
                                UPDATE Student SET foodstatus = {1}
                                WHERE shahash = "{myData}";
                                """
                        execute(query)
                    else:
                        print(res[0][0], "Already Authorized for Food.")

            else:
                print("Un-Authorized")

        cv2.waitKey(1000)


def read_data():
    file = open('data.json')
    data = json.load(file)

    return data


if __name__ == "__main__":
    verify_qr(1)  # for entry
    # verify_qr(2)  # for food
