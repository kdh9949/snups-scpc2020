#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
  int n, t;
  string s;
  cin >> n >> t >> s;
  
  string ans(n, '0');
  for(int i = 0; i < 2 * t; i++) {
    for(int j = i; j < n; j += 2 * t) {
      if(s[j] == '1') {
        if(j - t < 0) { ans[j + t] = '1'; j += 2 * t; }
        else if(j + t >= n || (j + 2 * t < n && s[j + 2 * t] == '0')) { ans[j - t] = '1'; }
        else { ans[j + t] = '1'; j += 2 * t; }
      }    
    }
  }
  
  cout << ans << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  for(int ctc = 1; ctc <= tc; ctc++) {
    cout << "Case #" << ctc << "\n";
    solve();
  }
  
  return 0;
}