#include <iostream>
const int MAXN = 1000;
int p[MAXN];

// ultra fast implementation with O(log n)

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
    for (int i = 0; i < MAXN; ++i) {
        p[i] = i;
    }
    std::cout << find(2) << "\n";
    unite(2, 3);
    std::cout << find(2) << " " << find(3) << "\n";

    return 0;

}