#include<bits/stdc++.h>

using i64 = long long;

void DAOQI() {
    i64 n, x1, x2;
    std::cin >> n >> x1 >> x2;
    std::vector<std::pair<i64, i64>> doc1, doc2;
    for (int i = 1; i <= n; i++) {
        i64 k, b;
        std::cin >> k >> b;
        i64 y1 = x1 * k + b, y2 = x2 * k + b;
        if (k >= 0) doc1.emplace_back(y1, y2);
        else doc2.emplace_back(y1, y2);
    }
    std::sort(doc1.begin(), doc1.end());
    std::sort(doc2.begin(), doc2.end(), [&](auto x, auto y) {
        return x.first > y.first;
    });
    std::vector<i64> pmx, pmn;
    for (auto [l, r]: doc1) {
        if (!pmx.empty() && pmx.back() > r) {
            std::cout << "YES\n";
            return;
        }
        if(pmx.empty()) pmx.push_back(r);
        else pmx.push_back(std::max(pmx.back(), r));
    }
    for (auto [l, r]: doc2) {
        if (!pmn.empty() && pmn.back() < r) {
            std::cout << "YES\n";
            return;
        }
        if(pmn.empty()) pmn.push_back(r);
        else pmn.push_back(std::min(pmn.back(), r));
        int p = std::lower_bound(doc1.begin(), doc1.end(), std::make_pair(l, -1ll)) - doc1.begin();
        p--;
        if (p >= 0) {
            if (pmx[p] > r) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    //std::cin >> T;
    while (T--) DAOQI();
    return 0;
}
