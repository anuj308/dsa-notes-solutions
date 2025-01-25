import "core-js/stable"; // just for older verion issues // nt working find is not there in this libaray so
type Pizza = {
  id: number
  name: string
  price: number
}
type Order = {
  id: number
  pizza: Pizza
  status: "ordered" | "completed"
}

let cashInRegister = 100;
const orderQueue: Order[] = [];
let nextOrderId = 1;
let nextPizzaId = 1;

const menu: Pizza[] = [
  { id: nextPizzaId++, name: "Margherita", price: 8 },
  { id: nextPizzaId++, name: "Pepperoni", price: 10 },
  { id: nextPizzaId++, name: "Hawaiian", price: 10 },
  { id: nextPizzaId++, name: "Veggie", price: 10 },
];

// generic
function addToArray<T>(array:T[], item:T): T[] {
  array.push(item)
  return array
}

console.log(addToArray<Pizza>(menu, { id: nextPizzaId++, name: "aif", price: 23 }))
console.log(addToArray<Order>(orderQueue, { id: nextOrderId++, pizza: menu[0], status: "ordered" })) // otder for status is without it is only string but now typescript can understan the string can be ordered or completed 
// void means it will not return anything
const addNewPizza = (pizzaObj: Omit<Pizza, "id">): Pizza => {
  const updatedPizzaObj: Pizza = { ...pizzaObj, id: nextOrderId++ };
  menu.push(updatedPizzaObj);
  return updatedPizzaObj;
};

function placeOrder(pizzaName: string): Order | undefined {
  const pizzaObj = menu.find(pi => pi.name === pizzaName); // find
  if (!pizzaObj) {
    console.error(`${pizzaName} does not exist in the menu`)
    return
  }
  cashInRegister += pizzaObj.price;
  const newOrder: Order = { id: nextOrderId++, pizza: pizzaObj, status: "ordered" };
  orderQueue.push(newOrder);
  console.log(newOrder)
  return newOrder;
}


function completeOrder(orderId: number): Order | undefined {
  const order = orderQueue.find(obj =>
    obj.id === orderId
  );
  if (!order) {
    console.error(`${orderId} was not found in the OrderQueue`)
    return
  }
  order.status = "completed"
  console.log(order)
  return order;
}
// type narowing
export function getPizzaDetail(identifier: number | string): Pizza | undefined {
  // const pizza = menu.find(p => p.id === identifier || p.name === identifier)
  if (typeof identifier === "string") {
    return menu.find(p => p.name.toLowerCase() === identifier.toLowerCase())
  } else if (typeof identifier === "number") {
    return menu.find(p => p.id === identifier)
  } else {
    throw new Error("typeError the parameter should either be string or number")
  }
  // console.log(pizza)
  // return pizza
}
// addNewPizza({ name: "aif", price: 23 })
// addNewPizza({ name: "asif", price: 923 })
// placeOrder("Margherita");
// completeOrder(1)
// getPizzaDetail(1)
// console.log(menu)


//  typescript - help in type error like in 55 line if i input a string it gives error
// typescript - has to be converted to js to run it in browser or terminal
// tsnode is package to convert ts to js and run it by cmd ts-node filename
