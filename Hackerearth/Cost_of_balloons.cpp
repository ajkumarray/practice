#include <iostream>
using namespace std;
// Hackerearth problem: Cost of balloons
int main() {
    int testcase;           //no of testcases
    cin>>testcase;
    while(testcase--) {
        int b1cost, b2cost, n, count1=0, count2=0, value1, value2, mincost, maxcost, mincount, maxcount;
        cin>>b1cost>>b2cost;    //cost of green and purple colored balloons
        cin>>n;                 //no of participants
        for(int i=0;i<n;i++) {
            cin>>value1>>value2;    //status of participants
            if(value1==1)
            count1++;
            if(value2==1)
            count2++;
        }
        if(count1<count2) {
            maxcount=count2;
            mincount=count1;
        }
        else {
            maxcount=count1;
            mincount=count2;
        }
        if(b1cost<b2cost) {
            mincost=b1cost;
            maxcost=b2cost;
        }
        else {
            mincost=b2cost;
            maxcost=b1cost;
        }
        cout<<(mincost*maxcount+maxcost*mincount)<<endl;    //min cost
    }
    return 0;
}
