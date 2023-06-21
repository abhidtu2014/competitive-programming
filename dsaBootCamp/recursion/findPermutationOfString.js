function findPermutationOfString (processed, unprocessed) {
    if (unprocessed.length === 0) {
        console.log(processed);
        return;
    }

    for (let i=0; i <= processed.length; i++) {
        const newProcessed = processed.substring(0, i) + unprocessed[0] + processed.substring(i);
        const newUnprocessed = unprocessed.substring(1);
        findPermutationOfString(newProcessed, newUnprocessed);
    }
}

findPermutationOfString("", "abc");