#include<stdio.h>

int cyclen(int num);

int main()
{
    int a,b,i,max=0,temp;

    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d %d ",a,b);

        if(a>b) //注意比较两数大小并交换数值 
            temp=a,a=b,b=temp;

        max=cyclen(a);

        for(i=a+1;i<=b;i++)
        {
            temp=cyclen(i);
            max=(temp>max?temp:max);
        }
        printf("%d\n",max);
        max=0;
    }
    return 0;
}

int cyclen(int num)
{
    int cnt=1;

    while(num!=1)
    {
        if(num%2==1) num=3*num+1;
        else num/=2;
        cnt++;
    }
    return cnt;
} 