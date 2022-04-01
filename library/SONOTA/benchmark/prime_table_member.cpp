#include <bits/stdc++.h>
using namespace std;
#include "../prime_table.cpp"

int main(int argc,char *argv[]) {
  const int N = 1e6;

  // Sieve生成
  PrimeTable pt(N);
  vector<int> rd(N,0);
  std::random_device rnd;
  std::mt19937 mt(rnd());
  for (int i = 0; i < N; ++i) {
    rd.at(i) = mt() % N;
  }
  cout << "random generate done" << endl;

  // factorList
  clock_t start_fl = clock();
  for(auto r : rd) {
    pt.factorList(r);
  }
  clock_t end_fl   = clock();

  const double time_fl = static_cast<double>(end_fl - start_fl) / CLOCKS_PER_SEC * 1000.0;
  cout << "factorList" << endl;
  cout << time_fl << "ms" << endl << endl;

  // factorPair
  clock_t start_fp = clock();
  for(auto r : rd) {
    pt.factorPair(r);
  }
  clock_t end_fp   = clock();

  const double time_fp = static_cast<double>(end_fp - start_fp) / CLOCKS_PER_SEC * 1000.0;
  cout << "factorPair" << endl;
  cout << time_fp << "ms" << endl << endl;

  return 0;
}
