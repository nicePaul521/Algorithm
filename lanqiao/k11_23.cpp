#include "stdio.h"

typedef struct LNode
{
    int data;//数据域
    struct LNode *next;//指针域
}LNode;//单链表

typedef struct
{
    int data[maxSize];
    int length;
}Sqlist;//顺序表

typedef struct
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;//二叉树

typedef struct
{
    int data[MaxSize];
    int top;
}SqStack;//顺序栈

void insertData(LNode *L,int x)
{
    LNode *s = *L
    LNode *p;
    C = (LNode*)malloc(sizeof(LNode))//分配Lnode大小的空间
    C->data = x;
    while(s->data<x) {p = s;s = s->next;}//找到要插入节点的前驱与后继节点
    p->next = C;//修改前驱节点的后继节点为当前节点
    C->next = s;//修改当前节点的后继节点为后继节点s
}
void InsertSort(int R[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)//n次迭代，每次迭代排序插入一个数字R[i]
    {
        temp = R[i];
        j = i-1;
        while(j>=0&&temp<R[j])//将大于待排序的数字后移
        {
            R[j+1] = R[j];
            --j;
        }
    R[j+1] = temp;//j为从后向前查找到的第一个比起值小的数字所对应索引
    }
   
bool findElem(Sqlist L,int x)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==x)
        return true;
    }
    return false;
}

Sqlist Bing(Sqlist A,Sqlist B)
{
    Sqlist C;
    int j = 0;
    C.data[] = {-1}
    for(int i=0;i<A.length;i++)
    {
        if(findElem(Sqlist B,A.data[i]))
        {
            C.data[j++] = A.data[i];
        }
    }
    C.length = j;
    return C;
}

void unique(LNode *L)
{
    LNode *s = L->next;
    LNode *b,*p;
    while(s!=null)
    {
        for(b=s->next;b!=null;b=b->next)
        {
            if(s->data==p->data)
            {
                p->next = b->next;//从L中删除当前节点
            }
            p = b;//指针p记录前驱节点的地址
        }
        s = s->next;
    }
}

int n=0;//全局变量
void travel(BTNode *p)
{
    if(p!=NULL)
    {
        ++n;
        travel(p->lchild);
        travel(p->rchild);
    }
}

void ten2bin(int x)
{
    int stack[MaxSize];
    int top = -1;
    
    while(x!=0)
    {
        stack[++top] = x%2;
        x /=2;
    }
    while(top!=-1)
    print("%d",stack[top--]);
}

}