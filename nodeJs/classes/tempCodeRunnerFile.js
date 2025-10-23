fs.readFile("hello.txt","utf-8",(err,data)=>{
    if(err) console.err("error in read operation")
    else console.log(data)
})