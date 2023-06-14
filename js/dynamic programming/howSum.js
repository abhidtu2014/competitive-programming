// recursion
const howSum = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const result = howSum(remainder, numbers, memo);
        if (result) {
            return (memo[targetSum] = [...result, num]);
        }
    }
    return (memo[targetSum] = null);
}

// Tabulation algorithm
const howSumTabulated = (targetSum, numbers) => {
    const table = Array(targetSum+1).fill(null);
    // seed value
    table[0] = [];
    for (let i = 0; i <= targetSum; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                if (i+num <= targetSum) {
                    table[i+num] = [...table[i], num];
                }
            }
        }
    }
    return table[targetSum];
}

// console.log(howSum(7, [2, 3]))
// console.time('check')
// howSum(7, [5, 3, 4, 7]);
// console.timeLog('check');
// console.log(howSum(7, [4, 2]))


console.log(howSumTabulated(7, [5,4,7, 3]))
console.log(howSumTabulated(8, [3, 5, 2]))
console.log(howSumTabulated(8, [3, 7]))
console.log(howSumTabulated(100, [1, 2, 5, 25]))