import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import ProductDetails from './pages/ProductDetails'
import Products from './pages/Products'
import About from './pages/About'
import Home from './pages/Home'
import { Route,Routes } from 'react-router-dom'

function App() {

  return (
    <>
      <Routes>
        <Route path="/" element={<Home/>}/>
        <Route path="/about" element={<About/>}/>
        <Route path="/products" element={<Products/>}/>
        <Route path="/product/:id" element={<ProductDetails/>}/>

      </Routes>
    </>
  )
}

export default App
