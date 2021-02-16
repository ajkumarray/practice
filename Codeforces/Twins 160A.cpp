//#include <iostream>               //Codeforces problem 160A : Twins
#include <bits/stdc++.h>            // <bits/stdc++.h> includes all the standard file, this might or might not be present in compiler...
#include <numeric>                  //describes sequence operations
using namespace std;
void sol(){
    int n,money_bro=0,money_me=0,coin_me=0;
    cin>>n;
    int ray[n];
    for(int i=0;i<n;i++)
        cin>>ray[i];
    sort(ray,ray+n);                //sorts the array/vector in ascending order | first parameter is the point of array from where sorting needs to begain and second parameter  is length upto which sorting has to be done
    money_bro=accumulate(ray,ray+n,money_bro);      //part of numeric library | takes 3 parameters, first and last elements of range whose elements are to be added and variable to store the sum
    for(int i=n-1;i>=0;i--)
    {
        if(money_me>(money_bro-money_me))
            break;
        else
        {
            money_me=money_me+ray[i];
            coin_me++;
        }
    }
    cout<<coin_me<<endl;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);           //this method is used for fast I/O in C++
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
