// CommonJS 
//  const color = require('colors');
// const chalk = require('chalk');
// const up = require('upper-case');

// ES Module(in package.json ->>add( "type":"module"))
 import color from 'colors';
 import chalk from "chalk";
 import up from "upper-case"; 

console.log(color.red("hello"));
console.log(color.bold.yellow("hello"));
console.log(color.green.bold("hello"));
console.log(color.blue("hello"));
console.log(chalk.bold.blue("hello"));
console.log(chalk.overline.bold("hello"));

 console.log(up.upperCase("hello"));