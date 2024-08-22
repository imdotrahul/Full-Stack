function createCounter() {
  let count = 0; // Local variable, which will be captured by the closure

  return function () {
    count++; // Increment the captured `count` variable
    console.log(count); // Log the current value of `count`
  };
}

let counter1 = createCounter(); // `counter1` is a closure that has access to `count`
let counter2 = createCounter(); // `counter2` is a separate closure with its own `count`

// Use the counters
counter1(); // Outputs: 1
counter1(); // Outputs: 2

counter2(); // Outputs: 1
counter2(); // Outputs: 2

// Intentionally create a memory leak by storing a reference to a closure in an array
let leakyArray = [];
leakyArray.push(counter1);
