#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, l = m + n - 1;
        while (i >= 0 || j >= 0)
        {
            if (i >= 0 && j >= 0)
            {
                nums1[l--] = (nums1[i] <= nums2[j]) ? nums2[j--] : nums1[i--];
            }
            else if (i >= 0 && j < 0)
            {
                nums1[l--] = nums1[i--];
            }
            else
            {
                nums1[l--] = nums2[j--];
            }
        }
        return;
    }
};

int main()
{
    int m, n;
    cout << "Enter number of elements in both arrays: ";
    cin >> m >> n;
    vector<int> nums1(m + n, 0);
    vector<int> nums2;
    cout << "Enter elements of nums1: ";
    //for (auto i = nums1.begin(); i != nums1.begin() + m; i++)
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        //*i = num;
        nums1[i] = num;
    }
    cout << "Elements of nums1 are: ";
    for (auto it = nums1.begin(); it != nums1.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Enter elements of nums2: ";
    for (auto i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums2.push_back(num);
    }
    cout << "Elements of nums2 are: ";
    for (auto it = nums2.begin(); it != nums2.end(); it++)
        cout << *it << " ";
    cout << endl;

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    cout << "Elements of final nums1 are: ";
    for (auto it = nums1.begin(); it != nums1.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}