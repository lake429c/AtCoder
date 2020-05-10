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

int n, m;
lint x;
vector<vector<lint>> book;

lint price(int index, vector<lint> now, lint& min_price){
  //cout << min_price << "\n";
  // 全理解度がxを越えていれば現在の合計金額を返す
  if(*min(now.begin()+1, now.end()) >= x){
    if(now[0] < min_price) min_price = now[0];
    return min_price;
  }

  // 全理解度がxを越えないまま探索を終える場合min_priceを返す
  index++;
  if(index == n) return min_price;

  // 次の本を買う場合と買わない場合を比べて安い方の金額を返す
  vector<lint> next(m+1);
  REP(i,m+1) next[i] = now[i] + book[index][i];
  return min(price(index, now, min_price), price(index, next, min_price));
}


int main()
{
  cin >> n >> m >> x;
  book.assign(n, vector<lint>(m+1));
  REP(i,n) REP(j,m+1) cin >> book[i][j];

  // 全部買ってもxに届かないものがあれば-1を出力する
  lint min_price;
  REP(i,m+1){
    lint sum = 0;
    REP(j,n) sum += book[j][i];
    if(i == 0){
      min_price = sum;
      continue;
    }
    if(sum < x){
      cout << "-1\n";
      return 0;
    }
  }
  // 動的計画法（買うか買わないか）
  price(-1, vector<lint>(m+1, 0), min_price);

  cout << min_price << "\n";
  return 0;
}
