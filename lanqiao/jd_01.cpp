#include <iostream>
#include <vector>
#define Max 200
#include <cstring>
using namespace std;

/*
京东2020年校招笔试算法编程01：最优打字策略
题目描述：
在英文输入中，经常会遇到大小写切换问题，频繁切换大小写会增加我们按键次数，也降低打字效率，众所周知，
切换大小写有两种方式，一种按下‘caps locks’,也就是大写锁定，这样一来，之后的输入模式都会被切换。另一种是同时
按下shift和需要打印的字母，可以临时切换大小写（算作两个键），已知初始状态下，打字模式是小写，现在给出需要打
印的字符串，计算出需要最少按键多少次才能打印出。
输入：
第一行仅含一个正整数n，表示字符串长度1<=n<=1000000
第二行包含一个长度为n的字符串，仅包含大小写字母。
输出：
包含一个正整数，即最少的按键次数
实例：
<-6
<-AaAAAA
->8
*/

//返回大小写标志
bool isUpper(char x)
{
    return (x>='A'&&x<='Z');
}

int main()
{
    char s[Max];
    int len,i=0,flag=0,count=0;
    vector<int> ud;//定义了标志位变长数组
    vector<char> cap;//定义cap标志位变长数组
    cin>>len;
    cin>>s;
    while (strlen(s)!=len)//判断是否输入字符串长度等于预设长度
    {
        cout<<"the length of string is not match,pls input again!"<<endl;
        cin>>len;
        cin>>s;
    }      
    while (s[i]!='\0')//生成大小写标志位数组，大写-1，小写-0
    {
        ud.push_back(isUpper(s[i++]));
    }
    for(int j=0;j<ud.size();j++)//生成cap标志位数组，cap-c，no_cap-n
    {
        if((ud[j]==ud[j+1])&&ud[j]!=flag)//确定cap切换的位置，即下一个不同于上个cap大小写标志位且至少两个连续相同大小写标志位相同的位置
        {
            cap.push_back('c');
            flag = ud[j];//更新flag标志
            continue;
        }
        cap.push_back('n');
    }
    flag = 0;//重置
    for(int j=0;j<ud.size();j++)//根据两个变长数组统计计数
    {
        if(cap[j]=='c')//对于cap位，两次按键
        {
            flag=ud[j];
            count += 2;
            continue;
        }
        if(ud[j]!=flag)//两次cap位之间的，但不同于cap位flag的需要shift+字母两次按键
        {
            count += 2;
            continue;
        }
        count++;//两次cap位之间，同于上一个cap位flag位的一次按键
    }
    cout<<count<<endl;//打印计数
    return 0;
}