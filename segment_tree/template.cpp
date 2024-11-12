#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> data;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            data[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INT_MAX;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node, start, mid, L, R);
        int right_query = query(2 * node + 1, mid + 1, end, L, R);
        return min(left_query, right_query);
    }

public:
    SegmentTree(const vector<int>& input_data) {
        data = input_data;
        n = data.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    cout << "Initial segment tree:" << endl;
    cout << "Minimum value in range [1, 4]: " << segTree.query(1, 4) << endl;

    segTree.update(3, 0);
    cout << "After updating index 3 to 0:" << endl;
    cout << "Minimum value in range [1, 4]: " << segTree.query(1, 4) << endl;

    return 0;
}