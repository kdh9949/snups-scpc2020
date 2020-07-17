#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

vint ans(64);

void solve() {
  int k;
  cin >> k;
  cout << ans[k] << ' ' << (1UL << k) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt = 0;
  for(int i = 1; cnt < 64; i++) {
    int c = 0, x = i;
    while(x > 1) {
      if(x & 1) x = 3 * x + 1;
      else x /= 2;
      c++;
    }
    if(c <= 63 && !ans[c]) {
      ans[c] = i;
      cnt++;
    }
  }
  
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }

  return 0;
}