// i が bit 列
rep(i,1<<n) {
  // 1桁ずつ照らし合わせる,bit桁が 1だったときのみ何か操作
  rep(j,n) if(i>>j&1) {
    // your_code
  }
}