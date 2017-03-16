class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, unordered_set<int>> counts;
        unordered_map<int, int> candidates;
        int base = 0;

        for (int num : nums)
        {
            if (candidates.count(num))
            {
                int count = candidates[num]++;
                counts[count].erase(num);
                counts[count + 1].insert(num);
            }
            else if (candidates.size() < k)
            {
                int count = 1 - base;
                candidates[num] = count;
                counts[count].insert(num);
            }
            else
            {
                --base;
                for (int n : counts[-base])
                    candidates.erase(n);
                counts[-base].clear();
            }
        }

        unordered_map<int, int> total;
        for (int num : nums)
        {
            for (auto& p : candidates)
            {
                if (num == p.first)
                {
                    ++total[p.first];
                    break;
                }
            }
        }
        for (auto& p : total)
            if (p.second > nums.size() / k)
                return p.first;
        return 0;
    }
};