const allConstruct = (targetWord, wordBank, memo = {}) => {
    if (targetWord in memo) return memo[targetWord];
    if (targetWord.length === 0) return [[]];

    let possibleConstructs = []
    for (let word of wordBank) {
        if (targetWord.indexOf(word) === 0) {
            // whole word is present as prefix
            const suffix = targetWord.substring(word.length);
            const childConstructs = allConstruct(suffix, wordBank, memo)
            for (let child of childConstructs) {
                possibleConstructs.push([word, ...child])
            }
        }
    }
    return (memo[targetWord] = possibleConstructs);
}

// At each node in Recursion tree we will return possibleConstruct and then iterate over child's possibilities
// and add current word to the list of possibleConstruct returned by child

console.time();
console.log(allConstruct("abcdef", ["a", "b", "d", "c", "aabbccddeeff", "e", "f", "def", "abc"]));
console.log(allConstruct("hello", ["a", "b", "d", "c", "aabbccddeeff", "e", "f", "def", "abc"]));
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

const allConstructTabulated = (target, words) => {
    const table = Array(target.length+1).fill(0).map(() => []);
    // seed
    table[0] = [[]];
    for (let i=0; i <= target.length; i++) {
        if (table[i].length > 0) {
            for (let word of words) {
                if (target.slice(i, i + word.length) === word && i + word.length <= target.length) {
                    for (let combination of table[i]) {
                        table[i+word.length].push([...combination, word]);
                    }
                }
            }
        }
    }
    return table[target.length]
}


console.time();
console.log(allConstructTabulated("abcdef", ["a", "b", "d", "c", "aabbccddeeff", "e", "f", "def", "abc"]));
console.log(allConstructTabulated("hello", ["a", "b", "d", "c", "aabbccddeeff", "e", "f", "def", "abc"]));
console.timeLog();


/**
 * Time compexity: O(N^2*M)
 * Space complexity: O(N^2)
 */