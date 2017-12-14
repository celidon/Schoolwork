"""

File Name: Exercise1.py
Developer: Anthony Hansen
Date Last Modified: 5.09.2013
Description: The assignment was to write a program that outputs
             all the three digit numbers divisible by 17
Email Address: hansen.tony92@gmail.com

"""

y=0

while 0 <= y <= 100 :
    x = 17 * y
    y = y + 1

    if 100 < x < 1000:
        print (x)
