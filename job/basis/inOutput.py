import sys

#一行输入多个的情况，如：[[1,2],[3,4]],4

#法1
L = list(eval(input()))
array = L[0]
target = L[1]

#法2,输入为4,[[1,2],[3,4]]
target,array = input().split(',', 1)
target = int(target)
array = list(eval(array))

#法3,按行输入，将一行输入作为一个字符串，并过滤多余空格
a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()

# 先输入个数n，后输入n个数的情况
n = int(input())
data = []

for i in range(n):
    b = int(input())
    data.append(b)

# 含有空格的一行数的输入
# liInt = list(map(int,input().split())) #split()默认以空格作为分隔符

#输出处理
#将['1','2','3'] ---> 1,2,3,4 或者 1 2 3 4
a = ['1','2','3','4']
print(','.join(a))
print(' '.join(a))

#循环输出多个数，两个数之间用空格隔开
a = [1,2,3,4]
for i in a:
    print(i,end=' ')