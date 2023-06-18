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
use std::collections::HashMap;
pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
    // Create a new empty set
    let mut my_set: HashMap<i32, i32> = HashMap::new();
    
    for i in 0..nums.len()
    {
        if let Some(index) = my_set.get(&nums[i]) // Check if the map includes current num
        {
            if ((i as i32 - index).abs() <= k) 
            {
                return true;
            }
        }

        // Insert elements into the set if its not there
        my_set.insert(nums[i], i as i32);
    }

    return false;
}

/** 
 * Best Solution
 * Creates a set with a capacity and operates within that window only.
*/
/*
pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut num_set = HashSet::with_capacity(k);
        let mut left = 0;
        let mut right = 0;
        while (right - left) <= k {
            if right >= nums.len() {
                return false;
            }
            if !num_set.insert(nums[right]) {
                return true;
            }
            right += 1;
        }
        num_set.remove(&nums[left]);
        left += 1;
        while right < nums.len() {
            if !num_set.insert(nums[right]) {
                return true;
            }
            num_set.remove(&nums[left]);
            left += 1;
            right += 1;
        }
        return false;
    }
 */