import React from 'react'

const Timer = () => {
    const [time,setTime] = React.useState(0);
    const [TimerAction,setTimerAction] = React.useState("stopped");

    function setTimer(time){
        setTime(time)
    }
    function stopTimer(){
        setTimerAction("stopped")
        setTime(0)
    }
    function pauseTimer(){
        // logic to pause timer
        setTimerAction("paused")
        setTime((prevTime)=> prevTime)
    }
    function startTimer(){
        // logic to start timer
        const id = setInterval(()=>{
            setTime((prevTime)=> prevTime - 1)
        },1000)
        if(time<=0){
            clearInterval(id)
        }
    }
  return (
    <div>
      <div>set time {time}</div>
      <div ><input type="number" onChange={(e) => setTimer(e.target.value)} /></div>
      <div onClick={stopTimer}>stop timer</div>
      <div onClick={pauseTimer}> pause timer</div>
      <div onClick={startTimer}>start timer</div>
    </div>
  )
}

export default Timer
