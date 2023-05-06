#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int m = nums1.size();
    int n = nums2.size();

    if (m == 0)
    {
        if (n == 1)
        {
            return nums2[0];
        }
        if (n % 2 != 0)
        {
            return nums2[n / 2];
        }
        else
        {
            int l = n / 2;
            return (double(nums2[l - 1] + nums2[l])) / 2;
        }
    }
    if (n == 0)
    {
        if (m == 1)
        {
            return nums1[0];
        }
        if (m % 2 != 0)
        {
            return nums1[m / 2];
        }
        else
        {
            int l = m / 2;
            return (double(nums1[l - 1] + nums1[l])) / 2;
        }
    }

    int nums3 [m + n];

    for (int h = 0; h < m + n; h++)
    {
        nums3[h] = 0;
    }

    int i = 0, j = 0, k = 0;
    while(i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            nums3[k] = nums1[i];
            i++;
        }  
        else if (nums1[i] > nums2[j])
        {
            nums3[k] = nums2[j];
            j++;
        }
        else
        {
            nums3[k] = nums1[i];
            k++;
            nums3[k] = nums2[j];
            i++;
            j++;
        }
        k++;
    }

    if (i == m && j == n)
    {
    }
    else if (i == m)
    {
        while(j < n)
        {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i < m)
        {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
    }

    if (k % 2 != 0)
    {
        return nums3[k / 2];
    }
    else
    {
        int l = k / 2;
        return (double(nums3[l - 1] + nums3[l])) / 2;
    }
}

int main()
{
    vector<int> a = {};
    vector<int> b = {1,2,3,4,5};
    cout << findMedianSortedArrays(b, a);
    return 0;
}