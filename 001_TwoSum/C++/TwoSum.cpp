#include <vector>

using namespace std;
#include <unordered_map>
#include <bitset>

class Solution
{
public:
  vector<int> twoSum_v1(vector<int>& nums, int target)
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
  vector<int> twoSum_v2(vector<int>& nums, int target)
  {
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
      int sub = target - *it;
      vector<int>::iterator it_sub = std::find(nums.begin(), nums.end(), sub);
      if (it_sub != nums.end() && it_sub != it) {
        int i = it - nums.begin();
        int j = it_sub - nums.begin();
        return vector<int>{i, j};
      }

    }
    vector<int> ret;
    return  ret;
  }

  vector<int> twoSum_v3(vector<int>& nums, int target)
  {
    std::unordered_map<int, int> num_map;

    for (int i = 0; i < nums.size(); i++) {
      num_map.insert(make_pair( nums[i], i ));
    }
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
      int sub = target - *it;
      std::unordered_map<int, int>::const_iterator it_sub = num_map.find(sub);
      if (it_sub!=num_map.end()) {
        int i = it - nums.begin();
        int j = it_sub->second;
        if (i != j) {
          return vector<int>{i, j};
        }
      }

    }
    vector<int> ret;
    return  ret;
  }

  vector<int> twoSum_v4(vector<int>& nums, int target) //fastest
  {
    std::unordered_map<int, int> num_map;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      std::unordered_map<int, int>::const_iterator it_cmp = num_map.find(complement);
      if (it_cmp != num_map.end()) {
        return vector<int>{i, it_cmp->second};
      }

      num_map[nums[i]] = i;
    }
    vector<int> ret;
    return  ret;
  }

  vector<int> twoSum_v5(vector<int>& nums, int target)
  {
    std::unordered_map<int, int> num_map;
    vector<int> ret(2);
    for (int i = 0; i < nums.size(); i++) {
      if (num_map.find(target - nums[i]) != num_map.end()) {
        ret[0] = num_map[target - nums[i]];
        ret[1] = i;
      } else {
        num_map[nums[i]] = i;
      }
    }
    
    return  ret;
  }
};




int main(int argc, char* argv[])
{
  vector<int> testInput{3,2,4};
  Solution slt;
  vector<int> ret = slt.twoSum_v5(testInput, 6);
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