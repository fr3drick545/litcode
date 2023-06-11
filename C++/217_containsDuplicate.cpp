/**
 * Given an integer array nums, return true if any value appears at least
 * twice in the array, and return false if every element is distinct.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 *
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 *
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // My best solution, 81.1% perf 58.7% mem 
        // an unordered set works better because it only cares about unique elemnts being added while not having a matched pair of values.
        std::unordered_set<int> mapofnums; 
        for (int n : nums)
        {
            if (mapofnums.count(n))
                return true;
            else
                mapofnums.insert(n);
        }
        return false;

    }
};

// My initial solution, 43.6% perf 58.7% mem 
//bool containsDuplicate(vector<int>& nums) {
//    std::unordered_map<int,int> mapofnums {};
//    for (int n : nums)
//    {
//       if (mapofnums.count(n))
//        {
//            return true;
//        }
//       else
//        {
//            mapofnums[n] = 1;
//        }
//    }
//    return false;
//}

// Best solution, 95% perf 82% mem 
// Sort the list, compare adjacent values.
// I wonder if there are any shortcuts you could take during the sorting if you wrote your own sort function.

//sort(nums.begin(), nums.end());
//int i=0;
//while(i<nums.size()-1)
//{
//    if(nums[i] == nums[++i]){
//        return true;
//    }
//}       
//return false;