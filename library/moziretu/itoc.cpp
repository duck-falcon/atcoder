// int -> char 一桁のみ

char itoc(int a) {
  if(a==0) return '0';
  if(a==1) return '1';
  if(a==2) return '2';
  if(a==3) return '3';
  if(a==4) return '4';
  if(a==5) return '5';
  if(a==6) return '6';
  if(a==7) return '7';
  if(a==8) return '8';
  if(a==9) return '9';
  return 'e';
}

const int h = 3600;
const int m = 60;

string hutaketa(int a) {
  int ten = a / 10;
  int one = a - ten * 10;
  string ans = "";

  ans+=itoc(ten);
  ans+=itoc(one);
  return ans;
}
