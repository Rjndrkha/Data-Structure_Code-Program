from selenium import webdriver
import time

no_of_drivers = int(input("Enter number of drivers: "))
url = input("Enter URL: ")
refresh_timeout = int(input("Enter refresh Rate in seconds : "))
drivers = []

for i in range(no_of_drivers):
    drivers.append(webdriver.Chrome(executable_path=r"C:\Users\KUNTAL\Downloads\chromedriver_win32\chromedriver.exe"))
    drivers[i].get(url)

while True:
    time.sleep(refresh_timeout)
    for i in range(no_of_drivers):
        drivers[i].refresh()
