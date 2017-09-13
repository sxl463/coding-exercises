#include<iostream>
#include<algorithm>
#include<vector>

void swap(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}

using namespace std;

class Solution 
{
public:
  void rotate(int nums[], int n, int k) 
  {
    for (; k = k%n; n -= k, nums += k)
      {
	// Swap the last k elements with the first k elements. 
	// The last k elements will be in the correct positions
	// but we need to rotate the remaining (n - k) elements 
	// to the right by k steps.
	for (int i = 0; i < k; i++)
	  {
	    swap(nums[i], nums[n - k + i]);
	  }
      }
  }
  void rotate_vector(vector<int>& nums, int k)
  {
    
    int n = nums.size();
    k = k%n;
 
    //moving an array to right by k steps, equals to move the first n-k elements to the tail
    //n-k, not k
    for(int i = 0; i < n - k; i++){
      //just use vector as a deque, use erase()
      nums.push_back(*nums.begin());
      nums.erase(nums.begin());
    }
   
  }
  /*
    Every swap will put one number into its correct position, so the running time is O(n)

    For example, at first, nums[] is [1,2,3,4,5,6,7], n is 7, k is 3

    after first outer loop, nums[] is [4,1,2,3], n is 4, k is 3

    after second outer loop, nums[] is [4], n is 1, k is 0

    loop ends.
  */
  void rotate_swap(int nums[], int n, int k) {
    
    cout << "in swap\n";

    /*the main difficulty is using *nums++*/
    for (;k = k%n ; n -= k){
      cout << "n = " << n << "\n";
        for (int i = 0; i < k; i++)
	  swap(*nums++, nums[n - k]);
    }
  }

  //swap, C++ version
  /*

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;   
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};

*/






};


int main(){

  int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int num[2] = {1, 2};
  

  vector<int> nums(num, num + sizeof(num)/sizeof(int));

  
  Solution s;
  s.rotate_swap(num, 10, 7);

  for(int i = 0; i < 10; i++)
    cout << num[i] << " ";

  cout << "\n";
  


  s.rotate_vector(nums, 7);

  for(int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";

  cout << "\n";

  return 0;
}
