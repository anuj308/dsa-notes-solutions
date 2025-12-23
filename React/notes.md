## Learning React from Colleage Classes 

## initialize a = 5
## declare let a;
## declare and initialize let a = 5;
# var
- can redeclare and change value
- when declare a variable with no value by default it undefined when printed.

# let 
- cannot redeclare in same block scope but in different scope 
- can change the value
- when declare a variable with no value by default it undefined when printed.

# const
- when declare have to initialize the value. otherwise error
- cannot chnage the value
- cannot redeclare

## every() - check if all elements pass a conditions
---
    console.log(arr.every(i => i%2==0)) // false
    console.log(even.every(i => i%2==0)) // true

## filter() - return elements that match a condition
---
    const res = arr.filter(i => i%2===0)
    console.log(res);

## forEach - execute for every index (no return like every)(difference)
---
    const arr = [1,3,4];
    arr.forEach(e => {
        console.log(e%2==0)
    });

## indexOf() - give the index of the value in array
--- 
    const arr = [1,3,4];
    console.log(arr.indexOf(3)) // 1
    console.log(arr.indexOf(10)) // -1

## array.form() -> create an array from iterable or string
---
    const str = 'aks'
    console.log(Array.from(str))

##  map() -> transform element and returns a new array
---
    const arr = [1,3,4];
    const narr = arr.map((w)=> w*2)
    console.log(narr); // [2,6,8]

---

## reduce() - Reduces array to a single value by executing a reducer function

**Definition:**
- The `reduce()` method executes a reducer function on each element of the array, resulting in a single output value
- It takes two parameters: a callback function and an optional initial value

**Syntax:**
```javascript
array.reduce((accumulator, currentValue, currentIndex, array) => {
    // return updated accumulator
}, initialValue)
```

**Important Points:**
- ✅ Accumulator stores the accumulated result
- ✅ If no initial value is provided, the first element becomes the accumulator
- ✅ Returns a single value (can be number, string, object, or array)
- ✅ Does not mutate the original array

**Examples:**

```javascript
// Example 1: Sum of array elements
const numbers = [1, 2, 3, 4, 5];
const sum = numbers.reduce((acc, cur) => acc + cur, 0);
console.log(sum); // 15

// Example 2: Find maximum value
const nums = [10, 5, 25, 15, 20];
const max = nums.reduce((acc, cur) => cur > acc ? cur : acc);
console.log(max); // 25

// Example 3: Count occurrences
const fruits = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple'];
const count = fruits.reduce((acc, fruit) => {
    acc[fruit] = (acc[fruit] || 0) + 1;
    return acc;
}, {});
console.log(count); // {apple: 3, banana: 2, orange: 1}

// Example 4: Flatten nested arrays
const nested = [[1, 2], [3, 4], [5, 6]];
const flat = nested.reduce((acc, cur) => acc.concat(cur), []);
console.log(flat); // [1, 2, 3, 4, 5, 6]
```

---

## Destructuring - Extract values from arrays and objects

**Definition:**
- Destructuring assignment syntax is a JavaScript expression that makes it possible to unpack values from arrays or properties from objects into distinct variables
- It provides a clean and readable way to extract multiple values at once

### Array Destructuring

**Important Points:**
- ✅ Uses square brackets `[]`
- ✅ Position matters - extracts by index
- ✅ Can skip elements using commas
- ✅ Can set default values
- ✅ Can use rest operator to collect remaining elements

**Examples:**

```javascript
// Basic array destructuring
const numbers = [10, 20, 30, 40];
const [a, , , b, c = 100] = numbers;
console.log(a);  // 10
console.log(b);  // 40
console.log(c);  // 100 (default value as no 5th element)

// Swapping variables
let x = 5, y = 10;
[x, y] = [y, x];
console.log(x, y); // 10, 5

// Nested array destructuring
const nested = [1, [2, 3], 4];
const [first, [second, third], fourth] = nested;
console.log(first, second, third, fourth); // 1, 2, 3, 4
```

### Object Destructuring

**Important Points:**
- ✅ Uses curly braces `{}`
- ✅ Extracts by property name
- ✅ Can rename variables using colon `:`
- ✅ Can set default values
- ✅ Order doesn't matter

**Examples:**

```javascript
// Basic object destructuring
const person = { name: 'aks', age: 19, country: 'India' };
const { name, age, city = 'Unknown' } = person;
console.log(name);  // 'aks'
console.log(age);   // 19
console.log(city);  // 'Unknown' (default value)

// Renaming variables
const { name: n, age: ag } = person;
console.log(n);   // 'aks'
console.log(ag);  // 19

// Nested object destructuring
const user = {
    id: 1,
    profile: {
        firstName: 'John',
        lastName: 'Doe'
    }
};
const { profile: { firstName, lastName } } = user;
console.log(firstName, lastName); // 'John' 'Doe'

// Destructuring in function parameters
function displayPerson({ name, age, country }) {
    console.log(`${name} is ${age} years old from ${country}`);
}
displayPerson(person); // 'aks is 19 years old from India'
```

