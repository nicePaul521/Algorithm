#include <iostream>
//#include <sstream>
#include <string>
#include <algorithm>
#define Max 10000
using namespace std;

int main()
{
	int A[Max] = {0};
	int B[Max] = {0};
	int C[Max] = {0};
	int tmp,k;
	int r = 0;
	int index = 0;
	string str1,str2;
	cin>>str1>>str2;
	for(int i=str1.length()-1;i>=0;i--)
		A[index++] = str1[i]-'0';
	index=0;
	for(int j=str2.length()-1;j>=0;j--)
		B[index++] = str2[j]-'0';
    int len = max(str1.length(),str2.length());
    for(int l=0;l<=len;l++)
    {
    	tmp = A[l]+B[l]+r;
    	//cout<<A[l]<<" "<<B[l]<<endl;
    	C[l] = tmp%10;
    	//cout<<C[l]<<endl;
    	r = tmp/10;
	}
	//cout<<C[0]<<C[1]<<C[2]<<endl;
	for(k=Max-1;k>0;k--)
	{
		if(C[k])
			break;
	}
	while(k>=0)
	{
		cout<<C[k--];
	}
	return 0;
}
