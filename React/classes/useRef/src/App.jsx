
import './App.css'
import Counter from './components/Counter'
import InputFocus from './components/InputFocus'
import Timer from './components/Timer'
import AppMemo from './components/AppMemo'
import CounterWithHook from './components/CounterWithHook'

function App() {
  return (
    <>
     <Timer />
     <InputFocus/>
     <Counter />
     <AppMemo />
     <CounterWithHook/>
    </>

  )
}

export default App
