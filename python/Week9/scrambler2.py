"""

File Name: scramble.py
Developer: Anthony Hansen
Date Last Modified: 26.09.2013
Description: The assignment was to write a program that will open a text file,
             scramble the text in the file(keeping the first and last letters
             the same), and write the scrambled text to a new file.
Email Address: hansen.tony92@gmail.com

"""

import string
import random

def file_name():
    file_name = input("Please input the name of the text file you wish to scramble:\n")
    input_file = open(file_name,'r')
    output_file = open('scrambled.txt','w')
    for line_str in input_file:
        file = line_str
        print(scramble(file),file = output_file)
    output_file.close()
    input_file.close()
    print("The scrambled text will be found in the new file 'scrambled.txt'")
    
def scramble_file(file):
    list_file = split_text(file)
    new_list = []
    for word in list_file:
        is_punctuated = punctuated(word)
        if(len(word)<4):
            new_list.append(word)
        elif(not is_punctuated) :           
            new_list.append(scramble(word))
        else:
            if(len(word[:is_punctuated])<4):
                new_list.append(word)
            else:
                new_list.append(str(scramble(word[:is_punctuated]))+(word[is_punctuated:]))
        return(" ".join(new_list))

#check to see if there is any punctuation in a word        
def punctuated(word):
    for letter in word:
        if letter in string.punctuation:
            punctuation = word.find(letter)
            break
        else:
            punctuation = 0

    return (punctuation)

#take in a text file and seperate the words
def split_text(file):
    text_words = []
    text_words = file.split(' ')
    return(text_words)

#scramble the letters in each seperated word
def scramble(string):
    
    string.strip()
    new_string = list(string) 
    random.shuffle(new_string)
    new_string=''.join(new_string)
    return(new_string)

file_name()
