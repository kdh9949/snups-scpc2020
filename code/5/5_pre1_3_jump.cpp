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

const int N = 450005;
vint d(N);

void solve() {
  ll s, e;
  cin >> s >> e;

  ll bnd = max(s, e - N);

  int st = 1;
  ll sum = 1;
  while(sum <= e) sum += ++st;
  sum -= st--;

  int ans = 0;
  for(ll i = e; i >= bnd; i--) {
    if(i < N) ans = max(ans, d[i]);
    else {
      while(sum > i) sum -= st--;
      ans = max(ans, st + d[i - sum]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(all(d), N);
  d[0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 1, k = 1; i + k < N; k += ++j) {
      d[i + k] = min(d[i + k], d[i] + j);
    }
  }

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}