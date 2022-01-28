import csv
from hashlib import new
import os
from datetime import datetime
from timeE import getTotalTime

loggedInUsers = []
loggedInUsersTimeStamp = []

# Return the index # of an item in a list
def numFromList(list, index):
    for i in range(0, len(list)):
            if list[i] == index:
                return i

# Create A New User (Creates Log File for Student), Returns False if the user already exists
def CreateNewUser(userName):
    if (os.path.exists(f"{os.getcwd()}/{userName}.csv") == True):
        return False
    else:
        with open(f"{os.getcwd()}/UserFiles/{userName}.csv", "a", newline='') as usrFile:
            writer = csv.writer(usrFile)
            writer.writerow(["Date", "Time In", "Time Out", "Time Spent (Seconds)", "Time Toltal (Seconds)"])
        return True

# Logs In a User
def LoginTask(user, timestamp):
    #Add the User to the list of logged in users
    loggedInUsers.append(user)
    loggedInUsersTimeStamp.append(timestamp)

# Logs Out a User
def LogoutTask(user, date, now, time):
    # Get the index the of the user in order to access their login time
    usrIndex = numFromList(loggedInUsers, user)
    # Get The Time The User Logged In From Their TimeStamp
    timeIn = datetime.fromtimestamp(loggedInUsersTimeStamp[usrIndex])
    # Format the DateTime into just Time
    timeInFormatted = datetime.strftime(timeIn, "%H:%M:%S")
    # Calculate the time the user was logged in for
    tTime = (now - timeIn)
    # Get The Users Previous Times
    pTime = getTotalTime(user)
    # Add the Time The User Spent Today to the Previous Time to get Toltal Time
    Ptime = pTime + tTime.total_seconds()
    # Open the users file and append their latest entry to their log
    with open(f"{os.getcwd()}/UserFiles/{user}.csv", "a", newline='') as usrFile:
        writer = csv.writer(usrFile)
        writer.writerow([date, timeInFormatted, time, tTime.total_seconds(), int(pTime)])

    # Remove the User From the list of logged in users
    loggedInUsers.pop(usrIndex)
    loggedInUsersTimeStamp.pop(usrIndex)
    
    # Return the Users Toltal Time, and the time they spent today in Seconds
    return [pTime, tTime.total_seconds()]

def main():
    # Give The User Instructions
    print("Scan Your Student ID")

    # Get The Input (Student ID Number) From The User Through the Barcode Scanner
    userID = int(input("Student ID: "))
    print("\n")

    # Record the Current Date and Time
    now = datetime.now()
    DateNow = datetime.strftime(now, "%m/%d/%Y")
    TimeNow = datetime.strftime(now, "%H:%M:%S")

    # If User Logged in --> Log User Out
    if userID in loggedInUsers:
        rton = LogoutTask(userID, DateNow, now, TimeNow)
        # Print The Users Time Spent Today and Total
        print(f"User {userID} Logged Out\nTime Today: {rton[1]/60/60} Hours\nTime Total: {rton[0]/60/60} Hours\n\n")

    # If User NOT Logged In --> Log User In
    else:
        #Check if the Student is a returning user
        newUser = CreateNewUser(userName=userID)

        #Log in the User
        LoginTask(userID, datetime.timestamp(now))

        # Print to let the user know they logged in successfully
        if(newUser == True): # Give alternate messages for new and returning users
            print(f"Logged in new user:\n{userID}\n\n")
        else:
            print(f"Logged in:\n{userID}\n\n")



while True:
    main()