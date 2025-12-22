import mongoose from "mongoose";

// MongoDB URL + Database
const url = "mongodb://localhost:27017/Rabaab";

// Schema definition
const studentSchema = new mongoose.Schema({
  name: String,
  age: Number,
  rollno: Number
},{versionKey:false});

// Model (collection: studentdetails)
const Student = mongoose.model("K23PB", studentSchema);

async function main() {
  try {
    // Connect to MongoDB
    await mongoose.connect(url);
    console.log("Connected to MongoDB using Mongoose");

    // Insert document
    const result = await Student.create({
      name: "Rohan12",
      age: 22,
      rollno: 45
    });

    console.log("Document inserted:", result._id);

  } catch (err) {
    console.error("Error:", err);
  } finally {
    // Close connection
    await mongoose.connection.close();
  }
}

main();
