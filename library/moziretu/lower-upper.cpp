char toLower(char c) {
  return char(c + 32);
}

string toLower(string s) {
  rep(i,s.size()) s.at(i) = toLower(s.at(i));
  return s;
}

char toUpper(char c) {
  return char(c - 32);
}

string toUpper(string s) {
  rep(i,s.size()) s.at(i) = toUpper(s.at(i));
  return s;
}
