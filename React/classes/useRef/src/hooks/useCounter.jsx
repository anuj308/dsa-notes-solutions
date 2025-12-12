import {useCallback,useState } from 'react'

const useCounter = (initialValue=0) => {
    const [count, setCount] = useState(initialValue);

    const increment = useCallback(()=>{
        setCount(prev => prev+1);
    },[])

    const decrement = useCallback(()=>{
        setCount(prev => prev-1);
    },[])
  return { count, increment, decrement };
}

export default useCounter
