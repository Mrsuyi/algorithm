class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if (nums.size() == 0) return;

        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int mid = nums[nums.size() / 2];

        auto vidx = [&](int i){ return (2 * i + 1) % (nums.size() | 1); };

        for (int il = 0, i = 0, ir = nums.size() - 1; i <= ir;)
        {
            if (nums[vidx(i)] > mid)
                std::swap(nums[vidx(il++)], nums[vidx(i++)]);
            else if (nums[vidx(i)] < mid)
                std::swap(nums[vidx(i)], nums[vidx(ir--)]);
            else
                ++i;
        }
    }
};