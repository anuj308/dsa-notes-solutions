function memoize(fn){
    let cache = {};
    return function(n){

        if(cache[n]){
            return cache[n];
        }

        let result = fn(n);
        cache[n] =  result;
        return result;
    }
}

function square(n){
    console.log("Calculating...")
    return n*n;
}
 let memoizeVal = memoize(square);

 console.log(memoizeVal(5));
 console.log(memoizeVal(5));
 console.log(memoizeVal(5));
 
  console.log(memoizeVal(10));
    console.log(memoizeVal(10));