import React,{useState,useEffect, use} from 'react'

const StateSt = () => {
    const [user,setUser] = useState({name:"aks",age:2})
    function updateAge(){
        setUser((prevUser)=>({
            ...prevUser,
            age:prevUser.age+1
        }))
    }
    useEffect(()=>{
        console.log("user state updated",user)
    },[user])
    useEffect(()=>{
        console.log("no dependencies - runs once on mount")
    },[])
  return (
    <div>
    username: {user.name} <br/>
    age: {user.age} <br/>
    <button onClick={updateAge}>Increase Age</button>
    </div>
  )
}

export default StateSt
