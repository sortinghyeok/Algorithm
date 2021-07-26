import sys
input = sys.stdin.readline()

number1, number2 = map(str, input.split())
#한 줄에 안받으면 틀림

# str을 받았을 시
# sum = 0
# for i in range(len(number1)):
#    for k in range(len(number2)):
#       sum += int(number1[i])*int(number2[k])
# n^2은 시간 초과뜸

# 123*34 = 1*3 + 1*4 + ... + 3*4 = (1+2+3)*3 + (1+2+3)*4 = (1+2+3)(3+4)
num1 = 0
num2 = 0
for i in number1:
    num1 += int(i)
for i in number2:
    num2 += int(i)

print(num1*num2)