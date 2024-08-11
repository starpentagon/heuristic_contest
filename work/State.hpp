#pragma once

#include <bits/stdc++.h>

namespace std {

class State {
  public:
   State();
   State operator=(const State& state);

   // 状態をエラー出力する
   void Output() const;

  protected:
   string GetString() const;
};

// Beam search用の比較演算子
bool operator>(const State& lhs, const State& rhs);
bool operator<(const State& lhs, const State& rhs);

}  // namespace std
