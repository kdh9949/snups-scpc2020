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

  vll a(n + 1), s(n + 1), t(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    t[i] = t[i - 1] + a[i] * a[i];
  }

  auto c = [&](int l, int r) {
    return (t[r] - t[l - 1]) - ld(s[r] - s[l - 1]) * (s[r] - s[l - 1]) / (r - l + 1);
  };

  stack<int> st;
  st.push(0);
  ld ans = 0;
  for(int i = 1; i <= n; i++) {
    while(st.top() > 0) {
      int t = st.top();
      st.pop();
      if((s[t] - s[st.top()]) * (i - t) < (s[i] - s[t]) * (t - st.top())) {
        st.push(t);
        break;
      }
      ans -= c(st.top() + 1, t);
    }
    ans += c(st.top() + 1, i);
    st.push(i);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(12);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }

  return 0;
}