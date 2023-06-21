function findAllSubsets(arr) {
    arr.sort((a, b) => a - b);
    let subsets = [[]];
    let currentSubsets = [];
    for (let i = 0; i < arr.length; i++) {
        if (i-1 >= 0 && arr[i] === arr[i-1]) {
            subsets = [...subsets, ...currentSubsets.map(subset => [...subset, arr[i]])];
            continue;
        }
        currentSubsets = [];
        for (let subset of subsets) {
            currentSubsets.push([...subset, arr[i]]);
        }
        subsets = [...subsets, ...currentSubsets];
    }
    return subsets;
}

console.log(findAllSubsets([1,2,2,1]))