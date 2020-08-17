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

const int N = 2000005;
vint d(N);

void solve() {
  int s, e;
  cin >> s >> e;

  int ans = 0;
  for(int i = s; i <= e; i++) ans = max(ans, d[i]);
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

  int c = 1;
  for(int i = 1; i <= 20; i++) {
    for(int j = 0; j < i + 1; j++) {
      printf("%3d ", d[c++]);
    }
    puts("");
  }

  c = 1;
  for(int i = 1; i <= 1500; i++) {
    int st = c;
    for(int j = 0; j < i + 1; j++, c++) {
      if(d[c] != d[st] + d[j]) {
        printf("counter : %d (%d + %d != %d)\n", c, d[st], d[j], d[c]);
      }
    }
  }

  /*
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }
  */

  return 0;
}