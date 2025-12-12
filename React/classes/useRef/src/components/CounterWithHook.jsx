import React from 'react'
import useCounter from '../hooks/useCounter'

const CounterWithHook = () => {
    const {increment,decrement,count} = useCounter(0);
  return (
    <div>
      {count}
      <button onClick={()=> increment()}>+</button>
      <button onClick={()=> decrement()}>-</button>
    </div>
  )
}

export default CounterWithHook
