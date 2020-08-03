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
  int n;
  cin >> n;

  int pv, sgn = -1, ans = 1;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(i) {
      if(pv == x) continue;
      int nsgn = (x > pv) - (x < pv);
      if(sgn != nsgn) {
        ans++;
        sgn = nsgn;
      }
    }
    pv = x;
  }

  cout << (ans / 2 * 2) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}