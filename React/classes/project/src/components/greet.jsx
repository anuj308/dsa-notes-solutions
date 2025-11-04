import React from 'react'

const greet = ({time,val,age}) => {
  console.log(time,val)
  return (
    <div >GOOD AFTERNOON {val} {time} {age}</div>
  )
}

export default greet  