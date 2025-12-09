import express from "express";
import { body } from "express-validator";

import {
  home,
  redirectHome,
  userPage,
  search,
  userDetails,
  showForm,
  submitForm,
  singleUser,
  editUserForm,
  updateUser,
  deleteUser
} from "./controllers/userController.js";

const router = express.Router();

router.get("/", home);
router.get("/home", redirectHome);
router.get("/user/:name/:id", userPage);

router.get("/search", search);

router.get("/usersdetails", userDetails);

router.get("/form", showForm);

router.post("/submit",
  [
    body("name")
      .trim()
      .notEmpty().withMessage("Username is required")
      .isLength({ min: 3 }).withMessage("Minimum 3 characters required"),

    body("email")
      .notEmpty().withMessage("Email is required")
      .isEmail().withMessage("Invalid Email format")
      .normalizeEmail(),
  ],
  submitForm
);

router.get("/user/:id", singleUser);

router.get("/edit/:id", editUserForm);

router.post("/update/:id", updateUser);

router.post("/delete/:id", deleteUser);

export default router;
