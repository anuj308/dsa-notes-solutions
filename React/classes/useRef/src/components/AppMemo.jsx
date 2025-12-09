import React,{useMemo, useState} from 'react'

const AppMemo = () => {
    const [num,setNum] = useState(0);
    const [text,setText] = useState('');
    const square = useMemo(()=>{
        console.log('Calculating square...');
        return num * num;
    },[num]);
  return (
    <div>
      <p>Square: {square}</p>
      <button onClick={()=>setNum((n)=>n+1)}>+</button>
      <input type="text" value={text} onChange={(e)=>setText(e.target.value)} placeholder="Type something"/>
    </div>
  )
}

export default AppMemo
