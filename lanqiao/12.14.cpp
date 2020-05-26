#include "stdio.h"

//单链表节点定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}
//顺序表结构体定义
typedef struct
{
    int data[maxSize];
    int length;
}
//单链表的读取
/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果： 用e返回L中第i个数据元素的值*/
Status GetElem(LinkList L,int i ,ElemType *e)
{
int j;
LinkList p; /*声明一指针p*/
p = L->next; /*让p指向链表L的第一个结点*/
j = 1;  /*计数器*/
while(p && j<i) /*当p不为空或者j还没有大于等于i时，循环继续*/
    {
    p = p->next;  /*让p指向下一个结点*/
    ++j;
    }
if (!p || j>i)
    return ERROR; /*第i个元素不存在*/
*e = p->data;  /*取出第i个结点的数据*/
return OK;
}
//单链表插入
/*初始条件：顺序线性表L已存在，1≤i≤ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(LinkList *L,int i ,ElemType e)
{
int j;
LintList p,s; 
p = *L;
j = 1;
while (p && j<i) /*寻找第i个结点*/
    {
    p = p->next;
    ++j;
    }
if (!p || j >i)
    return ERROR;  /*第i个元素不存在*/

s = (LinkList)malloc(sizeof(Node)); /*生成新的结点*/
s->data = e;
s->next = p->next;  /*将p的后继结点赋值给s的后继*/
p->next = s;  /*将s赋值给p的后继*/
return OK;
}
//单链表删除
#define ERROR 0
#define OK 1
Status ListDelete(LinkList *L,int i ,ElemType *e)
{
int j;
LinkList p,q;
p = *L;
j = 1;
while(p->next && j <i)
    {
    p = p->next;
    ++j;
    }
if(!(p->next) || j>i)
    return ERROR;
q = p->next;
p->next = q->next;
*e = q->data;
free(q);
return OK;
}
//头插法
/*随机产生n个元素的值，建立带表头结点的单链线性表L（头插法）*/
void CreateListHead(LinkList *L, int n)
{
LinkList p;
int i;
srand(time(0));  /*当前时间种下随机数种子*/
*L = (LinkList)malloc(sizeof(Node));
(*L) ->next = NULL;  /*建立带头结点的链表*/
for (i=0,i<n,i++)
    {
    P = (LinkList)malloc(sizeof(Node));  /*生成新结点*/
    p->data = rand()%100+1;  /*随机生成100以内的数字*/
    p->next = (*L)->next;
    (*L)->next = p;  /*插入到表头*/
    }
}
//尾插法
/*随机产生n个元素的值，建立带表头结点的单链线性表（尾插法）*/
void CreateListTail(LinkList *L,int n)
｛
LinkList p,r;
int i;
srand(time(0)); 
*L = (LinkList)malloc(sizeof(Node)) 
r =*L    /*r为指向尾部的结点*/
for(i=0;i<n;i++)
    {
    p = (Node *)malloc(sizeof(Node))  /*生成新结点*/
    p->data = rand() %100 +1;
    r->next = p;   /*将表尾终端结点的指针指向新结点*/
    r = p;  /*将当前的新结点定义为表尾终端结点*/
    }
