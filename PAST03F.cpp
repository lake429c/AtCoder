#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
using pqueg = priority_queue<int, vector<int>, greater<int>>;
using pquel = priority_queue<int, vector<int>, less<int>>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
int lcm(int a, int b){
  return a / __gcd(a, b) * b;
}
int r_int(int a, int b){
  return rand() % b + a;
}
const lint mod=1e9+7;

int main()
{
  int n;
  cin >> n;
  vector<set<char>> a(n);
  REP(i,n){
    string tmp;
    cin >> tmp;
    REP(j,n) a[i].insert(tmp[j]);
  }

  string ans;
  REP(i,n/2){
    for(char x : a[i]){
      auto itr = find(ALL(a[n-1-i]), x);
      if(itr != a[n-1-i].end()){
        ans.push_back(x);
        break;
      }
    }
  }

  if(n == 1){
    cout << *a[0].begin() << "\n";
  }else if(ans.size() != n/2){
    cout << "-1\n";
  }else{
    string r_ans = ans;
    reverse(ALL(r_ans));
    if(n%2 == 1) ans.push_back(*a[n/2+1].begin());
    cout << ans << r_ans << "\n";
  }
  return 0;
}
