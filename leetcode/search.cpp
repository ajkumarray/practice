class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (binary_search(nums.begin(), nums.end(), target))
            return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        else
            return -1;
    }
};

/*
    All this functions work on a sorted container.
    Time Complexity :   O(logN) - where N is number of elements in container.
    
    binary_search(nums.begin(), nums.end(), target) :   returns boolean true if the element target is present in the container, else returns false.

    lower_bound(nums.begin(), nums.end(), target)   :   returns pointer to "position of target" if container contains 1 occurrence of target.
                                                        returns pointer to "first position of target" if container contains multiple occurrence of num.
                                                        returns pointer to "position of next higher number than target" if container does not contain occurrence of target.

                                                        subtracting the pointer of 1st position i.e. nums.begin() returns the actual index.

    upper_bound(nums.begin(), nums.end(), target)   :   returns pointer to "position of next higher number than num" if container contains 1 occurrence of target.
                                                        returns pointer to "first position of next higher number than last occurrence of target" if container contains multiple occurrence of target.
                                                        returns pointer to "position of next higher number than num" if container does not contain occurrence of num.

                                                        subtracting the pointer to 1st position i.e. nums.begin() returns the actual index.
*/