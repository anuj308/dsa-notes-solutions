// const promise = new Promise((resolve,reject)=>{
   
//     let success = true;

//     if(success){
//         resolve("Data loaded success");
//     }else{
//         reject("Something went wrong");
//     }
// });

// console.log(promise)

// Promise.then((result)=>{
//     console.log(result)
// }).catch((error)=>{
//     console.log(error);
// })

//  const promise = new Promise((resolve,reject)=>{
//     reject("server error");
//  })

//  promise.then((data)=>{
//     console.log(data);
//  }).catch((error)=>{
//     console.log(error);
//  })

// const promise = new Promise((resolve)=>{
//     resolve(10);
// })

// promise.then((num)=>{
//     console.log(num);
//     return num * 2;
// }).then((num)=>{
//     console.log(num);
//     return num * 2;
// }).then((num)=>{
//     console.log(num);
// })


//   new Promise((resolve)=>{
//       resolve("Javascript");
//   }).then((data)=>{
//     return data + " ES6"
//   }).then((data)=>{
//     return data + " Promises"
//   }).then((data)=>{
//     console.log(data)
//   })

// new Promise((resolve)=>{
//     resolve(100)
// }).then((num)=>{
//     throw new Error("Something wrong")
// }).then((num)=>{
//     console.log(num)
// }).catch((err)=>{
//     console.log(err.message)
// })

// new Promise((resolve)=>{
//     resolve("Done")
// })
// .then((data)=>{
//     console.log(data)
// })
// .catch((err)=>{
//     console.log(err)
// })
// .finally(()=>{
//     console.log("Alway Execute")
// })


// const p1 = Promise.resolve("HTML");
// const p2 = Promise.resolve("CSS");
// const p3 = Promise.resolve("JAVASCRIPT");

// Promise.all([p1,p2,p3]).then((result)=>{
//     console.log(result)
// }).catch((err)=>{
//  console.log(err)
// })

// const p1 = Promise.resolve("HTML");
// const p2 = Promise.reject("error");
// const p3 = Promise.resolve("JAVASCRIPT");

// Promise.allSettled([p1,p2,p3]).then((result)=>{
//     console.log(result)
// }) 

// const p1 = new Promise(resolve=>{
//     setTimeout(()=>{
//         resolve("First");
//     },3000)
// })

// const p2 = new Promise(resolve=>{
//     setTimeout(()=>{
//         resolve("Second");
//     },1000)
// })

// Promise.race([p1,p2]).then((result)=>{
//     console.log(result)
// })

const p1 = Promise.reject("Error")
const p2 = new Promise(resolve=>{
    setTimeout(()=>{
          resolve("Success");
      },1000)
})

Promise.any([p1,p2]).then((result)=>{
    console.log(result)
})