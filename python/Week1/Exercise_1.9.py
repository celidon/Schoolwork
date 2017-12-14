"""

File Name: Exercise_1.9.py
Developer: Anthony Hansen
Date Last Modified: 31.08.2013
Description: The assignment was to write a program that prompts for a
             number, adds 2, multiplies by 3, subtracts 6, divides by 3
             and gives a back a new number. I added a line of text
             explaining what was happening so that the output has meaning
             to the user.
Email Address: hansen.tony92@gmail.com

"""

number_str = input("Please insert a number of your choice:")
number_int = int(number_str)

print("We are now going to add 2, multiply by 3, subtract 6, "
      "and then divide by 3 to give you a new number")

print ("Your new number is: ", (((number_int + 2) * 3) - 6) / 3,
       ", the same as before")
