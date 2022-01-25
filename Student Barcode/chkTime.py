from timeE import getTotalTime as getStudentTime


def chkTime():
    StudentID = int(input("Enter A Student ID: "))
    print(f"Student {StudentID} has {getStudentTime(StudentID)/60/60} Hours on File\n")

while True:
    chkTime()