r->next = NULL;   /*表示当前链表结束*/
｝
//顺序栈定义
typedef struct
{
    int data[maxSize]
    int top;
}SqStack;
//链栈定义
typedef struct
{
    int data;
    struct LNode *next;
}LNode;
//顺序队列定义
typedef struct
{
    int data[maxSize];
    int front;
    int rear;
}
//链队节点定义
typedef struct
{
    int data;
    struct QNode *next;
}QNode;
//链队定义
typedef struct
{
    QNode *front;
    QNode *rear
}
//链栈初始化
void initStack(LNode* &lst)
{
    lst = (LNode*)malloc(sizeof(LNode));//头节点
    lst->next = NULL;
}
//链栈进栈操作
void push(LNode *lst,int x)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));//为进栈元素申请结点空间
    p->next = NULL;

    p->data = x;
    p->next = lst->next;
    lst->next = p;
}
//链栈出栈操作
int pop(LNode *lst,int &x)
{
    LNode *p;
    if(lst->next == NULL)
        return 0;
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    return 1;
}
//括号匹配
#include<string>
#include<stack>
#include<iostream>
using namespace std;
bool MatchBrackets(char* pStr)
{
    stack <char> s;//用来存放括号的栈
    int Len = strlen(pStr);
    for (int i = 0; i < Len; ++i)
    {
        if (pStr[i] == '{' || pStr[i] == '(' || pStr[i] == '[')
        {
            s.push(pStr[i]);
        }
        else if (pStr[i] == '}' || pStr[i] == ')' || pStr[i] == ']')
        {
            if (s.empty())
            {
                cout << "右括号多于左括号" << endl;
                return false;
            }
            else
            {
                if ((pStr[i] == ')'&&s.top() == '(') || (pStr[i] == '}'&&s.top() == '{')
                    || (pStr[i] == ']'&&s.top() == '['))
                {
                    s.pop();
                }
                else
                {
                    cout << "左右括号匹配错误" << endl;
                    return false;
                }
            }
        }

    }
    if (s.empty())
    {
        cout << "匹配成功！" << endl;

    }

    else
    {
        cout << "左括号多于右括号" << endl;
        return false;
    }
}       
int main()
{
    char ptr1[] = "{[]}}";
    char ptr2[] = "{[(]}";
    MatchBrackets(ptr1);
    MatchBrackets(ptr2);
    system("pause");
    return 0;
}
//逆波兰表达式
    char ch;
    int sz = strlen(pStr);
    for (int i = 0; i < sz; i++)
    {
        if (IsOperator(pStr[i]))//是否是操作符
        {
            ch = pStr[i];
            if (icp(ch)>isp(opra.top()))//栈外优先级大于栈内，ch入操作符栈
            {
                opra.push(ch);
            }
            else if (icp(ch) < isp(opra.top()))//栈外优先级小于栈内优先级，先将操作符栈栈顶
            {                                 //输入到后缀表达式num中并出操作符栈,
                num.push_back(opra.top());
                opra.pop();
                i--;  //此时栈外操作符还需进行下一次比较，所以要给它-1；否则就跳过该操作符了
            }
            else
            {
                if (opra.top() == '(')
                {
                    opra.pop();
                }
            }
        }
        else
            num.push_back(pStr[i]);//数字入栈
    }
    while (!opra.empty() && opra.top() != '#')//当字符串数组遍历结束后，依次将操作符栈的元素出
    {                                         //栈并输入到后缀表达式数组中
        num.push_back(opra.top());
        opra.pop();
    }
    for (size_t i = 0; i < num.size(); ++i)//后缀表达式打印
    {
        cout << num[i];
    }
    cout << endl;
//算符优先级算法
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
//初始化队列
void initQueue(SqQueue &qu)
{
    qu.front = qu.rear = 0;
}
//进队
int enQueue(sqQueue &qu,int x)
{
    if((qu.rear+1)%maxSize==qu.front)//队满判断条件
        return 0;
    qu.rear = (qu.rear+1)%maxSize;
    qu.data[qu.rear] = x;
    return 1;
}
//出队
int deQueue(SqQueue &qu,int &x)
{
    if(qu.front==qu.rear)//队空判断条件
        return 0;
    qu.front = (qu.front+1)%maxSize;
    x = qu.data[qu.front]
    return 1;
}
//串的定长顺序存储
typedef struct
{
    char str[maxSize+1];
    int length;
}Str
//简单模式匹配算法
int index(Str str,Str substr)
{
    int i=1,j=1,k=i;
    while(i<=str.length && j<=substr.length)
    {
        if(str.ch[i]==substr.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j=1;
            i=k++;
        }
    }
    if(j>substr.length)
        return k;
    else return 0;
}
//KMP求next值
int GetNext(char ch[],int cLen,int next[]){//cLen为串ch的长度
    next[1] = 0;
    int i = 1,j = 0;
    while(i<=cLen){
        if(j==0||ch[i]==ch[j]) next[++i] = ++j;
        else j = next[j];
    }
}
//二叉树链式存储结构
typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;
//先序遍历
void preorder(BTNode *p)
{
    if(p!=NULL)
    {
        visit(p);//包含对p的各种操作
        preorder(p->lchild)
        preorder(p->rchild)
    }
}
//邻接矩阵顶点
trpedef struct
{
    int no;//顶点编号
    char info;//顶点其他信息
}VertexType;
//图的定义
typedef struct
{
    int edges[maxSize][maxSize];
    int n,e;
    VertexType vex[maxSize];
}MGraph;
//邻接表顶点
typedef struct 
{
    int adjvex;
    struct ArcNode *firststarc;//指向下一条边的指针
    int info;//该边的相关信息
}ArcNode;
//边结点
typedef struct
{
    char data;
    ArcNode *firstarc;//指向第一条边的指针
}VNode;
typedef struct 
{
    VNode adjlist[maxSize];//邻接表
    int n,e;//顶点数和边数
}AGraph;
