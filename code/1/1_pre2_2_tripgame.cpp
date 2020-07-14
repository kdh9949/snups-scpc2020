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

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  const static int N = int(1e6) + 5;
  vector<int> d(N), e(N);
  for(int t = 0; t < c; t++) {
    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
      int nd =
        (i <= a) ? 0 :
        (i <= a * k) ? 1 :
        (e[i - a] - e[i - a * k - 1] < a * (k - 1) + 1);
      int ne =
        (i <= b) ? 0 :
        (i <= b * k) ? 1 :
        (d[i - b] - d[i - b * k - 1] < b * (k - 1) + 1);
      d[i] = d[i - 1] + nd;
      e[i] = e[i - 1] + ne;
    }

    cout << "ba"[d[n] - d[n - 1]];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << "\n";
    solve();
  }

  return 0;
}
