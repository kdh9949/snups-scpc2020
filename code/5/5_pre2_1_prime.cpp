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

const int N = 30005;
vint d(N);

void solve() {
  int x, y;
  cin >> x >> y;
  cout << (d[x] > d[y] ? 1 : d[x] < d[y] ? 2 : 3) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vint p(N, 1);
  p[1] = 0;
  for(int i = 2; i < N; i++) {
    if(!p[i]) continue;
    for(int j = i * i; j < N; j += i) p[j] = 0;
  }

  for(int i = 2; i < N; i++){
    if(!p[i]) continue;
    for(int t = 1; t <= i; t *= 10) {
      int nxt = (i / (10 * t) * t) + (i % t);
      d[i] = max(d[i], d[nxt] + 1);
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