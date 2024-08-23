#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    vector<long long> pref = {0};
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
        pref.push_back(pref.back() + e);
    }

    const vector<int> ID(26);

    long long ans = 0;
    int last = -1;
    int cnt = 0;

    vector<long long> can;

    for (int i = 0; i < n; ) {
        if(s[i] == t[i]) {
            i++;
            continue;
        }

        int j = i+1;
        vector<int> cur(26);
        cur[s[i]-'a']++; cur[t[i]-'a']--;

        while(j < n && cur != ID) {
            cur[s[j]-'a']++;
            cur[t[j]-'a']--;
            j++;
        }

        ans += pref[j] - pref[i];
        ++cnt;

        if(~last) {
            can.push_back(pref[i] - pref[last+1]);
        }

        last = j-1;

        i = j;
    }

    sort(can.begin(), can.end());
    for (int i = 0; i < cnt - k; i++) {
        ans += can[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    for(int i = 1; i <= tt; i++) {
        // cout << "Case " << i << "#: ";
        solve();
    }

    return 0;
}