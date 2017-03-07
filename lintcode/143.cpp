class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        for (int i = 0; i < colors.size();)
        {
            if (colors[i] <= 0)
            {
                ++i;
            }
            else if (colors[i] == i + 1)
            {
                colors[i] = -1;
                ++i;
            }
            else
            {
                if (colors[colors[i] - 1] <= 0)
                {
                    --colors[colors[i] - 1];
                    colors[i] = 0;
                    ++i;
                }
                else
                {
                    int tmp = colors[colors[i] - 1];
                    colors[colors[i] - 1] = -1;
                    colors[i] = tmp;
                }
            }
        }
        for (int i = colors.size() - 1, j = i; j >= 0;)
        {
            if (colors[i] < 0)
            {
                ++colors[i];
                colors[j] = i + 1;
                --j;
            }
            else
                --i;
        }
    }
};