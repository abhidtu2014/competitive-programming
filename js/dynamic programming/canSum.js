const canSum = (targetSum, numbers) => {
    const table = Array(targetSum+1).fill(false);
    // seed the table with targetSum as zero as true
    table[0] = true;
    for (let i = 0; i <= targetSum; i++) {
        if (table[i]) {
            for (let num of numbers) {
                if (table[i+num] <= targetSum) {
                    table[i+num] = true;
                }
            }
        }
    }
    return table[targetSum];
}


console.log(canSum(7, [5,4,7, 3]))
console.log(canSum(8, [3, 5, 2]))
console.log(canSum(8, [3, 7]))
console.log(canSum(100, [1, 2, 5, 25]))