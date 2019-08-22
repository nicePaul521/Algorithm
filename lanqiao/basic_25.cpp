#include <iostream>
#include <vector>
//#define Max 1000

using namespace std;

int main()
{
    int array[10][10]={0};
    int check[10][10]={0};
    int row,col,pr,pc;
    int r=0;
    int c=0;
    int direction=1;
    vector<int> res;
    cout<<"hello"<<endl;
    cin>>row>>col;
    for(int i=0;i<row;i++)
        for(int j=0;j<row;j++)
            cin>>array[i][j];  
    res.push_back(array[0][0]);
    for(int k=0;k<(row*col)-1;k++)
    {
        pr=r;
        pc=c;
        switch (direction)
        {
            case 1:r++;break;
            case 2:c++;break;
            case 3:r--;break;
            case 4:c--;break;
            default:
                break;
        }
        if(check[r][c])
        {
            direction==4? direction=1:direction++;
            r = pr;
            c = pc;
        }
        else if (((direction==1)&&(r==row))||((direction==2)&&(c==col))||((direction==3)&&(row==0)))
        {
            direction==4? direction=1:direction++;
            res.push_back(array[r][c]);
            check[r][c] = 1;
        }       
        else
        {
            res.push_back(array[r][c]);
            check[r][c] = 1;
        } 
    }
    for(int i=0;i<res.size();i++)
        cout<<res[i];
    return 0;
}