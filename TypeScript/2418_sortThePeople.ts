/** 
 * You are given an array of strings names, and an array heights 
 * that consists of distinct positive integers. Both arrays are of length n.
 * For each index i, names[i] and heights[i] denote the name and height of the ith person.
 * Return names sorted in descending order by the people's heights.
 *
 * Example 1:
 * Input: names = ["Mary","John","Emma"], heights = [180,165,170]
 * Output: ["Mary","Emma","John"]
 * Explanation: Mary is the tallest, followed by Emma and John.
*/
function sortPeople(names: string[], heights: number[]): string[] {
    const sortedHeights = [...heights].sort((a, b) => b - a);

    const sortedNames: string[] = [];
    for (let i = 0; i < heights.length; i++)
    {
        sortedNames.push(names[heights.indexOf(sortedHeights[i])]);        
    }

    return sortedNames;
};

/**
 * Best Solution: Hashmap
    function sortPeople(names: string[], heights: number[]): string[] {
    const hash: { [key: number] : string } = {};

    for (let i = 0; i < names.length; i++) {
        hash[heights[i]] = names[i];
    }

    return Object.values(hash).reverse();
};
*/