//#include <iostream>               //Codeforces problem 1487B Cat Cycle
#include <bits/stdc++.h>            //exceeded time limit on test 3
using namespace std;
int sol()
{
    int t;
    cin >> t;
    while(t-->0)
    {
        int n,hour;
        cin>>n>>hour;
        int posA=n,posB=1;
        while(hour-- > 1)
        {
            if(posB<n)
                posB++;
            else
                posB=1;
            if(posA == 1)
                posA=n;
            else
                posA--;
            if(posA == posB)
            {
                if(posB<n)
                    posB++;
                else
                    posB=1;
            }
        }
        cout<<posB<<endl;
    }
    return 0;
}
int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);           //this method is used for fast I/O in C++
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
