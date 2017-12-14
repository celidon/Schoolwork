"""
File Name: tempguage.py
Developer: Anthony Hansen
Date Last Modified: 02.10.2013
Description: Write a program that will prompt a user to enter a temperature
             as an integer. Your program will print "it is hot" is the
             temperature is over 100, "it is cold" if the temperature is
             under 60, and "it is just right" if the temperature is between
             61 and 99 inclusive. The program continues to ask for temperatures,
             and evaluates them as above, until the user enters a temperature of
             0.

             This is what the output should look like:
             Please enter a temperature: 95
             It is just right.
             Please enter a temperature: 110
             It is hot.
             Please enter a temperature: 32
             It is cold.
             Please enter a temperature: 0
             Good bye!
Email Address: hansen.tony92@gmail.com
    
"""
print("Simply input a temperature of 0 to stop running the program.")

temp = int(input("Please input the current temperature in Fahrenheit:\n"))

while (temp != 0):

    if (61 <= temp <= 99):
        print("It is just right.\n")

    elif (temp > 99):
        print("It is hot.\n")

    else:
        print("It is cold.\n")

    temp = int(input("Please input the current temperature in Fahrenheit:\n"))

print("Goodbye!\n")
