function generateSubsets(word) {
    if (word.length === 0) return [""];
    const existingSubsets = generateSubsets(word.substring(1));
    return [...existingSubsets, ...existingSubsets.map(subset => word[0] + subset)];
}

console.log(generateSubsets("abc"));