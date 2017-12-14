def permutations(string):
    length = len(string)
    list_perm = []

    for i in range(length):

        new1 = string[i]+string[:i]+string[i+1:]
        list_perm.append(new1)
        new2 =new1[0]+new1[2]+new1[1]
        list_perm.append(new2)
    
        j = i + 1
        new1 = string[j]+string[:j]+string[j+1:]
        list_perm.append(new1)
        new2 =new1[0]+new1[2]+new1[1]
        list_perm.append(new2)
    
        k = j + 1
        new1 = string[k]+string[:k]+string[k+1:]
        list_perm.append(new1)
        new2 =new1[0]+new1[2]+new1[1]
        list_perm.append(new2)
        return(', '.join(list_perm))

print(permutations('abc'))
