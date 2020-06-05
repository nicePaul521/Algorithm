def conflict(pos,pos_lst):
    if len(pos_lst) == 0:
        return False
    i,j = pos[0],pos[1]
    for p in pos_lst:
        if (p[0]==i and abs(p[1]-j)==0) or (p[1]==j and abs(p[0]-i)==0):
            return True

    return False

def dfs(deepth,r,start,pos_lst):
    #终止条件
    if deepth == n*m:
        r = r + 1
        return

    for k in range(start,m):
        row = deepth/n
        if data[row][k] == 0 or conflict([row,k],pos_lst):
            deepth  = deepth + 1
            continue
        for flag in [True,False]:
            if flag == True:                
                dfs(deepth+1,r,start+1,pos_lst+[(row,k)])
            else:
                pos_lst_n = pos_lst.copy()
                dfs(deepth+1,r,start+1,pos_lst_n)

if __name__ == "__main__":
    global n,m,data

    n,m = input().split()
    n = int(n)
    m = int(m)
    data = []
    for i in range(n):
        x = input().split()
        x_lst = [int(e) for e in x]
        data.append(x_lst)
    
    r = 0
    deepth = 1
    start = 0
    pos_lst = []
    dfs(deepth,r,start,pos_lst)
    print()