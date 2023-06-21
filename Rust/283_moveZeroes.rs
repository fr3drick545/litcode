/**
 * Given an integer array nums, move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
*/

pub fn move_zeroes(nums: &mut Vec<i32>) {
    let mut zeros_to_add = 0;
    let mut i = 0;

    while i < nums.len() {
        if nums[i] == 0 {
            nums.remove(i);
            zeros_to_add += 1;
        }
        else {
            i += 1;
        }
    }

    for _i in 0..zeros_to_add {
        nums.push(0);
    }
}

/**
 * Best Solution
 */
pub fn move_zeroes(nums: &mut Vec<i32>) {
    let mut z = Vec::new();
    nums.retain(|x| {
     if *x != 0 { true } else { z.push(0); false }
    });
    &nums.append(&mut z);
}