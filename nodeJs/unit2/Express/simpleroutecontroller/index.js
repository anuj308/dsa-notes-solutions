import express from "express";
import router from "./route.js"

const ex = express();


ex.use("/",router);



ex.listen(3000);