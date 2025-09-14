#include "Utility.hpp"

using namespace std;

// clang-format off
#define rep(i, n) for (int i = 0; (i) < (int)(n); (i)++)
#define repp(i, s, n) for (int i = s; (i) < (int)(n); (i)++)

#define ALL(v) begin(v),end(v)
#define RALL(v) rbegin(v),rend(v)

template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if(a>b) {a=b; return true;} return false; }
// clang-format on

ll std::CalcSquareDist(const Coord& p1, const Coord& p2) {
   const auto [x1, y1] = p1;
   const auto [x2, y2] = p2;

   ll dist = (x1 - x2) * (x1 - x2);
   dist += (y1 - y2) * (y1 - y2);

   return dist;
}

double std::CalcEuclidDist(const Coord& p1, const Coord& p2) {
   ll sq_dist = CalcSquareDist(p1, p2);
   double dist = sqrt(sq_dist);

   return dist;
}

ll std::CalcManhattanDist(const Coord& p1, const Coord& p2) {
   const auto [x1, y1] = p1;
   const auto [x2, y2] = p2;

   ll dist = abs(x1 - x2);
   dist += abs(y1 - y2);

   return dist;
}

ll std::CalcChebyshevDist(const Coord& p1, const Coord& p2) {
   const auto [x1, y1] = p1;
   const auto [x2, y2] = p2;

   ll dist_x = abs(x1 - x2);
   ll dist_y = abs(y1 - y2);
   ll dist = max(dist_x, dist_y);

   return dist;
}

double std::CalcLpDist(const Coord& p1, const Coord& p2, double p) {
   assert(p >= 1);
   const auto [x1, y1] = p1;
   const auto [x2, y2] = p2;

   double dist = pow(abs(x1 - x2), p);
   dist += pow(abs(y1 - y2), p);

   dist = pow(dist, 1.0 / p);
   return dist;
}

int std::GetRandomWeightedElem(const vector<int>& weight_list) {
   assert(!weight_list.empty());
   int sum = accumulate(ALL(weight_list), 0);
   assert(sum > 0);

   int rnd = XorShift() % sum;

   int cur = 0;
   rep(i, weight_list.size()) {
      cur += weight_list[i];
      if (cur > rnd) return i;
   }
   return weight_list.size() - 1;
}
