#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;
int main(){
  
  // Declaring umap to be of <string, double> type
  // key will be of string type and mapped value will
  // be of double type
  unordered_map<string, double> umap;

  //inserting values by using [] operator
  umap["PI"] = 3.14;
  umap["root2"] = 1.414;
  umap["root3"] = 1.732;
  umap["log10"] = 2.302;
  umap["loge"] = 1.0;
  
  // inserting value by insert function
  umap.insert(make_pair("e", 2.718));

  string key = "PI";

  //if key not found in map iterator to end is returned
  if( umap.find(key) == umap.end() )
    cout << key << " not found\n\n";

  //if key found then iterator to that key is returned
  else 
    cout << "Found " << key << "\n\n";

  key = "lambda";
  if( umap.find(key) == umap.end() )
    cout << key << " not found\n\n";

  //if key found then iterator to that key is returned
  else 
    cout << "Found " << key << "\n\n";

  // iterating over all values of umap
  unordered_map<string, double>::iterator itr;
  cout << "\n All Elements : \n";
  
  for(itr = umap.begin(); itr != umap.end(); itr++){
    cout << itr->first << "  " << itr->second << endl;  
  }

  return 0;

}
