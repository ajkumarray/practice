class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        std::rotate(nums.begin(), nums.begin() + n - k, nums.end());
        //right rotation
    }
};

/*
    rotate in cpp stl   :
    this function is defined in header <algorithm>. It rotates the order of the range[first, last], in such a way that the element pointed by middle becomes the new first element.

    void rotate(first, middle, last)
    first, last :    forward iterators to the initial and final positions of the sequence to be rotated
    middle  :   forward iterator pointing to the middle within the range[first, last] that is moved to the first position in the range.

            ----    Types of Rotations  ----

    Left Rotation   :   to rotate left, we need to add the vector index.
    e.g.    you have to rotate vector left 3 times. the 3rd index of vector becomes first element. ray.begin() + 3 will rotate vector 3 times left.
    rotL = 3;
    std::rotate(ray.begin(), ray.begin() + rotL, ray.end());
    old vector  :   1 2 3 4 5 6 7 8 9
    new vector after 3 left rotation    :   4 5 6 7 8 9 1 2 3

            ----                        ----

    Right Rotation  :   to rotate right, we need to subtract the vector index.
    e.g.    you have to rotate vector right 3 times. the 3rd last index of vector becomes first element. ray.begin() + ray.size() - 3 will rotate vector 3 times right.
    rotR = 4;
    std::rotate(ray.begin(), ray.begin() + ray.size() - rotR, ray.end());
    old vector  :   1 2 3 4 5 6 7 8 9
    new vector after 4 right rotation   :   6 7 8 9 1 2 3 4 5 
*/