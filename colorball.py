import sys
input = sys.stdin.readline

n = int(input())
ball = [[i, 0,0] for i in range(n)]
for i in range(n):
    ball[i][1], ball[i][2] = map(int, input().split())

ball.sort(key = lambda x:x[2], reverse=True)
print(ball)
sumlist = []
sum = 0
count = 0
for i in range(n):
    for j in range(count, n):
        if ball[i][1] != ball[j][1]:
            sum += ball[j][2]
    sumlist.append([ball[i][0], sum])
    sum = 0
    count += 1

sumlist.sort()
print(sumlist)
for i in sumlist:
    print(i[1])