#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string i2s(int num)
{
    stringstream ss;
    string res;
    ss<<num;
    ss>>res;
    return res;
}
void transition(int n)
{
    char s[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(n>=16)
    {
        transition(n/16);
        cout<<s[n%16];
    }
    else
        cout<<s[n];
}
int main()
{
    vector<string> vec;
    vector<char> input;
    string str0[] = {"C","D","E","F"};
    int len,tmp;
    cout<<"pls input the length of the packet: "<<endl;
    string sr;
    getline(cin,sr);
    //cout<<sr<<endl;
    int j=0;
    while (sr[j]!='\0')
    {
        if(sr[j]!=' ')
        {
            input.push_back(sr[j]);
        }
        j++;
    }

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
        if(input[i]>'9')
        {
            vec.push_back(str0[input[i]-'C']);
            continue;
        }

        vec.push_back(i2s(input[i]-'0'));
    }   
    transition(vec.size());
    cout<<" ";
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}