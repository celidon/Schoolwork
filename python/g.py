string = "{ABC}"

def permutations(string):
    if len(string) <= 1:
        return [string]
    string2 = []
    for i in range(len(string)):
        s = string[:i] + string[i+1:]
        p = permutations(s)
        for x in p:
            string2.append(string[i:i+1] + x)
        print(string2)
        
permutations(string)
