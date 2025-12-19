import React,{useEffect, useRef, useState} from "react";

const Form = () => {
  const [successMesssage, setSuccessMessage] = useState("");
  const [formData,setFormData] = useState({
    name:"",
    email:"",
    password:"",
    age:"",
  })
  const fileRef = useRef();
  const [errors,setErrors] = useState({});
  const validate = ()=>{
    const errors = {};

    if(!formData.name.trim()) errors.name = "Full name is required"
    if(!formData.email.includes("@")) errors.email = "Enter a valid email"
    if(formData.password.length < 6 ) errors.password = "Password must be at least 6 characters"
    return errors;
  }

  const onChangeHandler = (e)=>{
    const name = e.target.name;
    const value = e.target.value;
    setFormData((prev)=> ({ ...prev, [name]: value }));
  }

  const handleSubmit = async (e)=>{
     e.preventDefault();
     const validationErrors = validate();
     if(Object.keys(validationErrors).length > 0){
         setErrors(validationErrors);
         setSuccessMessage("");
         return;
     }

     const fileData = fileRef.current.files[0];
     try {
      const response = await fetch("http://jsonplaceholder.typicode.com/users",
        {
          method: "POST",
          headers: { "Content-Type" : "application/json"},
          body: JSON.stringify(formData)
        }
      )
      const data = await response.json();
      console.log("post response",data)
      setErrors({})
      setSuccessMessage("Registration Successful!")
     } catch (error) {
        console.error("POST ERROR",error)
     }
  }
  const getUsers = async ()=>{
    try {
      const response = await fetch("https://jsonplaceholder.typicode.com/users")
      const data = await response.json();
      // setUsers(data);
      setSuccessMessage("Users fetched successfully");
      console.log("get response",data)
    } catch (error) {
      console.error("get error",error)
    }
  }

  const deleteUsers = async (id)=>{
    try {
      const response = await fetch(`https://jsonplaceholder.typicode.com/users/${id}`,
        {
          method: "Delete",
          headers: { "Content-Type" : "application/json"},
        }
      )
      setSuccessMessage("Users deleted successfully");
      console.log("delete response user id ", id)
    } catch (error) {
      console.error("delete users",error)
    }
  }
  const putUsers = async (id,data)=>{
    try {
      const response = await fetch(`https://jsonplaceholder.typicode.com/users/${id}`,
        {
          method: "Put",
          headers: { "Content-Type" : "application/json"},
          body: data
        }
      )
      setSuccessMessage("Users updated successfully");
      console.log("put response",data)
    } catch (error) {
      console.error("put users",error)
    }
  }

  useEffect(()=>{
    getUsers()
    deleteUsers(2);
    putUsers(1,formData);
  },[])
   
  return (
    <div>
      <div className="text-2xl font-bold">Register Account</div>
      <div
        className={`bg-green-400 p-4 m-3 rounded-2xl ${
          successMesssage.length > 0 ? "" : "hidden"
        }`}
      >
        {successMesssage}
      </div>
      <form className="m-3" onSubmit={handleSubmit}>
        <div>Full Name</div>
        <div>
            {errors.name && (<p className="p-1 text-red-400 ">errors.name</p>)}
          <input type="text" name="name" value={formData.name} onChange={onChangeHandler} className="border rounded-sm" />
        </div>
        <div>Email</div>
        <div>
            {errors.email && (<p className="p-1 text-red-400 ">errors.email</p>)}
          <input type="email" name="email" value={formData.email} onChange={onChangeHandler} className="border rounded-sm" />
        </div>
        <div>Password</div>
        <div>
            {errors.password && (<p className="p-1 text-red-400 ">errors.password</p>)}
          <input type="password" name="password" value={formData.password} onChange={onChangeHandler} className="border rounded-sm" />
        </div>
        <div>Age</div>
        <div>
          <input type="Number" name="age" value={formData.age} onChange={onChangeHandler} className="border rounded-sm" />
        </div>
        <div>Profile Photo</div>
        <div>
          <input type="file" name="profilePhoto" ref={fileRef}  />
        </div>
        <input
          type="submit"
          className="bg-blue-700 p-3 m-3 rounded-2xl w-70"
        />
      </form>
    </div>
  );
};

export default Form;
