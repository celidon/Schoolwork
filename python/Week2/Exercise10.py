"""

File Name: Exercise10.py
Developer: Anthony Hansen
Date Last Modified: 31.08.2013
Description: The assignment was to write a program that prompts for a
             number until the number is a perfect square.
Email Address: hansen.tony92@gmail.com

""" 

number_str = input("Please insert a positive number of your choice: ")
number_int = int(number_str)

while number_int > 0:

    x = int(number_int ** (.5))
    
    if (x * x) == number_int:
        print (number_int, " is a perfect square. Its squareroot is ", x)
        break

    else:
        number_str = input("Please insert a positive number of your choice: ")
        number_int = int(number_str)


