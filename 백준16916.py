def kmpTable(pattern):
    length = len(pattern)
    table = [0]*length
    j = 0

    for i in range(1, length):
        while j > 0 and pattern[i] != pattern[j]:
            j = table[j - 1] #일치한다면 j, i를, 일치하지 않는다면 i만
        if pattern[i] == pattern[j]:
            j += 1
            table[i] = j

    return table

def isExist(parent, pattern):
    table = kmpTable(pattern)
    parentlen = len(parent)
    patternlen = len(pattern)
    j = 0
    for i in range(parentlen):
        while j>0 and parent[i] != pattern[j]:
            j = table[j-1] #suffix와 일치했던 부분까지 가져오는 것!
        if parent[i] == pattern[j]:
            if j == patternlen- 1:
                return 1
            else :
                j+=1
    return 0

parent = input()
pattern = input()
print(isExist(parent, pattern))