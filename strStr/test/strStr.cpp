
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {

    if(needle.size() > haystack.size())
      return -1;

    if(needle.empty())
      return 0;
        
    int prime = 101;
    int d = 256;
        
    int hash_haystack = 0; //hash value of haystack
    int hash_needle = 0; //hash value of needle

    int hash_v = 1;
        
    for(int i = 0; i < needle.size()-1; i++)
      hash_v = (hash_v*256)%prime;
        
    //calculate the hash value of needle, and the hash value of the first window of haystack,
    //here window means the substring with the same length of needle
    for(int i = 0; i < needle.size(); i++){
      hash_needle   = (hash_needle*d + needle[i])%prime;
      hash_haystack = (hash_haystack*d + haystack[i])%prime;
    }
        
        
    for(int i = 0; i <= haystack.size() - needle.size(); i++){

      //check the hash value of needle and current window in haystack
      //if match, then check each char one by one
      if( hash_haystack == hash_needle){
                
	//check char one by one
	int j = 0;
	for(; j < needle.size(); j++){
	  if(needle[j] != haystack[i+j]) break;
	}
                
	//if two hash values match
	if(j == needle.size()) return i;                
      }
            
      //calculate hash value for the next window string: remove head value, add tail value
      hash_haystack = (d*(hash_haystack - haystack[i]*hash_v) + haystack[i+needle.size()])%prime;
            
      //test case: "mississippi" "issi"
      if(hash_haystack < 0)
	hash_haystack += prime;
            
    }
         
    return -1;
  }
};



int main()
{
  string txt = "mississippi";
  string pat = "sipp";
  
  Solution s;

  cout << s.strStr(txt, pat) << "\n";


  return 0;
}
