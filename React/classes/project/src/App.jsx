import './App.css'
import Greet from './components/greet'
import i1 from './assets/i1.png'
import i2 from './assets/i2.png'
import Car from './components/Car'
import User from './components/User'
import { useState } from 'react'
import Student from './components/Student'
import ClassComponent from './components/ClassComponent'
import Output from './components/SuperOutputProps'
import Event from './components/EventClass'
import LifeCycleDemo from "./components/LifeCycleDemo"
import State from './components/State'
import StateSt from './components/StateSt'
import DigitalClock from './components/DigitalClock'
import Timer from './components/Timer'
import { AppContext } from './context/appContext'
import ContextTest from './components/ContextTest'
function App() {
  const [users,setUsers] = useState([
    {username:"asd",country:"India",email:"asda"},
    {username:"asd",country:"India",email:"asda"},
  ])
  const [hobbies,setHobbies] = useState([
"chess","watching web series","finance" ,"geopolitics"
  ])
  const students = [{name:"aks",marks:22},{name:"mohit",marks:40}]
  return (
    <>
      {/* <Greet time="pm" val={2} age={128}/> */}
      {/* <Car model="tata" brand="nexon"/>
      <Car model="tata" brand="harrier"/>
      <User username="Asda" country="India" email="aks.web" /> */}
      {/* users. */}
      {/* <div className='imageClass'>
        <img src={i1}/>
        <img src={i2}/>

      </div>

      <table className='tableClass'>
        <tr><th>1</th><th>select</th><th></th></tr>
        <tr><tb>2</tb><tb>joins</tb><tb></tb></tr>
        <tr><tb>3</tb><tb>sub query</tb><tb></tb></tr>
        <tr><tb>4</tb><tb>windows function</tb><tb></tb></tr>
      </table> */}

      {/* <App/> */}
{/* jansdlansmd
      {users.map((u,index)=>{
      return (
        <div key={index}>
          <div>{u.email}</div>
          <div>{u.country}</div>

        </div>)
      })}
      {hobbies.map((h)=>{h})}
      {hobbies.map((h,index)=>
      {
        return (
          <div key={index}>
           {index+1} {h} 
        </div>
        )
      })}
      {students.map((st,index)=>{
        return (
          <div key={index}>

          <Student name={st.name} marks={st.marks}/>
          </div>
        )
      })}
      <ClassComponent name="anuj"/>
      <Output name="anuj" /> */}
      {/* <div className='bg-black text-white p-3 m-3'>
        Hello world with tailwind
      </div> */}
      {/* <Event/> */}
      {/* <LifeCycleDemo/> */}
      <State/>
      <StateSt/>
      <DigitalClock/>
      <Timer/>
      <AppContext.Provider value={{course: "React Basic", student:"User1"}}>
        <ContextTest/>
      </AppContext.Provider>
    </>
  )
}

export default App
