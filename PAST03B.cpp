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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> s(q);
  REP(i,q){
    int tmp, num;
    cin >> tmp >> num;
    num--;
    s[i].push_back(num);
    if(tmp == 2){
      int quest;
      cin >> quest;
      quest--;
      s[i].push_back(quest);
    }
  }

  vector<int> score(n, 0);
  vector<vector<int>> answered(m);
  REP(i,q){
    if(s[i].size() == 1){
      cout << score[s[i][0]] << "\n";
    }else{
      // その問題を解いた人にはその時点での得点を加える
      score[s[i][0]] += n-answered[s[i][1]].size()-1;
      // もう解いてる人からは，一人増えたので1点減点
      for(int x : answered[s[i][1]]) score[x]--;
      answered[s[i][1]].push_back(s[i][0]);
    }
  }
  return 0;
}
