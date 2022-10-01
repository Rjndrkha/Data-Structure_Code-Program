import hashlib
import random
import qrcode
import time
import json
import os
from mailer import mail

directory = os.getcwd()

file = open('freshers.txt', 'r')
file_data = file.readlines()
file.close()

file_data = [file_data[i].split(',') for i in range(1, len(file_data))]
names = [file_data[i][0] for i in range(len(file_data))]
roll_number = [file_data[i][1] for i in range(len(file_data))]
phone_number = [file_data[i][2] for i in range(len(file_data))]
email = [file_data[i][3] for i in range(len(file_data))]

def generateSHA():
    try:
        roll_number_sha256_map = {}
        for i in range(len(file_data)):
            a_string = names[i] + '_' + roll_number[i] + '_' + phone_number[i]
            a_string = list(a_string)
            random.shuffle(a_string)
            a_string = ''.join(a_string)

            hashed_string = hashlib.sha256(a_string.encode('utf-8')).hexdigest()
            print(names[i], hashed_string)
            roll_number_sha256_map[roll_number[i]] = {"hash" : hashed_string, "email" : email[i], "mailed" : False}

        tp = json.dumps(roll_number_sha256_map, indent=4)
        f2 = open('data.json', 'w+')
        f2.write(tp)
        f2.close()
        return True

    except Exception as e:
        print("Exception in SHA:", e.msg)
        return False


def generateQrAndMail():
    data = json.load(open("data.json"))

    try:
        for key, value in data.items():

            img = qrcode.make(value["hash"])
            img_name = key + '.jpg'
            img.save(directory + "/QRs/" + img_name)

            if not value["mailed"]:
                mail(value["email"], directory+"/QRs/"+img_name)
                value["mailed"] = True

            print("\n", value["hash"])
            print("mailed to", key)

        return True

    except Exception as e:
        print("Exception in Mailing", e.message)
        return False

    finally:
        tp = json.dumps(data, indent=4)
        f2 = open('data.json', 'w+')
        f2.write(tp)
        f2.close()


if __name__ == "__main__":
    t1 = time.time()

    shaSucc = False
    while not shaSucc:
        shaSucc = generateSHA()

    mailSucc = False
    while not mailSucc:
        mailSucc = generateQrAndMail()

    t2 = time.time()
    print("\nProcess Completed")
    print(t2 - t1)
