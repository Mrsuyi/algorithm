class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        vector<int> req(128, 0);
        int total = 0;
        for (char c : target)
            total += req[c]++ == 0;

        for (int l = -1, r = 0; r < source.size(); ++r)
        {
            if (--req[source[r]] == 0)
            {
                if (--total == 0)
                    return source.substr(l + 1, r - l);
            }
            while (l < r && req[source[l + 1]] < 0) ++req[source[l++ + 1]];
        }
        return "";
    }
};
