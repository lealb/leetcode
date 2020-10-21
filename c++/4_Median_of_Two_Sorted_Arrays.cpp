#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int start = 0;
        int end = m;
        while (start <= end)
        {
            int i = start + (end - start) / 2;
            int j = (m + n + 1) / 2 - i;
            int min1 = (i == m) ? INT_MAX : nums1[i];
            int min2 = (j == n) ? INT_MAX : nums2[j];
            int max1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int max2 = (j == 0) ? INT_MIN : nums2[j - 1];
            if (max1 <= min2 && max2 <= min1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (double)(max(max1, max2) + min(min1, min2)) / 2;
                }
                else
                    return (double)max(max1, max2);
            }
            else if (max1 > min2)
                end = i - 1;
            else
                start = i + 1;
        }
        return -1;
    }

    double findMedianSortedArrays_1(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1 + n2;
        int k = n % 2 == 0 ? n / 2 : n / 2 + 1;

        int lo = 0, hi = k;
        int mid = lo + (hi - lo) / 2;
        while (lo != hi)
        {
            int i, j;
            //cout << "Trying hi,lo,mid = " << hi << " " << lo << " " << mid << endl;
            if (mid > n1)
                i = n1 - 1, j = k - n1 - 1;
            else if (k - mid > n2)
                j = n2 - 1, i = k - n2 - 1;
            else
                i = mid - 1, j = k - mid - 1;

            //cout << "Trying i,j = " << i << " " << j << endl;
            if (i == -1)
            {
                // We're done
                if (nums1.empty() || nums1[0] >= nums2[j])
                    break;
                else
                    // Take less of nums2
                    lo = mid + 1, mid = lo + (hi - lo) / 2;
            }
            else if (j == -1)
            {
                // We're done
                if (nums2.empty() || nums2[0] >= nums1[i])
                    break;
                else
                    // Take less of nums1
                    hi = mid - 1, mid = lo + (hi - lo) / 2;
            }
            // Which array has largest end?
            else if (nums1[i] > nums2[j])
            {
                // We're done
                if (j == n2 - 1 || nums2[j + 1] >= nums1[i])
                    break;
                else
                    // Take less of nums1
                    hi = mid - 1, mid = lo + (hi - lo) / 2;
            }
            else
            {
                // We're done
                if (i == n1 - 1 || nums1[i + 1] >= nums2[j])
                    break;
                else
                    // Take less of nums2
                    lo = mid + 1, mid = lo + (hi - lo) / 2;
            }
        }
        //cout << "Found mid = " << mid << endl;
        {
            int i, j;
            if (mid > n1)
                i = n1 - 1, j = k - n1 - 1;
            else if (k - mid > n2)
                j = n2 - 1, i = k - n2 - 1;
            else
                i = mid - 1, j = k - mid - 1;

            //cout << "Found i,j = " << i << " " << j << endl;

            double median1 = max(i == -1 ? -1 : nums1[i], j == -1 ? -1 : nums2[j]);

            if (n % 2)
                return median1;

            // One extra step
            double result = 0.5 * median1;

            //cout << "Extra step i,j = " << i << " " << j << endl;
            int lastEl2;
            // One more if necessary

            if (j == n2 - 1)
                result += 0.5 * nums1[i + 1];
            else if (i == n1 - 1)
                result += 0.5 * nums2[j + 1];
            else if (nums1[i + 1] <= nums2[j + 1])
                result += 0.5 * nums1[i + 1];
            else
                result += 0.5 * nums2[j + 1];

            return result;
        }
        return 0;
    }

    double findMedianSortedArraysSlow(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int k;
        if (n % 2 == 0)
            k = n / 2;
        else
            k = n / 2 + 1;

        int i = 0, j = 0;
        int lastEl = 0;
        for (int t = 0; t < k; t++)
        {
            if ((j == n2) || (i < n1 && nums1[i] <= nums2[j]))
                lastEl = nums1[i++];
            else
                lastEl = nums2[j++];
        }
        if (n % 2 == 1)
            return lastEl;

        //cout << i << " " << j << " " << k << endl;

        int lastEl2;
        // One more if necessary
        if ((j == n2) || (i < n1 && nums1[i] <= nums2[j]))
            lastEl2 = nums1[i++];
        else
            lastEl2 = nums2[j++];
        //cout << i << " " << j << " " << lastEl2 << endl;
        return 0.5 * (lastEl + lastEl2);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> num1 = {1, 2};
    vector<int> num2 = {3, 4};
    cout << solution.findMedianSortedArrays_1(num1, num2) << endl;
    system("pause");
    return 0;
}
