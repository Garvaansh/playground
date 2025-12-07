const input = require("prompt-sync")();

/* Direct method --> to get the array in one line */

// let arr;
// arr = input("Enter the array: ").split(" ").map(Number);

/* --------------------------------------------------------------- */

/* Indirect methor --> */
// let arr = [];
// let n = Number(input("Enter the number of elements: "));
// for (let i = 0; i < n; i++){
  //   arr.push(Number(input(`Enter element ${i+1}: `)));
  // }
  
/* --------------------------------------------------------------- */

/* Keep adding numbers in array until 0 is added. */
// let arr = [];
// while(true){
  //   let num = Number(input("Enter a number: "));
  //   if (num === 0) break;
  //   arr.push(num);
  // }
  
/* --------------------------------------------------------------- */

/* Filter the array for numbers divisible by 10 */
let arr = [], ans = [];

arr = input("Enter the array: ").split(" ").map(Number);
// for(let i in arr){
  //   if(arr[i] % 10 === 0) ans.push(arr[i]);
  // } 


// Method 2 -->
// ans = arr.filter((num) => num%10 === 0)
// ans = arr.filter((num) => {return num%10 === 0})
console.log(ans);
/* --------------------------------------------------------------- */

/* create an array of square of numbers */
// let arr = [], ans = [];
// arr = input("Enter the array: ").split(" ").map(Number);
// for(let i in arr){
//     ans.push(arr[i]*arr[i]);
//   }

 /* --------------------------------------------------------------- */

/*  Use reduce to calculate the factorial of a given number
    from an array of first n natural numbers. 
    (n being the numbers whose factorial needs to be calculated) */ 

// let arr = [];
// arr = (input("Enter the number: ")).split(" ").map(Number);
// let factorial = arr.reduce((a, b) => a * b, 1);
//   console.log(`Factorial: ${factorial}`);

