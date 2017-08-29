#include <iostream>
#include <cmath>

using namespace std;


int main(){

  float x = 3.1415926;
  float y = 3.1415926;

  if(fabs(x-y) < 1e-9)
    cout << "x==y\n";
  else
    cout << "x!=y\n";


  int a = -5;

  if (a % 2 !=0){
    cout << "a is an odd number.\n";
    cout << "a % 2 == " << a % 2 << "\n";

  }


  return 0;
}
