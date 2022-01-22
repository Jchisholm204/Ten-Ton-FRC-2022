import csv
import os
from datetime import datetime
from datetime import timedelta

loggedInUsers = []
loggedInUsersTimeStamp = []

def numFromList(list, index):
    for i in range(0, len(list)):
            if list[i] == index:
                return i

while True:
    usrCode = int(input("Student ID: "))

    now = datetime.now()
    DateNow = datetime.strftime(now, "%m/%d/%Y")
    TimeNow = datetime.strftime(now, "%H:%M:%S")
    timeStamp = datetime.timestamp(now)

    if os.path.exists(f"{os.getcwd()}/UserFiles/{usrCode}.csv") == False:
        with open(f"{os.getcwd()}/UserFiles/{usrCode}.csv", "a", newline='') as usrFile:
            writer = csv.writer(usrFile)
            writer.writerow(["Date", "Time In", "Time Out", "Time Spent", "Time Toltal"])

    if usrCode in loggedInUsers:
        userIndex = numFromList(loggedInUsers, usrCode)
        
        loginTime = datetime.fromtimestamp(loggedInUsersTimeStamp[userIndex])

        timeDiff = (now - loginTime)
        accTime = 0

        with open(f"{os.getcwd()}/UserFiles/{usrCode}.csv", "r") as timeFile:
            reader = csv.reader(timeFile)
            for row in reader:
                if row[3] != 'Time Spent':
                    accTime += float(row[3])

        timeTotal = accTime + timeDiff.total_seconds()

        with open(f"{os.getcwd()}/UserFiles/{usrCode}.csv", "a", newline='') as usrFile:
            writer = csv.writer(usrFile)
            writer.writerow([DateNow, loginTime, TimeNow, timeDiff.total_seconds(), timeTotal])

        loggedInUsers.remove(usrCode)
        loggedInUsersTimeStamp.pop(userIndex)

    else:
        loggedInUsers.append(usrCode)
        loggedInUsersTimeStamp.append(datetime.timestamp(now))
