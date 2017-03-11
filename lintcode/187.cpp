class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int has = 0, need = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            if (has + gas[i] < cost[i])
            {
                need += cost[i] - has - gas[i];
                has = 0;
                start = i + 1;
            }
            else
            {
                has += gas[i] - cost[i];
            }
        }
        return (has >= need && start < gas.size()) ? start : -1;
    }
};