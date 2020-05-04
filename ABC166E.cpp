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
  lint n;
  cin >> n;
  map<lint, vector<lint>> tall;
  REP(i,n){
    lint tmp;
    cin >> tmp;
    //tall.try_emplace(vector<lint>(0));
    tall[tmp].push_back(i+1);
  }

  lint min = tall.begin()->first;
  lint cnt = 0;
  auto a = tall.begin(), b = tall.begin();
  while(a != tall.end()){
    if(a != b){
      REP(i,a->second.size()){
        REP(j,b->second.size()){
          if(abs(a->second[i]-b->second[j]) == a->first+b->first){
            //cout << a->second[i] << " " << b->second[j] << "\n";
            cnt++;
            break;
          }
        }
      }
    }else{
      REP(i,a->second.size()-1){
        FOR(j,i+1,b->second.size()){
          if(abs(a->second[i]-b->second[j]) == a->first+b->first){
            cnt++;
            break;
          }
        }
      }
    }
    b++;
    if(b == tall.end() || min+b->first > n-1){
      a++;
      b = a;
    }
  }

  cout << cnt << "\n";

  return 0;
}
