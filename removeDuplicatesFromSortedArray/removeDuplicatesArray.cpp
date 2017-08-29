#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int>& nums){
    if(nums.empty()) return 0;

    int index = 0;
    for(int i = 1; i < nums.size(); i++){
      if(nums[index] != nums[i])
	nums[++index] = nums[i];
    }
    return index + 1;
  }

  int removeDuplicatesWithDistance(vector<int>& nums){
    return distance(nums.begin(), unique(nums.begin(), nums.end()));
  }


};




int main(){


  int a[] = {1,1,2};
  int b[] = {2,2,3,4,4,4,5,6,7,9,9,9,9,12};

  //patch initialize vectors with C arrays
  vector<int> arr1 (a, a + sizeof(a)/sizeof(a[0]));
  vector<int> arr2 (b, b + sizeof(b)/sizeof(b[0]));

  Solution sol;

  int ret1 = sol.removeDuplicates(arr1);
  ret1 = sol.removeDuplicatesWithDistance(arr1);


  int ret2 = sol.removeDuplicates(arr2);
  ret2 = sol.removeDuplicatesWithDistance(arr2);




  cout << "arr1 new length = " << ret1 << "\n";
  cout << "arr2 new length = " << ret2 << "\n";

}
