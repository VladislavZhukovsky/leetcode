#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target);

int main()
{
    vector<int> nums { 1,3,5,6 };
    int target = 0;
    cout << searchInsert(nums, target);
}

int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (nums[i] >= target)
        {
            return i;
        }
        if (nums[i] > target)
        {
            return i - 1;
        }
    }
    return i;
}