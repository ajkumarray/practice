#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main()
{
    vector<int> ray;
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    cout << "Enter elements: ";
    for (int i = 0; i < num; i++)
    {
        int n;
        cin >> n;
        ray.push_back(n);
    }
    int val;
    cout << "Enter value to remove: ";
    cin >> val;
    Solution solution;
    int n = solution.removeElement(ray, val);

    for (int i = 0; i < n; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl;
    return 0;
}
