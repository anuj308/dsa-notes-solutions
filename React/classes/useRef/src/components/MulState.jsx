import React from 'react'
import useMulState from '../hooks/useMulState'
const MulState = () => {
    const {count,setCount,name,setName} = useMulState({iCount:6,iName:"anuj"});
    const countHandler = (e)=>{
        setCount(e.target.value);
    }
    const nameHandler = (e)=>{
        setName(e.target.value);
    }
  return (
    <div>
      {count} {name}

      <input value={count} type="number" onChange={(e)=> countHandler(e)}/>
      <input value={name} type="text" onChange={(e)=> nameHandler(e)}/>
    </div>
  )
}

export default MulState
