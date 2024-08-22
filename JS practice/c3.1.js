function checkeven(num) {
    if (num < 0) {
        return;
    }
    checkeven(num - 1);
    if (num % 2 == 0) {
        console.log("even");
    } else {
        console.log("odd");
    }
}

checkeven(49);
