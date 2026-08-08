#include<iostream>
#include<string>
#include <unordered_set>
using namespace std;
string LNS(string s){
  if(s.size() < 2){
    return "";
  }
    unordered_set<char>uset;
    for (int i = 0; i < s.size(); i++)
    {
      /* code */
      uset.insert(s[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
      /* code */
      if(uset.count(tolower(s[i])) && uset.count(toupper(s[i]))){
        continue;
      }
      string prev = LNS(s.substr(0,i));
      string next = LNS(s.substr(i+1));
      if(prev.size() >= next.size()){
        return prev;
      }
      else{
        return next;
      }
    }
    return s;
  }

int main(){
  string s;
  cin >> s;
  cout << LNS(s) << endl;
}