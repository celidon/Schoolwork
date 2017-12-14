info = "02/27/1992 00:25:24"

def date_time(info):

#Separating the date from the time
    data=info.split(" ")

#Separating out everything for usage and reordering
    date = data[0].split("/")
    time = data[1].split(":")

    month = int(date[0])
    day = int(date[1])
    year = int(date[2])

    hour = int(time[0])
    minute = int(time[1])
    sec = int(time[2])
    
#Determining if the month and day are valid
    if(hour > 24):
        print("Hour invalid")
    elif(minute > 60):
        print("Minute invalid")
    elif(sec > 60):
        print("Seconds invalid")
    else:
#Determining if it is AM or PM and converting to 12-hour time
        if(hour > 12):
            am_pm = "PM"
            hour = hour - 12
        elif(hour == 12):
            am_pm = "PM"
        elif(hour == 0):
            am_pm = "AM"
            hour = 12
        else:
            am_pm = "AM"

#Determining if the month and day are valid
        if(1 > month or month > 12):
            print("Month invalid")
        else:
            if(1 > day > 31):
                print("Day invalid")
            elif(day > 30 and month == 4 or month == 6 or month == 9 or month == 11):
                print("Day invalid")
            elif(day > 28 and month == 2):
                print("Day invalid")
            else:
#Printing everything out if everything is valid
                print(day,"/",month,"/",year,"\n")
                print(hour,":",minute,":",sec,am_pm,"\n")
                print(month,"/",year,"\n")

date_time(info)
