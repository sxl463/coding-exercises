#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
  /*  
  void swap(string s, int i, int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    cout << "in swap s = " << s << "\n";
    }*/
    
  string reverseStr(string s, int k) {
    if (s.empty()) return s;
        
    int n = s.size();
    int span = 0;
    for (; span < n; span+=2*k){
      //reverse the first k chars            
      int i = span;
      int j = span+k-1;
      while (i < j){
	swap(s[i++], s[j--]);
      }
    }
	
    cout << "span = " << span << "\n";
    cout << "span-2*k = " << span-2*k << "\n";
    cout << "n-(span-2*k) = " << n-(span-2*k) << "\n";

    if (n-(span-2*k) < k){
      int i = span-2*k;
      int j = n-1;
      cout << "i = " << i << " j = " << j << "\n";
      while (i < j){
	swap(s[i++], s[j--]);
	cout << s << "\n";
      }
    } else {
      int i = span-k;
      int j = n-1;
      while (i < j){
	swap(s[i++], s[j--]);
      }
    }
        
    return s;
  }
};

int main (){
  Solution s;
  s.reverseStr("abcdefg", 1213);

}
