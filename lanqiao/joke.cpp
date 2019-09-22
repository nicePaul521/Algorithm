#include <iostream>
using namespace std;
#include <vector>

void reverseString(vector<char>& s) {

    if(s.empty())
        return;
    cout<<s.back();
    s.pop_back();
    reverseString(s);
    return;
    }

int main()
{
    char a[7] = {'a','B','c','D','E','F','g'};
    vector<char> b(a,a+7);
    reverseString(b);
}