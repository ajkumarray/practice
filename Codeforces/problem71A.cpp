//  problem71A of Codeforces
//  Way Too Long Words
//  Created by Ajit Kumar on March25//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while(n--)
    {
        string word;
        cin >> word;
        if(word.length() > 10)
        {
            cout << word[0] << word.length()-2 << word[word.length()-1] << endl;
        }
        else
            cout << word << endl;
    }
    return 0;
}

