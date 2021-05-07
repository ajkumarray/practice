//  removeDuplicatesFromSortedArray leetcode problem
//  Created by Ajit Kumar on April10//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        auto i = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), i));
        return (int)nums.size();
    }
};

/*
 std::unique is used to remove duplicates of any element present consecutivey in a range [first, last].
 
 It does not delete all the duplicate elements, but it removes duplicacy by just replacing those elements
 by the next element present in the sequence which is not duplicate to the current element being replaced.
 All the elements which are replaced are left in an unspecified state.
 
 This function does not change the size of the container after deleting the elements,
 it just returns a ponter pointing to the new end of the container, and based upon that we can resize the container, or remove the garbage elements.
 */

/*
 std::distance
 If we have two iterators and we want to find the total number of elements between the two iterators.
 
 std::distance has direction associated with it just as vectors in science.
 */
