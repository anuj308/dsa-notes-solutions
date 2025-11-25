import React,{useEffect} from 'react'

const DigitalClock = () => {
    const [time,setTime] = React.useState(new Date());
    
    useEffect(()=>{
        const timerID = setInterval(()=>{
            setTime(new Date());
        },1000);
        return () => clearInterval(timerID);
    },[]);
  return (
    <div>
      {time.toLocaleTimeString()}
    </div>
  )
}

export default DigitalClock
