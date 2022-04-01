
## primetable(int n)
 - n以下のエラトステネスの篩
 - 素数テーブル、素因数分解が多数必要な時など

###### 使用条件(2sec制限)
 - nは10^7以下
 - メンバ関数`factorList`,`factorPair`へのアクセス回数は10^5以下

#### メンバ変数
 - `vector<int> primes`
   - n以下の素数達
 - `vector<int> sieve`
   - n以下の篩
   - sieve[i] = iの素因数のうち最小の値
   - ただし、sieve[0] = sieve[1] = -1

#### メンバ関数
 - `bool isPrime(int x)`
  - xが素数ならtrue
 - `vector<int> factorList(int x)`
  - xの素因数分解
  - 小さい順
 - `vector<pair<int,int>> factorPair(int x)`
  - xの素因数分解
  - 素因数が小さい順
  - 冪乗形式

---

### 例
#### メンバ変数
 - `vector<int> primes`
   - n = 13
   - primes = [2, 3, 5, 7, 11, 13]
 - `vector<int> sieve`
   - sieve[0] = sieve[1] = -1
   - n = 13
   - sieve = [-1, -1, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13]

#### メンバ関数
 - `bool isPrime(int x)`
  - isPrime(31) = true
  - isPrime(32) = false
 - `vector<int> factorList(int x)`
  - factorList(13) = [13]
  - factorList(30) = [2, 3, 5]
  - factorList(48) = [2, 2, 2, 2, 3]
 - `vector<pair<int,int>> factorPair(int x)`
  - factorPair(13) = [<13,1>]
  - factorPair(30) = [<2,1>, <3,1>, <5,1>]
  - factorPair(48) = [<2,4>, <3,1>]

---

### ベンチマーク

コンストラクタ
`PrimeTable(N)`

| N(exponent) | time(ms) |
| -    | -------- |
| 10(1) | 0.059 |
| 100(2) | 0.063 |
| 1000(3) | 0.087 |
| 10000(4) | 0.331 |
| 100000(5) | 2.566 |
| 1000000(6) | 39.812 |
| 10000000(7) | 403.541 |
| 100000000(8) | 4421.76 |

メンバ関数`factorList(x)`

`Sieve(N)`して、
N以下の乱数をN個生成して実験する

| N(exponent) | time(ms) |
| -    | -------- |
| 1000000(6) | 968.167 |
| 10000000(7) | 14187 |

メンバ関数`factorPair(x)`

`Sieve(N)`して、
N以下の乱数をN個生成して実験する

| N(exponent) | time(ms) |
| -    | -------- |
| 1000000(6) | 2229.85 |
| 10000000(7) | 27197.4 |
