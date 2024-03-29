class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

/*
    isBadVersion(version)   :   predefined
*/