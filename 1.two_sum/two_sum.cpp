#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> hashmap;
      vector<int> ret;
      int n = nums.size();
      for(int i = 0; i < n; i++){

	cout << "hashmap" << "\n";
	for(map<int,int>::iterator I = hashmap.begin(), E=hashmap.end();
	    I!=E;++I)
	  cout << "i = " << I->first << " " <<I->second<<"\n";
	  
	cout << "nums["<<i<<"] = "<< nums[i] << "\n";
  int hope = target - nums[i];
	  cout << "hope to find " << hope << "\n";
	  cout << "map.find() = " << hashmap.find(hope)->second << "\n";

	if(hashmap.find(target - nums[i]) != hashmap.end()){
	  
	  int hope = target - nums[i];
	  cout << "hope to find " << hope << "\n";
	  cout << "map.find() = " << hashmap.find(hope)->second << "\n";
	  ret.push_back(hashmap.find(target-nums[i])->second);
	  ret.push_back(i);
	  break;
	}
	hashmap[nums[i]] = i;
      }
      return ret;
    }
};


int main(){

  //  int a[4] = {2, 7, 11, 15};
  int a[3] = {3, 2, 4};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));
  
  int k = 6;

  Solution s;
  vector<int> ret = s.twoSum(vec, k);
  cout << "return vec:\n";
  for(int i = 0; i < ret.size(); i++)
    cout << ret[i] << " ";
  cout << "\n";
  return 0;
}





//AC solution
/*


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        vector<int> ret;
        int n = nums.size();
        for(int i = 0; i < n; i++){
	  
	
	    if(hashmap.find(target - nums[i]) != hashmap.end()){
	  
	        ret.push_back(hashmap.find(target-nums[i])->second);
	        ret.push_back(i);
	        break;
	    }
	        hashmap[nums[i]] = i;

        }
        return ret;
      
    }
};

*/
