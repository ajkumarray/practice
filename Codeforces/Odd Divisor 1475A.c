#include<stdio.h>
int main()        //Codeforces problem 1475A "Odd Divisor".    this solution exceeded time limit...   check cpp solution
{
    int i,n,j,f;
    int long m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&m);
        f=0;j=3;
        if(m==2)
            f=0;
        while(j<=m)
        {
            if(m%j==0)
                f=1;
            j=j+2;
        }
        if(f==1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
