#include<stdio.h>
int main()
{
    int n,i,j;
    char ch='A';
    printf("Enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        ch='A';
    for(j=1;j<=i;j++)
    {
        printf("%c",ch);
        ch++;
    }
    printf("\n");
}
}