---

## Spread Operator (...) - Expands iterables into individual elements

**Definition:**
- The spread operator `...` allows an iterable (like array or string) to be expanded in places where zero or more arguments or elements are expected
- It "spreads" the elements of an array or object

**Important Points:**
- ✅ Creates shallow copies (doesn't deep clone nested objects)
- ✅ Works with arrays, objects, and strings
- ✅ Useful for immutability patterns
- ✅ Can be used in function calls, array literals, and object literals

**Examples:**

```javascript
// Example 1: Merging arrays
const arr1 = [1, 2, 3];
const arr2 = [4, 5, 6];
const merge = [...arr1, ...arr2];
console.log(merge); // [1, 2, 3, 4, 5, 6]

// Example 2: Copying arrays
const original = [1, 2, 3];
const copy = [...original];
console.log(copy); // [1, 2, 3]

// Example 3: Adding elements
const numbers = [2, 3, 4];
const withMore = [1, ...numbers, 5, 6];
console.log(withMore); // [1, 2, 3, 4, 5, 6]

// Example 4: Spread in function calls
const nums = [5, 10, 15];
console.log(Math.max(...nums)); // 15

// Example 5: Spread with objects
const obj1 = { a: 1, b: 2 };
const obj2 = { c: 3, d: 4 };
const merged = { ...obj1, ...obj2 };
console.log(merged); // {a: 1, b: 2, c: 3, d: 4}

// Example 6: Overriding properties
const defaults = { theme: 'dark', lang: 'en' };
const userPrefs = { theme: 'light' };
const settings = { ...defaults, ...userPrefs };
console.log(settings); // {theme: 'light', lang: 'en'}

// Example 7: Spread with strings
const str = 'hello';
const chars = [...str];
console.log(chars); // ['h', 'e', 'l', 'l', 'o']
```

---

## Rest Operator (...) - Collects multiple elements into an array

**Definition:**
- The rest operator `...` collects multiple elements and condenses them into a single array
- It looks identical to spread operator but does the opposite - it "gathers" remaining elements
- Must be the last parameter in function parameters or destructuring

**Important Points:**
- ✅ Must be the last parameter in a function
- ✅ Must be the last element in destructuring
- ✅ Collects all remaining arguments/elements into an array
- ✅ Useful for functions with variable number of arguments
- ✅ Makes code more flexible and reusable

**Examples:**

```javascript
// Example 1: Rest in function parameters
function sum(...nums) {
    return nums.reduce((acc, cur) => acc + cur, 0);
}
console.log(sum(1, 2, 3, 4));        // 10
console.log(sum(5, 10, 15, 20, 25)); // 75

// Example 2: Rest with other parameters
function multiply(multiplier, ...numbers) {
    return numbers.map(num => num * multiplier);
}
console.log(multiply(2, 1, 2, 3, 4)); // [2, 4, 6, 8]

// Example 3: Rest in array destructuring
const [first, ...rest] = [10, 20, 30, 40];
console.log(first); // 10
console.log(rest);  // [20, 30, 40]

// Example 4: Rest in object destructuring
const person = { name: 'John', age: 30, city: 'NYC', country: 'USA' };
const { name, ...others } = person;
console.log(name);   // 'John'
console.log(others); // {age: 30, city: 'NYC', country: 'USA'}

// Example 5: Combining first, middle, and rest
const numbers = [1, 2, 3, 4, 5, 6];
const [a, b, ...remaining] = numbers;
console.log(a);         // 1
console.log(b);         // 2
console.log(remaining); // [3, 4, 5, 6]

// Example 6: Rest with default parameters
function greet(greeting = 'Hello', ...names) {
    return names.map(name => `${greeting}, ${name}!`);
}
console.log(greet('Hi', 'Alice', 'Bob', 'Charlie'));
// ['Hi, Alice!', 'Hi, Bob!', 'Hi, Charlie!']
```

---

## Key Differences: Spread vs Rest

| Feature | Spread Operator | Rest Operator |
|---------|----------------|---------------|
| **Purpose** | Expands/spreads elements | Collects/gathers elements |
| **Usage** | Right side of assignment | Left side of assignment |
| **Location** | Function calls, array/object literals | Function parameters, destructuring |
| **Result** | Individual elements | Single array |
| **Example** | `func(...arr)` | `function func(...args)` |

---

design a reusable custom hook called useForm to handle form state validation and rest functionality for login form
the useForm hook should
accept initialvalues and a validate function a arguments
manage form values error and touched fields
expose value errors tocuhed , handleChange, handleBlur, handleSubmit, resetForm

Form fields:
email : Required, must be a valid email format
password: Required, minimim 6 characters

Behavior:
validation should run on fields blur and on form submission
Error messages should be displayed only after a field has been touched
on successful submission, log the form data to the console and reset the form


implement todo list and forms in redux