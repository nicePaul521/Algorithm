#include <iostream>
//#include <vector>
#define Max 100000
  
using namespace std;

int main()
{
	int res[Max] = {0};
	int jin[Max] = {0};
	int n,tmp,c=0;
	int k=1;
	cin>>n;
	res[0] = 1;
	res[1] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<Max;j++)
		{
			tmp = res[j]*i+c;
			res[j] = tmp%10;
			c = tmp/10;
		}
	}
	for(k=Max-1;k>0;k--)
	{
		if(res[k])
			break;
	}
	while(k)
	{
		cout<<res[k--];
	}
    return 0;
} 
