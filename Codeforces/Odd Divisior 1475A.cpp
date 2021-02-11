#include <iostream>
using namespace std;
// Codeforces problem: 1475A "Odd Divisior"
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    while(n--)
    {
        long long m;
        cin>>m;
        while(m!=1)
        {
            if(m%2==1)
            {
                cout<<"yes\n";
                break;
            }
            else
                m=m/2;
        }
        if(m==1)
            cout<<"no\n";
    }
    return 0;
}
