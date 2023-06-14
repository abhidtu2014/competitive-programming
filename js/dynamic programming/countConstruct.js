const countConstruct = (targetWord, wordBank, memo = {}) => {
    if (targetWord in memo) return memo[targetWord];
    if (targetWord.length === 0) return 1;

    let count = 0;
    for (let word of wordBank) {
        if (targetWord.indexOf(word) === 0) {
            // whole word is present as prefix
            const suffix = targetWord.substring(word.length);
            count += countConstruct(suffix, wordBank, memo)
        }
    }
    return (memo[targetWord] = count);
}

console.time();
console.log(countConstruct("abcdef", ["a", "b", "d", "c", "aabbccddeeff", "e", "f", "def", "abc"]));
console.timeLog();

/**
 * Brute force
 * Time complexity: O(W^N * N), where W is number of words and N is the length of target word
 * Space complexity: O(N^2)
 * 
 * Memoized solution:
 * Time complexity: O(N^2 * W)
 * Space complexity: O(N^2)
 */

