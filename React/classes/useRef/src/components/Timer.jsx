import { useRef } from 'react'

const Timer = () => {
  const countRef = useRef(0);

  const increment = () => {
    countRef.current += 1;
    console.log("Count Ref:", countRef.current);
  };
  return <><button onClick={increment}>Increment</button>
  <h1>Timer: {countRef.current}</h1>
  </>;
};

export default Timer;
