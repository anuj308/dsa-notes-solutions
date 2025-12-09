import React,{useCallback, useState} from 'react'

const Counter = () => {
    const [count, setCount] = useState(0);
    const increment = useCallback(()=>{
        setCount((c)=>c+1);
    },[])
    // how much improvement with useCallback here?
    // In this simple example, the performance improvement from using useCallback is likely negligible.
    // However, in more complex components with multiple re-renders or expensive computations, 
    // useCallback can help optimize performance by preventing unnecessary re-creations of functions.   
    // like in case of passing this increment function to child components as props.    
    // then useCallback helps to avoid unnecessary re-renders of those child components.
    // means useCallback is more beneficial when dealing with complex components or when passing functions as props to child components.
    // explain more how it helps in avoiding unnecessary re-renders of child components?    
    // so if i have two child componets with same button to increment i pass the fucntion as props to both
    // without useCallback each time parent re-renders new function is created and passed to both child components
    // so both child components re-render even if their props didn't change
    // with useCallback the increment function is memoized and only recreated if its dependencies change
    // so when parent re-renders the same function reference is passed to both child components
    // preventing unnecessary re-renders of those child components if their props remain unchanged
  return (
    <div>
      <p>Count: {count}</p>
        <button onClick={increment}>Increment</button>
    </div>
  )
}

export default Counter
