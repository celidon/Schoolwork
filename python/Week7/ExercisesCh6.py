"""
File Name: ExercisesCh6.txt
Developer: Anthony Hansen
Date Last Modified: 02.10.2013
Description: 
Email Address: hansen.tony92@gmail.com 
"""

"""
13--Define a function 'make_payment(P)' that error checks a payment on a credit card balance. The credit limit is $1000 and the minimum payment is
$20.
"""
def make_payment(P):
    
    limit = int(1000)
    min_P = int(20)

    if(limit >= P >= min_P):
        print("Success!")
    elif(P < min_P):
        print("Retry\nYour minimum payment is $20")
    else:
        print("Retry\nYour payment must be less than your limit of $1000")
		
"""
14--Write a function that takes the amount of money a user wants to
put on a calling card and then outputs the amount they really receive
through special offers.
"""
def card_amount():
    
    print("Please select how much to add to your card:\n")
    print("$5 $10 $20 $50 $100\n")
    payment = int(input("$"))
    
    if(payment == 5) or (payment == 10):
        amount = payment
    elif(payment == 20):
        amount = payment + 3
        print("You receive a bonus of $3\n")
    elif(payment == 50):
        amount = payment + 8
        print("You receive a bonus of $8\n")
    elif(payment == 100):
        amount = payment + 20
        print("You receive a bonus of $20\n")
    else:
        amount = 0
        print("Sorry, that amount is not an option")

    print("You now have $",amount," on your card")
	
"""
15--
"""
