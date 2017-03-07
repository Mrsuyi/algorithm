/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        sort(nuts, bolts, 0, nuts.size() - 1, compare);
    }

    void sort(vector<string>& a, vector<string>& b, int l, int r, Comparator cmp)
    {
        if (l >= r) return;
        int count = 0, equal;
        for (int i = l; i <= r; ++i)
        {
            int res = cmp.cmp(a[l], b[i]);
            if (res == 0)
                equal = i;
            else if (res == 1)
                ++count;
        }
        int pivot = l + count;
        std::swap(a[l], a[pivot]);
        std::swap(b[equal], b[pivot]);
        for (int i = l, j = r; i < pivot && j > pivot;)
        {
            while (i < pivot && cmp.cmp(a[i], b[pivot]) == -1) ++i;
            while (j > pivot && cmp.cmp(a[j], b[pivot]) == 1) --j;
            if (i < j) std::swap(a[i++], a[j--]);
        }
        for (int i = l, j = r; i < pivot && j > pivot;)
        {
            while (i < pivot && cmp.cmp(a[pivot], b[i]) == 1) ++i;
            while (j > pivot && cmp.cmp(a[pivot], b[j]) == -1) --j;
            if (i < j) std::swap(b[i++], b[j--]);
        }
        sort(a, b, l, pivot - 1, cmp);
        sort(a, b, pivot + 1, r, cmp);
    }
};