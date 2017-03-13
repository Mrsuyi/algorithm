class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        return find(num, 0, num.size() - 1);
    }

    int find(vector<int>& num, int l, int r)
    {
        if (l > r) return INT_MAX;
        int mid = l + (r - l) / 2;
        if (num[l] <= num[mid])
            return std::min(num[l], find(num, mid + 1, r));
        else
            return std::min(num[mid], find(num, l, mid - 1));
    }
};