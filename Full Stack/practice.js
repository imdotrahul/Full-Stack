// Global Scope
console.log("Start of Program");

// Hoisting example
console.log(hoistedVar); // undefined due to hoisting
var hoistedVar = "I am hoisted";
console.log(hoistedVar); // "I am hoisted"

// Shadowing example
var shadowVar = "I am global";

function outerFunction(outerArg) {
  // Function Scope
  var outerVar = "I am outer";

  console.log(globalVar); // Access global variable
  console.log(outerVar); // Access outer variable
  console.log(outerArg); // Access outer function argument

  // Shadowing global variable
  var shadowVar = "I am shadowed in outerFunction";
  console.log(shadowVar); // "I am shadowed in outerFunction"

  function innerFunction(innerArg) {
    // Inner Function Scope (Closure)
    var innerVar = "I am inner";

    console.log(globalVar); // Access global variable
    console.log(outerVar); // Access outer variable (closure)
    console.log(innerVar); // Access inner variable
    console.log(innerArg); // Access inner function argument

    // Shadowing outer function's variable
    var shadowVar = "I am shadowed in innerFunction";
    console.log(shadowVar); // "I am shadowed in innerFunction"
  }

  innerFunction("Inner Argument");

  var sum = 4 + 4;
  console.log(sum);
}

// Global variable
var globalVar = "I am global";
outerFunction("Outer Argument");

console.log("End of Program");
