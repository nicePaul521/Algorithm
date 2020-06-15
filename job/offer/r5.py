# -*- encoding: utf-8 -*-
'''
@File    :   r5.py
@Time    :   2020/06/12 18:11:34
@Author  :   paul yu 
@Github  :   https://github.com/nicePaul521/Algorithm.git
'''

# here put the import lib
'''
请实现一个函数，把字符串中的每个空格替换成“%20”，例如输入“We are happy”，则输出“We%20are%20happy”
'''

if __name__ == '__main__':
    s = input()
    print(s.replace(' ','%20'))
