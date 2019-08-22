#include<iostream>
using namespace std;
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
    int n;
    while(cin>>n)
    {
        cout<<n<<" == ";
        transition(n);
        cout<<endl;
    }
    return 0;
}