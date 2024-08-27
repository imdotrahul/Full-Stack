function a(product1, product2) {
    if (product1.price == product2.price && product1.name == product2.name) {
        return true;
    } else {
        return false;
    }
}

let ob1 = {
    name: "Basketball",
    price: 2000,
};
let ob2 = {
    name: "Basketball",
    price: 2000,
};
console.log(a(ob1, ob2));

let str = "Good Morning";
console.log(str.toUpperCase());
