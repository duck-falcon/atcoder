#define IUTEST_USE_MAIN 1
#include "../../iutest/include/iutest.hpp"
#include <bits/stdc++.h>
using namespace std;
#include "../prime_table.cpp"

const int INF  =  2147483647 - 1;
const int MINF = -2147483648;

// primesメンバ変数のテスト
IUTEST(primes, max)
{
    Sieve s(1e7);
    IUTEST_ASSERT_EQ(s.primes.back(), 999983);
}

IUTEST(primes, hazureti)
{
    Sieve s(100);
    IUTEST_ASSERT_EQ(s.parimes[0], -1);
    IUTEST_ASSERT_EQ(s.parimes[1], -1);
}
