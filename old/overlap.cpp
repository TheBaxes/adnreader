#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int minx = 100;

bool isOver(string & s1, string & s2){
  int len = s1.size(), i = minx, r = 0;
  while(s1[i-1]){
    string sb = s2.substr(0, i), sb2 = s1.substr(len - sb.size(), len);
    if(!sb.compare(sb2)) r = sb.size();
    i++;
  }

  if (r) {
    s1 += s2.substr(r,s2.size());
    return 1;
  }
  
  return 0;
}

bool isNotOver(string & s1, string & s2){
  if(isOver(s1,s2)) return true;
  else if(isOver(s2,s1)){
      string tmp = s1;
      s1 = s2;
      s2 = s1;
      return true;
  }
  return false;
}

int main(){
  string s1, s2;
  cin >> s1;
  while(cin >> s2){
    bool b = isNotOver(s1,s2);
    string yn = b ? "Yes: " : "No, everything remains the same :C, ";
    cout << "Is it over? " << yn << s1 << endl;
  }
  cout << s1 << endl;
  return 0;
}
