import sys
input = sys.stdin.readline
t = int(input())
for i in range(t):
    n = int(input())
    s = []
    for j in range(n):
        a, b = map(int, input().split())
        s.append([a, b])
    s.sort()
    min_n = s[1]
    prev = 9999999
    cnt = 0
    for k in s:
        docu, meet = k
        if(meet< prev):
            cnt = cnt + 1
            prev = meet
    print(cnt)
