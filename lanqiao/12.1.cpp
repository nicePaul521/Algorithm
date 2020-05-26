#include "stdio.h"

//完成数组R[low]到R[high]范围内对在位置low上的节点进行调整。
void Sift(int R[],int low,int high)
{
    int i = low,j=2*i;//R[j]是R[i]的左孩子节点。low为待调整节点
    int temp = R[i];
    while(j<=high)
    {
        if(j<high&&R[j]>R[j+1])//右孩子比左孩子大，j指向右孩子。
            ++j;
        if(temp>R[j])//待调整值比孩子节点值小，则对调
        {
            R[i] = R[j];
            i=j;//i指向调整的位置
            j=2*i;//j重定向到左孩子节点
        }
        else
            break;//已经找到最终调整位置
    }
    R[i]=temp;//被调整节点放入最终位置
}
//堆排序
void heapSort(int R[],int n)
{
    int i,temp;
    for(i=n/2;i>=1;i--)//从非叶子节点开始调整堆
        Sift(R,i,n);
    for(i=n;i>=2;--i)//从后向前调整，与第一个关键字对调，第一个关键字是最小的数，放在最后
    {
        temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        Sift(R,1,i-1);//在减少了一个的关键字序列中进行调整
    }
}

typedef struct BTNode
{
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

BTNode* BSTSearch(BTNode* bt,int key)
{
    if(bt==NULL)
        return NULL;//查找不成功返回NULL
    else
    {
        if(bt->key==key)
            return bt;
        else if(key<bt->key)
            return BSTSearch(bt->lchild,key);
        else
            return BSTSerach(bt->rchild,key)
    }
}