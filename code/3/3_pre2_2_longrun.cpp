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

  vll s(n), l(n), d(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i] >> l[i] >> d[i];
    s[i] %= l[i];
    d[i] = (l[i] - d[i]) % l[i];
  }

  function<pll(ll, ll)> extgcd = [&](ll a, ll b) {
    if(!b) return pll(1, 0);
    pll p = extgcd(b, a % b);
    return pll(p.y, p.x - a / b * p.y);
  };

  ll A = 0, N = 1;
  for(int i = 0; i < n; i++) {
    pll p = extgcd(s[i], l[i]);
    ll g = gcd(s[i], l[i]);
    ll M = l[i] / g;
    ll B = (d[i] / g * p.x % M + M) % M;

    p = extgcd(N, M);
    ll C = ((B - A) % M + M) % M;
    g = gcd(N, M);
    ll k = (C / g * p.x % M + M) % (M / g);
    A = (A + N * k) % (N * M / g);
    N *= M / g;
  }
  
  cout << (A == 0 ? N : A) << '\n';
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