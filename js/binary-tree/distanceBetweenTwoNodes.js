function solve(root, value1, value2, level) {
    if (!root) return 0;

    if (root.val === value1 || root.val === value2) {
        return level;
    }
    const left = solve(root.left, value1, value2, level+1);
    const right = solve(root.right, value1, value2, level+1);

    if (left && right) return left + right - 2*level;
    return 0;
}



function findDistanceBetweenTwoNodes (root) {

}