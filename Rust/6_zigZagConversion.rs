/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * Example 3:
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 */

use std::collections::HashMap;

pub fn convert(s: String, num_rows: i32) -> String {
    let mut result: String = String::new();
    let mut str_map: HashMap<i32, String> = HashMap::with_capacity(num_rows as usize);
    let mut row = 0;
    let mut direction = 1;

    for i in 0..num_rows {
        str_map.insert(i, String::new());
    }

    for (i, c) in s.chars().enumerate() {
        if let Some(row_str) = str_map.get_mut(&row) {
            row_str.push(c);
        }

        row += direction;

        if row == 0 || row == num_rows - 1 {
            direction *= -1;
        }
    }

    for i in 0..num_rows {
        if let Some(row_str) = str_map.get(&i) {
            result += row_str;
        }
    }

    result
}
