#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, parent[200000];
vector <pair<int, pair<int, int>>> vec;

int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}
int main() {
	cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({ c, {a, b} });
        total += c;
    }
    sort(vec.begin(), vec.end());
    int ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        int cost = vec[i].first;
        int from = vec[i].second.first;
        int to = vec[i].second.second;
        if (findParent(from) != findParent(to)) {
            unionParent(from, to);
            ans += cost;
        }
    }
    cout << total - ans << '\n';

	return 0;
}