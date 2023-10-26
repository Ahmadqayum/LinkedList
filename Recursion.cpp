#include<iostream>
using namespace std;

int fun(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else 
    {
        return num * fun(num - 1);
    }
}

int main()
{
    for(int i=1;i<=5;i++)
    {
        cout<<fun(5)<<endl;
    }
}