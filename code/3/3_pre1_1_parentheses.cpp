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
  string s;
  cin >> s;

  int n = s.length();
  vector<int> chk(n);
  stack<int> st;

  static char mat[1 << 8];
  mat[')'] = '(';
  mat['}'] = '{';
  mat[']'] = '[';

  for(int i = 0; i < n; i++) {
    char c = s[i];
    if(c == '(' || c == '{' || c == '[') st.push(i);
    else {
      if(!st.empty() && mat[c] == s[st.top()]) {
        chk[st.top()] = chk[i] = 1;
        st.pop();
      } else {
        while(!st.empty()) st.pop();
      }
    }
  }

  for(int i = 1; i < n; i++) chk[i] *= (chk[i - 1] + 1);
  cout << *max_element(all(chk)) << '\n';
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