#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*华为2019年校招笔试题目
第一题：
题目描述：实现报文转义功能，如果报文中出现0x0A,转义为两个字节0x12和0x34，如果出现0x0B则转义为两个字节0xAB 0xCD，其他报文保持不变
输入描述：1.输入的报文为16进制，输入报文长度不超过127，输入报文的第一个字节为报文长度，第一个字节（报文长度）算作正式报文的一部分
         其他报文字节保持不变。
         2.输入的报文每个字节用空格隔开
输出描述：1.输出为转义后的报文，转义后的报文长度不超过255，输出报文的第一个字节算是正式报文的一部分，为转义后的报文长度。
         2.输出的报文内容都为大写的16进制，输出的报文为16进制，前不带0x前缀
         3.输出报文的每个字节用空格隔开
*/

//将整形转换为字符串类型
string i2s(int num)
{
    stringstream ss;
    string res;
    ss<<num;
    ss>>res;
    return res;
}
//定义了一个十进制转十六进制函数，将该数连续求余得到
void transition(int n)
{
    char s[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(n>=16)
    {
        transition(n/16);//进行递归剥离
        cout<<s[n%16];
    }
    else
        cout<<s[n];
}
int main()
{
    vector<string> vec;//定义变长数组，保存了转义后的字符串数组
    vector<char> input;//保存了输入字符串切分后的结果
    string str0[] = {"C","D","E","F"};
    int len,tmp;
    cout<<"pls input the length of the packet: "<<endl;
    string sr;//输入字符串
    getline(cin,sr);//将输入赋值到sr中，直到遇到回车才算是一次输入
    //cout<<sr<<endl;
    int j=0;
    //对字符串按照空格进行切分
    while (sr[j]!='\0')
    {
        if(sr[j]!=' ')
        {
            input.push_back(sr[j]);
        }
        j++;
    }
    //对输入进行遍历，并进行判断
    for(int i=1;i<input.size();i++)
    {
        if(input[i]=='A')
        {
            vec.push_back("12");
            vec.push_back("34");
            continue;
        }
        if(input[i]=='B')
        {
            vec.push_back("AB");
            vec.push_back("CD");
            continue;
        }
        if(input[i]>'9')//判断是否是A以上的16进制字符，若是就将对应字符存入
        {
            vec.push_back(str0[input[i]-'C']);
            continue;
        }
        //对于0-9的数字字符先将其转为整形再转为字符串
        vec.push_back(i2s(input[i]-'0'));
    }   
    transition(vec.size());//将转义后的长度转换为对应的16进制
    cout<<" ";
    for(int i=0;i<vec.size();i++)//打印输出输出报文
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}