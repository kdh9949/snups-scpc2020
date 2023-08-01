#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(x + i > n) ans++;
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