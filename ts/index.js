"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
require("core-js/stable"); // just for older verion issues
var menu = [
    { name: "Margherita", price: 8 },
    { name: "Pepperoni", price: 10 },
    { name: "Hawaiian", price: 10 },
    { name: "Veggie", price: 10 },
];
var cashInRegister = 100;
var orderQueue = [];
var ids = 1;
var addNewPizza = function (pizzaObj) {
    menu.push(pizzaObj);
};
function placeOrder(pizzaName) {
    var pizzaObj = menu.find(function (pi) { return pi.name === pizzaName; }); // find
    if (!pizzaObj) {
        console.error("".concat(pizzaName, " does not exist in the menu"));
        return;
    }
    cashInRegister += pizzaObj.price;
    var newOrder = { id: ids++, pizza: pizzaObj, status: "ordered" };
    orderQueue.push(newOrder);
    console.log(newOrder);
    return newOrder;
}
function completeOrder(orderId) {
    var order = orderQueue.find(function (obj) {
        return obj.id === orderId;
    });
    if (!order) {
        console.error("".concat(orderId, " was not found in the OrderQueue"));
        return;
    }
    order.status = "completed";
    console.log(order);
    return order;
}
addNewPizza({ name: "aif", price: 23 });
placeOrder("Margherita");
completeOrder(1);
