#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node
{
    Node* n0 = nullptr;
    Node* n1 = nullptr;
    int cnt = 0;
    int len, prefix;
    Node(int len, int prefix) : len(len), prefix(prefix) {}
    
    void insert(int num)
    {
        ++cnt;
        if (len != 32)
        {
            int mask = 1 << (31 - len);
            if (num & mask)
            {
                if (!n1)
                    n1 = new Node(len + 1, prefix | mask);
                n1->insert(num);
            }
            else
            {
                if (!n0)
                    n0 = new Node(len + 1, prefix);
                n0->insert(num);
            }
        }
    }
    
    long long result()
    {
        if (len == 32)
            return (long long)prefix * prefix * prefix;
        if (n1)
        {
            if (n1->cnt >= 2)
                return n1->result();
            if (n1->cnt == 1)
            {
                long long res = n0->calc(n1->get());
                if (n0->cnt > 1)
                    res = std::max(res, n0->result());
                return res;
            }
        }
        return n0->result();
    }
    
    long long get()
    {
        if (len == 32)
            return prefix;
        else
            return n0 ? n0->get() : n1->get();
    }
    
    long long calc(long long a)
    {
        if (len == 32)
            return (long long)a * prefix * (a & prefix);
        long long res = 0;
        if (n0) res = std::max(res, n0->calc(a));
        if (n1) res = std::max(res, n1->calc(a));
        return res;
    }
};

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        Node* root = new Node(0, 0);
        for (int j = 0; j < N; ++j)
        {
            int num;
            cin >> num;
            root->insert(num);
        }
        cout << root->result() << endl;
    }
    
    return 0;
}