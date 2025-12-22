import mongoose from "mongoose";

async function main() {
  await mongoose.connect("mongodb://127.0.0.1:27017/ABX");

  const studentSchema = new mongoose.Schema(
    {
      name: String,
      age: Number,
      rollno: Number
    }
  );

  const Student = mongoose.model("K23PB", studentSchema);

  // CREATE
    // await Student.create({ name: "Rabaab", age: 22, rollno: 101 });

  // READ
//  console.log(await Student.find());

//   // UPDATE
  // await Student.findOneAndUpdate({ rollno: 101 }, { age: 23 });
//   // READ
//     console.log(await Student.find());

//   // DELETE
   await Student.findOneAndDelete({ age:22 });
// // READ
// console.log(await Student.find());

  await mongoose.connection.close();
}

main();
