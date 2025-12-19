import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Form from './component/Form'
import FormWithAxios from './component/FormWithAxios'

function App() {
  
  return (
    <>
      <Form/>
      <FormWithAxios/>
    </>
  )
}

export default App
