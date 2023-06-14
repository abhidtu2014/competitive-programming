const bestSum = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return []
    if (targetSum < 0) return null;

    memo[targetSum] = null
    for (let num of numbers) {
        const remainder = targetSum - num;
        const result = bestSum(remainder, numbers, memo);
        if (result !== null) {
            const possibility = [...result, num];
            if (targetSum in memo && memo[targetSum] !== null) {
                if (memo[targetSum].length > possibility.length) {
                  memo[targetSum] = possibility
                }
            } else {
                memo[targetSum] = [...result, num];
            }
        }
    }
    return memo[targetSum];
}

// Tabulation algorithm
// Time complexity: O(S^2 * N), where S is the target sum and N is the number of elements
// Complexity: O(S^2)
const bestSumTabulated = (targetSum, numbers) => {
    const table = Array(targetSum+1).fill(null);
    // seed value
    table[0] = [];
    for (let i = 0; i <= targetSum; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                if (i+num <= targetSum) {
                    const possibleCombination =  [...table[i], num];
                    if (table[i+num] === null || table[i+num].length > possibleCombination.length) {
                        table[i+num] = possibleCombination;
                    }
                }
            }
        }
    }
    return table[targetSum];
}

console.log(bestSumTabulated(7, [5,4,7, 3]))
console.log(bestSumTabulated(8, [3, 5, 2]))
console.log(bestSumTabulated(8, [1, 4, 5]))
console.log(bestSumTabulated(100, [1, 2, 5, 25]))
