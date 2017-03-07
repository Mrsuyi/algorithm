class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        long long res = 1;
        for (int i = 0; i < A.size(); ++i)
        {
            unordered_set<int> record;
            for (int j = i + 1; j < A.size(); ++j)
                if (A[j] < A[i] && !record.count(A[j]))
                {
                    record.insert(A[j]);
                    std::swap(A[i], A[j]);
                    res += combine(A, i + 1, A.size() - 1);
                    std::swap(A[i], A[j]);
                }
        }
        return res;
    }

    long long combine(vector<int>& A, int l, int r)
    {
        unordered_map<int, int> counts;
        for (int i = l; i <= r; ++i)
            ++counts[A[i]];
        long long res = factorial(r - l + 1);
        for (auto& p : counts)
            res /= factorial(p.second);
        return res;
    }

    long long factorial(int n)
    {
        long long res = 1;
        for (int i = 1; i <= n; ++i)
            res *= i;
        return res;
    }
};