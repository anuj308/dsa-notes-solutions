import React from 'react'
import { Link } from 'react-router-dom'

const Home = () => {
  return (
    <div>
      Home
      <Link to="/about">About</Link>
      <Link to="/products">Product</Link>
      <Link to="/products?category=mobile">Mobile Products</Link>
    </div>
  )
}

export default Home
