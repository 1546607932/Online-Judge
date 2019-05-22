//Chess Queen
#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,m;
    
    while(cin>>n>>m&&n&&m)
    {
        if(n>m)
        swap(n,m);
        unsigned long long ans=0;
        ans+=n*m*(m-1);
        ans+=m*n*(n-1);
        ans+=2*n*(n-1)*(3*m-n-1)/3;
        cout<<ans<<endl;
    }
    return 0;
}