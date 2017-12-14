"""

File Name: Exercise22.py
Developer: Anthony Hansen
Date Last Modified: 31.08.2013
Description: The assignment was to write a program that prompts for a
             number greater than 2 and then continuously takes the squareroot
             until the number is less than 2
Email Address: hansen.tony92@gmail.com

"""

number_str = input("Please insert a positive number of your choice greater than 2: ")
number_int = int(number_str)

while number_int >= -1:

    if number_int > 2:

        attempt = 1
            
        print("The squareroots of the number until it is lower than 2: ")

        while number_int > 2:
            print(attempt, ": ", number_int ** 0.5)
            number_int = number_int ** 0.5
            attempt += 1

        break
    
    else:
        number_str = input("Please insert a positive number of your choice greater than 2: ")
        number_int = int(number_str)

