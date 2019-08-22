#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string,int> mymap;
    mymap["c++"] = 100;
    mymap["c++"]++;
    cout<<mymap["c++"]<<endl;
    return 0;
}
