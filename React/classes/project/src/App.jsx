import './App.css'
import Greet from './components/greet'
import i1 from './assets/i1.png'
import i2 from './assets/i2.png'

function App() {
  
  return (
    <>
      <Greet />
      <div className='imageClass'>
        <img src={i1}/>
        <img src={i2}/>

      </div>

      <table className='tableClass'>
        <tr><th>1</th><th>select</th><th></th></tr>
        <tr><tb>2</tb><tb>joins</tb><tb></tb></tr>
        <tr><tb>3</tb><tb>sub query</tb><tb></tb></tr>
        <tr><tb>4</tb><tb>windows function</tb><tb></tb></tr>
      </table>

      {/* <App/> */}
    </>
  )
}

export default App
