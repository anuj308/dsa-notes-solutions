import {configureStore} from "@reduxjs/toolkit";
import counterReducer from "./counterSlice.jsx"

export const store = configureStore({
    reducer:{
        counter: counterReducer
    }
})