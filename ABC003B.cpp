#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
lint ncr(int n, int r){
  if(r<n/2.0) r = n-r;
  vector<int> div(n-r+1,1);
  FOR(i, 1, n-r+1) div[i]=i;
  lint result=1;
  IFOR(i, r+1, n+1){
    int tmp=i;
    IREP(j,n-r+1){
      if(div[j]!=1 && tmp%div[j]==0){
        tmp/=div[j];
        div[j]=1;
      }
    }
    result*=tmp;
  }
  return result;
}


int main()
{
  string s, t;
  cin >> s;
  cin >> t;
  string rep = "atcoder";
  string result;
  REP(i,t.size()){
    if(s[i]==t[i] || (s[i]=='@' && rep.find(t[i])!=-1) || (t[i]=='@' && rep.find(s[i])!=-1)){
      result = "You can win";
    }else{
      result = "You will lose";
      break;
    }
  }
  cout << result << endl;
  return 0;
}
