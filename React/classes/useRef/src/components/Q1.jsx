import React, { useEffect, useState } from 'react'

const Q1 = () => {
    const [data,setData] = useState([])
    useEffect(()=>{
        // function for api call
        setData([{id:1,name:"aa"},{id:2,name:"22"}]);
    },[])
  return (
    <div>
      {data.map((da)=>{
        return (
            <div key={da.id}>
                {da.id}
                {da.name}
            </div>
        )
      })}
    </div>
  )
}

export default Q1
