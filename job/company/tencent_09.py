if __name__ =="__main__":

    p = [0]*100005
    t = [0]*100005
    n = int(input())
    for i in range(1,n+1):
        x = int(input())
        p[i] = min(p[i-1],t[i-1])+x
        if i==1:
            continue
        t[i] = min(p[i-1],p[i-2])

    print(min(p[n],t[n]))