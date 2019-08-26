#include <iostream>
#include <string>
using namespace std;

bool isUpper(char x)
{
    return (x>='A'&&x<='Z');
}

int main()
{
    int len;
    char input[20];
    int count=0;
    cin>>len;
    cin>>input;
    //getline(cin,input);//将输入赋值到sr中，直到遇到回车才算是一次输入
    //cout<<input;
    int i=0;
    int flag=1;
    while(input[i]!='\0')
    {
        if(i!=0)
        {
            flag = isUpper(input[i-1])? 0:1;
        }
        if(isUpper(input[i])&&flag&&isUpper(input[i+1]))//小写-大写-大写，cap
        {
            int d = i==1? 0:isUpper(input[i-2]);
            if(d)
            {
                count += 1;
            }
            else
            {
                count = count + 2;
            }
            i += 1;
            continue;
        }
        if(isUpper(input[i])&&!flag)//大写-大写，不cap和shift
        {
            count = count + 1;
            i += 1;
            continue;
        }
        if(!isUpper(input[i])&&!flag&&!isUpper(input[i+1]))//大写-小写-小写，cap
        {
            int d = i==1? 0:isUpper(input[i-2]);
            if(!d)
            {
                count += 1;
            }
            else
            {
                count = count + 2;
            }
            i += 1;
            continue;
        }
        if(!isUpper(input[i])&&flag)//小写-小写，不cap和shift
        {
            count += 1;
            i += 1;
            continue;
        }
       count+=2;//小-大-小，大-小大，小-大-边界，大-小-边界，shift
       i = i+1;
    }
    cout<<count<<endl;
    return 0;
}