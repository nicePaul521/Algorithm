#include <iostream>
#include <String>
using namespace std;

class Solution {
public: 
bool isPalindrome(long x) {
        if(x<0)
            return false;
        long rem=0,y=0;
        long quo=x;
        while(quo!=0){
            rem=quo%10;
            y=y*10+rem;
            quo=quo/10;
        }
        return y==x;
    }
};

int main()
{
    long x = 12321;
    //cin>>x;
    Solution* sol = new Solution();
    bool res = sol->isPalindrome(x); 
    String s = res?"True":"False"
    cout<<s<<endl;
    return 0;   
}