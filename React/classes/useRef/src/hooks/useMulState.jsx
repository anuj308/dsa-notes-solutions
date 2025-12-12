import { useState } from 'react'

const useMulState = ({iCount,iName}) => {
    const [count,setCount] = useState(iCount);
    const [name,setName] = useState(iName);
  return {count,setCount,name,setName};
}

export default useMulState
