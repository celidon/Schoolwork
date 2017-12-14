string = "ABC"


for letters in string:
    for i in letters:
        i = len(i)
        print(string[i:] + string[:i])
        i= i + 1
        print(string[i:] + string[:i])
