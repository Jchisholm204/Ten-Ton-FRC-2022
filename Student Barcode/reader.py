import os
import csv
from datetime import datetime
from datetime import timedelta

usrReq = int(input("Enter A Student ID: "))

accTime = 0

if os.path.exists(f"{os.getcwd()}/UserFiles/{usrReq}.csv") == True:
    with open(f"{os.getcwd()}/UserFiles/{usrReq}.csv", "r") as timeFile:
        reader = csv.reader(timeFile)
        for row in reader:
            if row[3] != 'Time Spent':
                accTime += float(row[3])

print(f"The Student: {usrReq} Has {(accTime/60)/60} Hours on File")