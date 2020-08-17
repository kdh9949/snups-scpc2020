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

const int N = 1000005;
vll sum(N);

void solve() {
  int s, e;
  cin >> s >> e;
  cout << (sum[e] - sum[s - 1]) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sum[1] = 0;
  sum[2] = 1;
  for(int i = 3; i + 1 < N; i += 2) {
    sum[i + 1] = sum[(i + 1) / 2] + 1;
    sum[i] = sum[i + 1] + 1;
  }
  for(int i = 1; i < N; i++) sum[i] += sum[i - 1];

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}