#include "State.hpp"
#include "debug_st.hpp"

using namespace std;

// clang-format off
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)
#define repp(i, s, n) for (int i = s; (i) < (int)(n); (i)++)

#define ALL(v) begin(v),end(v)
#define RALL(v) rbegin(v),rend(v)

template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if(a>b) {a=b; return true;} return false; }
// clang-format on

bool operator>(const State& lhs, const State& rhs) {
   assert(false);
   return false;
}

bool operator<(const State& lhs, const State& rhs) {
   assert(false);
   return false;
}

State::State() {
}

State State::operator=(const State& state) {
   // メンバ変数をコピー
   // Note: メンバ変数を追加した場合はここに追加する
   return *this;
}

string State::GetString() const {
   assert(false);

   string str;
   return str;
}

void State::Output() const {
   cerr << GetString() << endl;
}
