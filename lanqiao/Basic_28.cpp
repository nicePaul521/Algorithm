#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec;
	int n,tp,tmp;
	int sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tp;
		vec.push_back(tp);
	}
	while(vec.size()!=1)
	{
		sort(vec.begin(),vec.end());
		tmp = vec[0]+vec[1];
	//	cout<<tmp<<endl;
		vec.erase(vec.begin(),vec.begin()+2);
		sum+=tmp; 
		vec.push_back(tmp);
	}
	//cout<<endl;
	cout<<sum<<endl;
	return 0;
}
