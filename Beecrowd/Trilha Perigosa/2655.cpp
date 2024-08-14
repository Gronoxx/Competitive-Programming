#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_M = 50;

struct SegmentTree {
    vector<bitset<MAX_M>> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void build(vector<int>& arr, int node, int low, int high) {
        if (low == high) {
            tree[node].set(arr[low]);
        } else {
            int mid = (low + high) / 2;
            build(arr, 2 * node + 1, low, mid);
            build(arr, 2 * node + 2, mid + 1, high);
            merge(node);
        }
    }

    void merge(int node) {
        tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
    }

    void update(int node, int low, int high, int idx, int oldvalue, int newvalue) {
        if (low == high) {
            tree[node].reset(oldvalue);
            tree[node].set(newvalue);
        } else {
            int mid = (low + high) / 2;
            if (low <= idx && idx <= mid) {
                update(2 * node + 1, low, mid, idx, oldvalue, newvalue);
            } else {
                update(2 * node + 2, mid + 1, high, idx, oldvalue, newvalue);
            }
            merge(node);
        }
    }

    bitset<MAX_M> query(int node, int low, int high, int L, int R) {
        if (R < low || high < L) {
            return bitset<MAX_M>(); // Retorna bitset vazio
        }
        if (L <= low && high <= R) {
            return tree[node];
        }
        int mid = (low + high) / 2;
        bitset<MAX_M> left = query(2 * node + 1, low, mid, L, R);
        bitset<MAX_M> right = query(2 * node + 2, mid + 1, high, L, R);
        return left | right;
    }
};

int main() {
    int N, Q, M;
    cin >> N >> Q >> M;
    vector<int> input(N);
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
        --input[i];
    }

    SegmentTree segTree(N);
    segTree.build(input, 0, 0, N - 1);

    for (int i = 0; i < Q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int L, R;
            cin >> L >> R;
            --L; --R; 
            bitset<MAX_M> result = segTree.query(0, 0, N - 1, L, R);
            cout << result.count() << endl;
        } else {
            int C, T;
            cin >> C >> T;
            --C; --T; 
            int oldvalue = input[C];
            input[C] = T;
            segTree.update(0, 0, N - 1, C, oldvalue, T);
        }
    }

    return 0;
}
