class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        
        int alen = A.size();
        int blen = B.size();
        int al = 0, ar = alen * 2, ai = alen;
        int bl = 0, br = blen * 2, bi = blen;

        auto idxl = [](const int i)
        {
            return (i - ((i & 1) ? 0 : 1)) / 2;
        };
        auto idxr = [](const int i)
        {
            return (i + ((i & 1) ? 0 : 1)) / 2;
        };

        while (ai > al && ai < ar && bi > bl && bi < br)
        {
            int nal = A[idxl(ai)];
            int nar = A[idxr(ai)];
            int nbl = B[idxl(bi)];
            int nbr = B[idxr(bi)];

            if (nal <= nbr && nbl <= nar) break;

            // ai >>   bi <<
            if (nar < nbl)
            {
                int ai2r = (ar - ai + 1) / 2;
                int bi2l = (bi - bl + 1) / 2;
                int step = std::min(ai2r, bi2l);
                al = ai;
                ai += step;
                br = bi;
                bi -= step;
            }
            // ai << bi >>
            else
            {
                int ai2l = (ai - al + 1) / 2;
                int bi2r = (br - bi + 1) / 2;
                int step = std::min(ai2l, bi2r);
                ar = ai;
                ai -= step;
                bl = bi;
                bi += step;
            }
        }
        int nal = ai == 0 ? INT_MIN : A[idxl(ai)];
        int nar = ai == 2 * alen ? INT_MAX : A[idxr(ai)];
        int nbl = bi == 0 ? INT_MIN : B[idxl(bi)];
        int nbr = bi == 2 * blen ? INT_MAX : B[idxr(bi)];

        return (std::max(nal, nbl) + std::min(nar, nbr)) / 2.0;
    }
};


class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        
        int la = A.size(), lb = B.size();
        return (kth(&A[0], la, &B[0], lb, (la + lb + 1) / 2) +
                kth(&A[0], la, &B[0], lb, (la + lb + 2) / 2)) / 2.0;
    }

    int kth(const int* a, int la, const int* b, int lb, int k)
    {
        if (la > lb)
            return kth(b, lb, a, la, k);
        if (la == 0)
            return b[k - 1];
        if (k == 1)
            return std::min(a[0], b[0]);
        
        int i = std::min(la, k / 2);
        int j = std::min(lb, k / 2);
        if (a[i - 1] > b[j - 1])
            return kth(a, la, b + j, lb - j, k - j);
        else
            return kth(a + i, la - i, b, lb, k - i);
    }
};
