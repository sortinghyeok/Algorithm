import sys
from collections import defaultdict
input = sys.stdin.readline
#위 코드없이 내장 함수 input사용시 테스트케이스는 모두 성공하지만 시간초과가 뜬다. input의
# 처리 속도가 느려서라고 생각되는데 정확한 이유는 알 수 없음
trees = defaultdict(int)
num = 0

while True :
    tree = input().strip()
    if tree == '':
        break
    trees[tree] += 1
    num += 1


treeNames = sorted(list(trees.keys()))
for i in treeNames:
    print(i, "{0:.4f}".format(trees[i]*100/num))

