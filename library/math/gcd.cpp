// a > 0, b > 0
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
// a > 0, b > 0, a*b << ll
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }
