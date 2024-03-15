#include<stdio.h>
int setBits(int);
int main()
{

    int n,d;
    printf("Enter n:");
    scanf("%d",&n);

    d=setBits(n);
    printf("%d\n",d);

}
int setBits(intn)
{
    int c=0, n;
    while(n)
    {
        n= n & (n-1);
        c++;
    }
    return c;

}
