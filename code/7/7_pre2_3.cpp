#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 605, O = 1210;
ll a[5 * N][5 * N], us[5 * N][5 * N], lus[5 * N][5 * N], rus[5 * N][5 * N];

void solve() {
  int n, k;
  cin >> n >> k;
  ll mx = 0;
  for(int i = O; i < O + n; i++) for(int j = O; j < O + n; j++) { cin >> a[i][j]; mx = max(mx, a[i][j]); }
  if(k == 1) { cout << mx << '\n'; return; }
  for(int i = O; i < O + N; i++) for(int j = O; j < 5 * N; j++) us[j][i] = us[j - 1][i] + a[j][i];
  for(int i = O; i < 5 * N; i++) for(int j = O; j < 5 * N; j++) lus[i][j] = lus[i - 1][j - 1] + a[i][j];
  for(int i = O; i < 5 * N; i++) for(int j = O + N; j >= 0; j--) rus[i][j] = rus[i - 1][j + 1] + a[i][j];
  ll ans = 0;
  for(int i = N; i <= O + N + n; i++) {
    ll cur = 0, ld = 0, rd = 0;
    for(int j = N; j <= O + N + n; j++) {
      ans = max(ans, cur);
      cur += rd - ld;
      ld += (us[i + k - 1][j + 1] - us[i - k][j + 1]) - (lus[i + k - 1][j] - lus[i][j - k + 1]) - (rus[i][j - k + 1] - rus[i - k][j + 1]);
      rd += -(us[i + k - 1][j + 1] - us[i - k][j + 1]) + (rus[i + k - 1][j + 2] - rus[i][j + k + 1]) + (lus[i][j + k + 1] - lus[i - k][j + 1]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    cout << "Case #" << i << '\n';
    solve();
  }
    
  return 0;
}