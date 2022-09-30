import smtplib
  

#Enable access to the less safer apps in your Gmail Account before running code
s = smtplib.SMTP('smtp.gmail.com', 587)
s.starttls()
sendermail=input("Enter Sender's Email:  ")
senderpass=input("Enter Password: ")
receivermail=input("Enter mail ID of reciever:  ")

s.login(sendermail, senderpass)
  
message = "Hello World"
  
s.sendmail(sendermail, receivermail, message)
  
if(s.quit()):
    print("Sent")
else:
    print("Failed")