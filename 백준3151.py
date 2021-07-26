import sys
input = sys.stdin.readline

num = int(input())
s = list(map(int, sys.stdin.readline().split()))
s.sort()

teamcount = 0

for i in range(num):
    now = i
    need = 0 - s[now]
    left = i+1
    right = num-1
    while(left<right):
        if (s[left] + s[right]) == need :
            teamcount = teamcount + 1
            left = left + 1
        elif (s[left] + s[right]) < need :
            left = left + 1
        elif (s[left] + s[right]) > need :
            right = right - 1
        else : left = left + 1

print(teamcount)



print(s)
