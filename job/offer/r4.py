# -*- encoding: utf-8 -*-
'''
@File    :   r4.py
@Time    :   2020/06/12 15:23:44
@Author  :   paul yu 
@Github  :   https://github.com/nicePaul521/Algorithm.git
'''

# here put the import lib
import numpy as np

'''
题目要求：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下的递增顺序排序，请完成一个函数，输入这样的
一个二维数组和整数，判断数组中是否含有该整数。
输入：二维数组大小m,n,及要判断的整数x。接下来每行输入n个数，输入m行
输出：布尔值
'''


'''
paramters:
return: 
overview:对矩阵右上角数字进行判断是否为查找值，如果比查找值小，则该数字所在行不存在该数字，因此行加一，如果比查找值大则所在列不存在该数字，因此列减1.
'''
def fun(matrix,row,col,value):
   
    if row<=0 or col<=0:
        return False
    r = 0
    c = col-1
    while(r<row and c>0):
        if matrix[r,c] == value:
            return True
        elif matrix[r,c] < value:
            r = r + 1
        else:
            c = c - 1

    return False

if __name__ == '__main__':
    m,n,x = list(map(int,input().split(' ')))
    data = []
    for i in range(m):
        row = list(map(int,input().split()))
        data.append(row)

    matrix = np.array(data)
    r = fun(matrix,m,n,x)
    print(r)