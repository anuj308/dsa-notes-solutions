import express from 'express';
import { loginController, 
    logoutController,
     aboutController, userController
     } from "./controller.js";


const router = express.Router();

router.get("/user/:name", userController);
router.get("/about/:name", aboutController);
router.get("/login/:name", loginController);
router.get("/logout/:name", logoutController);


export default router;
