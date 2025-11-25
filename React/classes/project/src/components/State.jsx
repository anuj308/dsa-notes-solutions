import React,{useState} from 'react'

const State = () => {
    const [list,setList] = useState([])
    function addItem(){
        const newItem = `Item ${list.length + 1}`;
        setList([...list, newItem]);
    }
  return (
    <div>
      {list.map((item,index)=>(
        <div key={index}>{item}</div>
      ))}
      <button onClick={addItem}>Add Item</button>
    </div>
  )
}

export default State
