"""
File Name: Exercise25.py
Developer: Anthony Hansen
Date Last Modified: 31.08.2013
Description: The assignment was to find a two-digit number such that
             the square has the rightmost two digits the same as the
             original number. In other words, find AB, such that
             AB*AB=CAB
Email Address: hansen.tony92@gmail.com
"""

#The number is 25 with its square of 625.
#I found it by using the following program:

number = 10

while number < 31:
    print(number, ":", number**2)
    number += 1
