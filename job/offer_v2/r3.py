'''
找出数组中重复的第一个数字，如输入[2,3,1,0,2,5,3],输出2或3
'''

if __name__ =='__main__':

    liInt = list(map(int,input().split(',')))
    '''
    解法1：构建哈希表，key为数组，可以以O(1)时间复杂度判断数字是否在哈希表中，value为该数字出现的次数，
    针对本题可以不用key-value对，直接用列表也可。该解法的时间复杂度为O(n),空间复杂度为O(n)
    '''
    hash_dic = {}
    
    for i in range(len(liInt)):
        if liInt[i] in hash_dic:
            hash_dic[liInt[i]] = hash_dic[liInt[i]] + 1
            print(liInt[i])
            break
        hash_dic[liInt[i]] = 1

    '''
    解法2
    '''
    