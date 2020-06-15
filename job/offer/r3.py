# -*- encoding: utf-8 -*-
'''
@File    :   r3.py
@Time    :   2020/06/05 15:27:50
@Author  :   paul yu 
@Github  :   https://github.com/nicePaul521/Algorithm.git
'''

# here put the import lib

'''
找出数组中重复的第一个数字，如输入[2,3,1,0,2,5,3],输出2或3
'''

def fun1(lst):
    '''
    解法1：构建哈希表，key为数组，可以以O(1)时间复杂度判断数字是否在哈希表中，value为该数字出现的次数，
    针对本题可以不用key-value对，直接用列表也可。该解法的时间复杂度为O(n),空间复杂度为O(n)
    '''
    hash_dic = {}
    
    for i in range(len(lst)):
        if lst[i] in hash_dic:
            hash_dic[lst[i]] = hash_dic[lst[i]] + 1
            return lst[i]
        hash_dic[lst[i]] = 1

    return -1

def fun2(lst):
    '''
    解法2: 重排数组，将数组索引与数字值进行匹配，当扫描到下标为i的数字m，首先比较这个数字是不是等于i，
    如果是，则接着扫描下一个数字，如果不是，则拿它与m第个数字比较。如果它和第m个数字相等，就找到了重复的数字。
    该解法的时间复杂度为O(n),空间复杂度为O(1)
    '''
    for i,num in enumerate(lst):
        while i!=num:
            if num == lst[num]:
                return num
            lst[i],lst[num] = lst[num],lst[i]

    # for i in range(len(lst)):
    #     while(lst[i] != i):
    #         if lst[lst[i]] == lst[i]:
    #             return lst[i]
    #         m = lst[i]
    #         lst[i] = lst[m]
    #         lst[m] = m

    return -1

def countRange(lst,start,middle):
    count=0
    for i in range(len(lst)):
        if lst[i]>=start and lst[i]<=middle:
            count = count + 1
        
    return count

def fun3(lst):
    '''
    解法3:
    '''
    start = 1
    end = len(lst)
    while(end>=start):
        middle = (end-start)/2 + start
        count = countRange(lst,start,middle)
        if end == start:
            if count>1:
                return start
            else:
                break
        if count > (middle-start+1):
            end = middle
        else:
            start = middle + 1
    return -1

if __name__ =='__main__':

    liInt = list(map(int,input().split(',')))
    # print(fun1(liInt))
    # print(fun2(liInt))
    print(fun3(liInt))