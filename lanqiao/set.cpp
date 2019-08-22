#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> myset;
    myset.insert(3);
    myset.insert(5);
    myset.insert(3);
    cout<<myset.size()<<endl;
    myset.erase(3);
    if(myset.find(3)==myset.end())
        cout<<"3 not found"<<endl;
    return 0;
}