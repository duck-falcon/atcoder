// https://duck-dalcon.hatenablog.com/entry/2021/02/21/223334
auto okcheck = [&](int mid) {
    // your_code
};

int binary_search (int n) {
  int ok_idx = n;
  int ng_idx = -1;
  while(abs(ok_idx - ng_idx) > 1) {
    int mid = (ok_idx + ng_idx) / 2;
    if(okcheck(mid)) ok_idx = mid;
    else ng_idx = mid;
  }
  
  return ok_idx;
  // return ng_idx;
}