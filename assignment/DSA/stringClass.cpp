//  stringClass
/*
There are two ways of handling strings in C++. One is to use the native C-style strings and other is to use the string template class.
 */
//  Created by Ajit Kumar on February21//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //C-stle strings are defined using character array.
    char cStyleString[10];          //declaring string
    cin>>cStyleString;              //taking input
    cout<<cStyleString<<endl;       //printing string
    cout<<strlen(cStyleString)<<endl;       //finding length of the string
    
    //string class in C++ STL
    string classString;
    cin>>classString;
    cout<<classString<<" "<<classString.length()<<endl;
    
    return 0;
}
