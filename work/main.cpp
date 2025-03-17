#include <bits/stdc++.h>

#include "XorShift.hpp"
#include "Utility.hpp"
#include "Parameter.hpp"
#include "SearchInfo.hpp"
#include "State.hpp"

#include "debug_mn.hpp"

using namespace std;

// clang-format off
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)
#define repp(i, s, n) for (int i = s; (i) < (int)(n); (i)++)

#define ALL(v) begin(v),end(v)
#define RALL(v) rbegin(v),rend(v)

template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if(a>b) {a=b; return true;} return false; }

template<class T> ostream& operator<<(ostream& os, vector<T>& vec){ rep(i, vec.size()) os << vec[i] << (i+1==(int)vec.size() ? "" : " "); return os;}
// clang-format on

State LoadProblem();
SearchInfo search_info;
Parameter param;

int main() {
   ios::sync_with_stdio(false);
   std::cin.tie(nullptr);

   cerr << "Result="
        << "dummy"
        << " ";
   cerr << "Score=" << 0 << " ";
   cerr << endl;

   return 0;
}

State LoadProblem() {
#ifdef LOCAL
   string def_file_name;
   cin >> def_file_name;

   ifstream cin(def_file_name);
   assert(!cin.fail() && cin.is_open());
#endif

   State state;
   return state;
}
