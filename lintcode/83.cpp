class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        vector<int> counts(32, 0);
        for (int num : A)
        {
            for (int i = 0; i < 32; ++i)
                counts[i] = (counts[i] + ((num & (1 << i)) ? 1 : 0)) % 3;
        }
        int res = 0;
        for (int i = 0; i < 32; ++i)
            if (counts[i] == 1)
                res |= 1 << i;
        return res;
    }
};

// smarter
class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int c1 = 0, c2 = 0, c3 = 0;
        for (int num : A)
        {
            int a1 = c1 & num;
            int a2 = c2 & num;
            int a3 = c3 & num;
            num = num & ~a1 & ~a2 & ~a3;
            c3 = c3 & ~a3 | a2;
            c2 = c2 & ~a2 | a1;
            c1 = c1 & ~a1 | a3 | num;
        }
        return c1;
    }
};

// cool
public int singleNumber(int[] A) {
     int x1 = 0;   
     int x2 = 0; 
     int mask = 0;

     for (int i : A) {
        x2 ^= x1 & i;
        x1 ^= i;
        mask = ~(x1 & x2);
        x2 &= mask;
        x1 &= mask;
     }

     return x1;  // p = 1, in binary form p = '01', then p1 = 1, so we should return x1; 
                 // if p = 2, in binary form p = '10', then p2 = 1, so we should return x2.
}

// awesome
public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}