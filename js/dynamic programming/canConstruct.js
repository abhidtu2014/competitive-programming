const canConstruct = (targetWord, wordBank, memo = {}) => {
    if (targetWord in memo) return memo[targetWord];
    if (targetWord.length === 0) return true;

    for (let word of wordBank) {
        if (targetWord.indexOf(word) === 0) {
            // whole word is present as prefix
            const suffix = targetWord.substring(word.length);
            if (canConstruct(suffix, wordBank, memo)) {
                return (memo[targetWord] = true)
            }
        }
    }
    return (memo[targetWord] = false);
}

/**
 * Brute force
 * Time complexity: O(W^N * N), where W is number of words and N is the length of target word
 * Space complexity: O(N^2)
 * 
 * Memoized solution:
 * Time complexity: O(N^2 * W)
 * Space complexity: O(N^2)
 */

const canConstructTabulated = (targetWord, wordBank) => {
    const table = Array(targetWord.length + 1).fill(false);
    table[0] = true;
    for (let i = 0; i <= targetWord.length; i++) {
        if (table[i] === true) {
            const stringToMatch = targetWord.substring(i)
            for (let word of wordBank) {
                if (stringToMatch.indexOf(word) === 0) {
                    table[i+word.length] = true;
                }
            }
        }
    }
    return table[targetWord.length];
}

console.time();
console.log(canConstructTabulated("abcdef", ["a", "b", "d", "c", "aabbccddeeff", "e", "f"]));
console.timeLog();