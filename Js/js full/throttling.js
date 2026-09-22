function throttle(fn,delay){
    let lastTime = 0;
    return function(){
        const now = Date.now();
        if(now - lastTime >= delay){
            fn();
            lastTime = now;
        }
    }
}

const handleScroll = throttle(()=>{
    console.log("API Call...")
},1000);

window.addEventListener("scroll",handleScroll)

