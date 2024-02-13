#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<int> sizes;

void build_ds(int size) {
    parents.resize(size);
    sizes.resize(size);
    for (int i = 0; i < size; ++i) {
        parents[i] = i;
        sizes[i] = -1;
    }
}
// O(log n / log log n)
int find(int x) {
    return parents[x] == x ? x : (parents[x] = find(parents[x]));
}

void unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);

    if (sizes[x_root] < sizes[y_root]) {
        return unite(y_root, x_root);
    }
    parents[y_root] = x_root;
    sizes[x_root] += sizes[y_root];
}