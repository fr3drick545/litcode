/**
* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
* 
* Note that you must do this in-place without making a copy of the array.
*/

// My Best solution, playing by the rules.
// Have a slow and a fast pointer. slow pointer stays at first 0 it finds, fast pointer runs to the first nonzero element.
// Swap and continue. 
// perf fluctuates 75-65% mem fluctuates 98-75%

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int slowIndex = 0;
        int len = nums.size();
        while (nums[slowIndex] != 0)
        {
            slowIndex++;

            if (slowIndex == len) // no zeroes whatsoever
                return;
        }

        int fastIndex = slowIndex + 1;
        for (fastIndex; fastIndex < len; fastIndex++)
        {
            if (nums[fastIndex] != 0)
            {
                nums[slowIndex] = nums[fastIndex];
                nums[fastIndex] = 0;
                slowIndex++;
            }
        }
    }
};

// My initial solution, breaking the rules. make a zeroed array the same size as "nums", loop over nums and throw non zeroes into the helper array.
// Memcpy the helper array onto "nums".
// Good performance but relatively bad memory consumption.
// perf fluctuates 91-72% mem 8%

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
// 
//         int* newArray = new int[nums.size()] {};
//         int count = 0;
// 
//         for (int& n : nums)
//             if (n != 0)
//             {
//                 newArray[count] = n;
//                 count++;
//             }
// 
//         memcpy(nums.data(), newArray, nums.size() * sizeof(int));
//         delete[] newArray;
//     }
// };