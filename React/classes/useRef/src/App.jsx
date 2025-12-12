
import './App.css'
import Counter from './components/Counter'
import InputFocus from './components/InputFocus'
import Timer from './components/Timer'
import AppMemo from './components/AppMemo'
import CounterWithHook from './components/CounterWithHook'
import MulState from './components/MulState'
import Q1 from "./components/Q1"
function App() {
  return (
    <>
     <Timer />
     <InputFocus/>
     <Counter />
     <AppMemo />
     <CounterWithHook/>
     <MulState/>
     <Q1/>
    </>

  )
}

export default App
