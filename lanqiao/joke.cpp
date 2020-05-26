#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
        string substr = "";
        int len = 0;        
        for(int i=0;i<s.length();i++)
        {
            if(substr.find(s[i])==-1){
                substr += s[i];
                cout<<substr<<endl;
                continue;
            }
            if(substr.length()>len) len = substr.length();
            substr.clear();
            substr += s[i];
        }
        if(substr.length()>len) len = substr.length();
        return len;
    }
int main(){
    string str = "dvdf";
    int num = lengthOfLongestSubstring(str);
    cout<<num<<endl;
}