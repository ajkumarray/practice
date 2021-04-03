//  worldRecord
//  Created by Ajit Kumar on April03//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.
#include <iostream>
using namespace std;

double roundd(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}
void sol()
{
    int t;
    cin >> t;
    while(t--)
    {
        double k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;
        double time = 100/(k1*k2*k3*v);
        time = roundd(time);
        if(time >= 9.58)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);           //this method is used for fast I/O in C++
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}
