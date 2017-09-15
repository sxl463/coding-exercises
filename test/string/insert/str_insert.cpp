
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;

/*
class Foo
{
  //whatever
};

class MyClass
{
  public:
  int myInt;
  vector<Foo> foo_v;
};

bool condition(MyClass mc)
{
  if(mc.myInt==5)
    return true;
  else
    return false;
}


int main (void)
{
  vector<MyClass> myClass_v;
  std::find_if(myClass_v.begin(),myClass_v.end(),condition);
}
*/

 
int main() {
  string str;
  getline (cin, str);
  
  if (find_if(str.begin(), str.end(), ::isdigit) != str.end()) {
    
    cout << "Digit";
  }
  else {
    
    cout << "No digit";
  }
 
}
