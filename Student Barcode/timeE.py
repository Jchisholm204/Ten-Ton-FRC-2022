import os
import csv

# Get The Amount of time the user has logged so far
def getTotalTime(user):
    tTime = 0
    # Return 0 if the User does not exist
    if (os.path.exists(f"{os.getcwd()}/UserFiles/{user}.csv") == False):
        return 0
    
    # Open The Users Log File
    with open(f"{os.getcwd()}/UserFiles/{user}.csv", "r") as timeFile:
        reader = csv.reader(timeFile)
        #Go Through The Users Logs
        for row in reader:
            if row[3] != 'Time Spent':
                # Add all of the Users Time Together
                tTime += float(row[3])

    # Returns the Users Accumulated Time
    return tTime
