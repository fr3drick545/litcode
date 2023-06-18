/**
 * Given an integer array nums and an integer k, return 
 * true if there are two distinct indices i and j in the 
 * array such that nums[i] == nums[j] and abs(i - j) <= k.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * Example 3:
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
*/

// Basically same solution as last time.
// Perf 72% mem 37%

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        std::unordered_set<int> data;

        for (int i = 0; i < n; i++)
        {
            if (data.count(nums[i]) && abs(i - data[nums[i]]) <= k)
                return true;

            data[nums[i]] = i;
        }

        return false;
    }
};

/* 
    Sliding Window Solution
    Perf 28% Mem 96%

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int>mp;

        int i=0,j=0;

        while(j<n){


           if(mp.count(nums[j])) return true;
           mp[nums[j]]++;

            if(j-i<k){
                 j++;  // window size is not hit
            }
            else if(abs(j-i)==k){
                // window size is hit
                 // remove  frequency of nums[i]
                 mp[nums[i]]--;
                 if(mp[nums[i]]==0)mp.erase(nums[i]);
                 i++;
                 j++;
            }

        }//while

       return false;
    }
};
 */

/*
    best solution?
    perf 91% mem 74% 
    class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++){
            if (mp.count(nums[i]) && abs(mp[nums[i]] - i) <= k)
                return 1;

            mp[nums[i]] = i;
        }

        return 0;

    }
};

*/
