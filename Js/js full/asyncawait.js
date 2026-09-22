// async function getData(){
//     return "Hello";
// }
// getData().then(console.log)

// function fetchUser(){
//     return new Promise((resolve)=>{
//         setTimeout(()=>{
//             resolve("Heavy coding")
//         },2000);
//     })
// }
// async function userData(){
//     const user = await fetchUser();
//     console.log(user);
// }

// userData();


// function getUser(){
//     return new Promise((resolve)=>{
//         setTimeout(()=>{
//             resolve("Shubham")
//         },2000);
//     })
// }
// function getCourse(){
//     return new Promise((resolve)=>{
//         setTimeout(()=>{
//             resolve("Javascript")
//         },1000);
//     })
// }

// async function showData(){
//     const user = await getUser();
//     const course = await getCourse();
//     console.log(user)
//     console.log(course)
// }
// showData()

function fetchData(){
    return new Promise((resolve,reject)=>{
        reject("Server Error") 
    })
}

async function getData(){
    try{
        const data  = await fetchData();
        console.log(data)
    } catch(error){
        console.log(error)
    } finally {
        console.log("Order placed successfully")
    }
}

getData();


try{
    const response  = await fetch("https://razopray.com/getpaymentList"); 
    const data  = await response.json()
    console.log(data)
}catch(error){

}
