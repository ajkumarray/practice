#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> v(26);
        for(auto i : s){
            v[i-'a']++;
        }
        for(auto i : t){
            if(v[i-'a']==0){
                return false;
            }
            if(v[i-'a']--<=0){
                return false;
            }
        }
        return true;
    }
};