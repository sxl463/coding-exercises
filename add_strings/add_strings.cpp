#include <string>
#include <iostream>
#include <algorithm>
//#include <stdlib.h>


using namespace std;

string addStrings(string num1, string num2){

  string res = "";

  int m = num1.size();
  int n = num2.size();
  int i = m - 1, j = n - 1, carry = 0;

  //not to the end
  while(i >= 0 || j >= 0){
    
    int value_i = (i>=0) ? num1[i--] - '0' : 0;
    int value_j = (j>=0) ? num2[j--] - '0' : 0;
    int sum = value_i + value_j + carry;

    if(sum >= 10 ){
      carry = 1;
      sum = sum%10;
    }
    else 
      carry = 0;

    //    cout << "sum = " << to_string(sum) << "\n";

    res.insert(0, to_string(sum));   
  }

  if(carry == 1)
    res.insert(0, "1");
  return res;

}


int main(){

  string a = "9999999999981", b = "19";

  cout << addStrings(a, b) << "\n";

  return 0;

}
