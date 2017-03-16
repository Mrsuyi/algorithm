class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        return partition(nums, 0, nums.size() - 1, k);
    }

    int partition(vector<int>& nums, int l, int r, int k)
    {
        int m = l + 1;
        int n = r;
        while (m <= n)
        {
            while (m <= n && nums[m] >= nums[l]) ++m;
            while (m <= n && nums[n] <= nums[l]) --n;
            if (m > n) break;
            std::swap(nums[m++], nums[n--]);
        }
        std::swap(nums[l], nums[n]);
        if (n - l + 1 == k)
            return nums[n];
        else if (n - l + 1 < k)
            return partition(nums, n + 1, r, k - (n - l + 1));
        else
            return partition(nums, l, n - 1, k);
    }
};