import json
from tensorflow.keras.models import model_from_json
from tensorflow.keras.models import load_model
import tensorflow as tf
import cv2
import numpy as np
import time
from selenium import webdriver

from selenium import webdriver
cd = 'C:\\Users\\Bishal\\Documents\\isb\\ml and iot\\Chromedriver.exe'
driver = webdriver.Chrome(cd)
email = "yuyguy721@gmail.com"
password = "621311Hi5"
driver.get("https://www.tinkercad.com/dashboard")
time.sleep(2)
mail = driver.find_element_by_xpath(
    '//*[@id="content"]/div/main/ng-component/main/section/div/div/div/div/div[1]/a[2]')
mail.click()
driver.find_element_by_xpath('//*[@id="userName"]').send_keys(email)
driver.find_element_by_xpath(
    '//*[@id="verify_user_btn"]').click()
time.sleep(2)
driver.find_element_by_xpath('//*[@id="password"]').send_keys(password)
driver.find_element_by_xpath(
    '//*[@id="btnSubmit"]').click()
time.sleep(2)
driver.get('https://www.tinkercad.com/things/gpic8WJBqq8-glorious-robo-gogo')
time.sleep(2)
driver.find_element_by_xpath(
    '/html/body/div[1]/div/app/div/div/main/tk-thing-detail/div/tk-design-content/div/div[2]/div/div[1]/div/div[2]/div[2]/a/button').click()
time.sleep(2)
driver.find_element_by_xpath('//*[@id="CODE_EDITOR_ID"]/div[2]').click()
time.sleep(1)
driver.find_element_by_xpath('//*[@id="SIMULATION_ID"]/div[2]').click()
time.sleep(3)
driver.find_element_by_xpath('//*[@id="SERIAL_MONITOR_ID"]/div[2]').click()
time.sleep(2)
# Model reconstruction from JSON file
with open("C:\\Users\\Bishal\\model_architecture_FaceMask_Detection.json") as f:
    model = model_from_json(f.read())

# Load weights into the new model
model.load_weights(r"C:\Users\Bishal\FaceMask_Detection.h5")

# model.summary()


# Model testing

label = {0: "With Mask", 1: "Without Mask"}
color_label = {0: (0, 255, 0), 1: (0, 0, 255)}

cap = cv2.VideoCapture(0)

cascade = cv2.CascadeClassifier(
    r'C:\Users\Bishal\haarcascade_frontalface_default.xml')


while True:
    (rval, frame) = cap.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = cascade.detectMultiScale(gray, 1.1, 4)

    for x, y, w, h in faces:
        face_image = frame[y:y+h, x:x+w]
        resize_img = cv2.resize(face_image, (150, 150))
        normalized = resize_img/255.0
        reshape = np.reshape(normalized, (1, 150, 150, 3))
        #reshape = np.vstack([reshape])
        result = model.predict(reshape)
        result = result[0][0]

        if result <= 0.5:
            cv2.rectangle(frame, (x, y), (x+w, y+h), color_label[0], 3)
            cv2.rectangle(frame, (x, y-50), (x+w, y), color_label[0], -1)
            cv2.putText(frame, label[0], (x, y-10),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
            driver.find_element_by_xpath(
                '//*[@id="main"]/div/div/div[5]/div[2]/div[4]/div/div[5]/div[2]/div[2]/input').send_keys(0)
            driver.find_element_by_xpath(
                '//*[@id="main"]/div/div/div[5]/div[2]/div[4]/div/div[5]/div[2]/div[2]/div/a[1]/div').click()
            time.sleep(0.5)

        elif result > 0.5:
            cv2.rectangle(frame, (x, y), (x+w, y+h), color_label[1], 3)
            cv2.rectangle(frame, (x, y-50), (x+w, y), color_label[1], -1)
            cv2.putText(frame, label[1], (x, y-10),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
            driver.find_element_by_xpath(
                '//*[@id="main"]/div/div/div[5]/div[2]/div[4]/div/div[5]/div[2]/div[2]/input').send_keys(1)
            driver.find_element_by_xpath(
                '//*[@id="main"]/div/div/div[5]/div[2]/div[4]/div/div[5]/div[2]/div[2]/div/a[1]/div').click()
            time.sleep(0.5)

    cv2.imshow('LIVE',   frame)
    key = cv2.waitKey(10)

    if key == 27:
        break

cap.release()

cv2.destroyAllWindows()
