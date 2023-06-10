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

/**
 * @param nums
 * @returns
 */
function containsDuplicate(nums: number[]): boolean {
	if (nums.length <= 1) return false;

	for (let i = 0; i < nums.length; i++) {
		for (let j = i + 1; j < nums.length; j++) {
			if (nums[i] === nums[j]) {
				return true;
			}
		}
	}

	return false;
}

/**
 * Best Solution
 *
 * Uses Set which is available in the default Ts library.
 * "new Set(input[])" can only contain new values
 * if the length of unique[] isn't the same as original,
 * means the original contains duplicate.
 *
 * @param nums
 * @returns
 */
/**
 * function containsDuplicate(nums: number[]): boolean {
    return new Set(nums).size !== nums.length
}
*/
