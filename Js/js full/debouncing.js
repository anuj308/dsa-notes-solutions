 function debounce(fn,delay){
    let timer;
    return function(){
        clearTimeout(timer);
        timer = setTimeout(function(){
            fn();
        },delay);
    };
 }

 function search(){
    console.log("API Call searching..");
 }

 let handleSearch = debounce(search,500)

 handleSearch();
 handleSearch();
 handleSearch();
 handleSearch();
 handleSearch();
 handleSearch();
 handleSearch();