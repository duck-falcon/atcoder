#include <bits/stdc++.h>
using namespace std;
#include "../prime_table.cpp"

int main() {
  int N;
  cin >> N;

  // Sieve生成
  clock_t start = clock();
  PrimeTable pt(N);
  cout << pt.primes.back() << endl;
  clock_t end   = clock();

  const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
  cout << time << "ms" << endl << endl;

  return 0;
}
