#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAX_ST = 1 << 18;
struct MergeSortTree{
    vector<int> node[MAX_ST];
    void construct(){
        for (int i = MAX_ST / 2 - 1; i > 0; i--){
            vector<int> &current = node[i];
            vector<int> &left = node[i * 2];
            vector<int> &right = node[i * 2 + 1];
            node[i].resize(left.size() + right.size());
            for (int j = 0, l = 0, r = 0; j < current.size(); j++){
                if (r == right.size() || (l < left.size() && left[l] < right[r])) current[j] = left[l++];
                else current[j] = right[r++]; 
            }
        }
    }
    int greater(int s, int e, int k, int idx = 1, int ns = 0, int ne = MAX_ST / 2){
        if (ne <= s || e <= ns) return 0;
        if (s <= ns && ne <= e) return node[idx].end() - upper_bound(node[idx].begin(), node[idx].end(), k);
        int mid = (ns + ne) / 2;
        return greater(s, e, k, idx * 2, ns, mid) + greater(s, e, k, idx * 2 + 1, mid, ne);
    }
    void pushLeaf(int i, int val){
        node[MAX_ST / 2 + i].push_back(val);
    }
};