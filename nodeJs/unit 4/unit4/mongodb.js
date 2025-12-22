import {MongoClient} from 'mongodb';

// MongoDB URL (local)
const url = "mongodb://localhost:27017";

// Database name
const dbName = "Rabaab";

// Create client
const client = new MongoClient(url);

async function main() {
    try {
      // Connect to MongoDB
      await client.connect();
      console.log("Connected to MongoDB");
  
      // Select DB
      const db = client.db(dbName);
  
      // Select collection
      const student = db.collection("studentdetails");
    //    Example: Insert data
    const result = await student.insertOne({
        name: "Rohan",
        age: 22,
        rollno: 45
      });
  
      console.log("Document inserted:", result.insertedId);
  
    } catch (err) {
      console.error("Error:", err);
    } finally {
      // Close connection
      await client.close();
    }
  }
  
  main();



