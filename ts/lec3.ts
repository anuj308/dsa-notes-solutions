const gameScores = [14,23,33,43,67]
const favoriteThings = ["books","movies","music","tv","games"]
const voters =[{name:"pri",age:24},{name:"anuj",age:19}]

// it for flexiblity
function getLastItem<Type>(array: Type[]): Type | undefined{
    return array[array.length - 1]
}

console.log(getLastItem(gameScores))
console.log(getLastItem(gameScores))
console.log(getLastItem(gameScores))