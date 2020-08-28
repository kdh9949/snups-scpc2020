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
  string s;
  cin >> n >> s;
  reverse(all(s));

  int st = 0, en = 1;
  for(char c : s) {
    c -= 'A';
    if(c < st) c += 3;
    if(en - st == 1) {
      if(c == st) en++;
      else if(c == en) st += 2;
      else { cout << "NO\n"; return; }
    }
    else {
      if(c == st + 1) swap(st, en);
    }
    st %= 3;
    en %= 3;
    if(st > en) en += 3;
  }

  cout << "YES\n";
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