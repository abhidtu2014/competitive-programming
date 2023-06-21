const sumDigists = (num) => {
    if (num === 0) return 0;
    return num % 10 + sumDigists(parseInt(num/10)); 
}


console.log(sumDigists(1342));