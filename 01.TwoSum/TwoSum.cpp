#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size();j++) {
        if (nums[i] + nums[j] == target) {
          return vector<int>{i, j};
        }
      }
    }
    vector<int> ret;
    return  ret;
  }
};


int main(int argc, char* argv[])
{
  vector<int> testInput{ 2};
  Solution slt;
  vector<int> ret = slt.twoSum(testInput, 2);
  printf("[");
  for (int i = 0; i < ret.size(); i++) {
    if (i == 0) {
      printf("%d", ret[i]);
    } else {
      printf(",%d", ret[i]);
    }
  }
  printf("]\n");
}