#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int,string> mymap;
    mymap[0] = "zero";
    mymap[1] = "one";
    mymap[2] = "two";
    mymap[3] = "three";
    mymap[4] = "four";
    mymap[5] = "five";
    mymap[6] = "six";
    mymap[7] = "seven";
    mymap[8] = "eight";
    mymap[9] = "nine";
    mymap[10] = "ten";
    mymap[11] = "eleven";
    mymap[12] = "twelve";
    mymap[13] = "thirteen";
    mymap[14] = "fourteen";
    mymap[15] = "fifteen";
    mymap[16] = "sixteen";
    mymap[17] = "seventeen";
    mymap[18] = "eighteen";
    mymap[19] = "nineteen";
    mymap[20] = "twenty";
    mymap[30] = "thirty";
    mymap[40] = "forty";
    mymap[50] = "fifty";
    int h,m;
    cin>>h>>m;
    string res = "";
    h>20? res+=mymap[20]+" "+mymap[h-20]+" ":res+=mymap[h]+" ";
    if(m==0) res+="o'clock";
    else
    m>20? res+=mymap[m/10*10]+" "+mymap[m%10]:res+=mymap[m];
    cout<<res<<endl;
}