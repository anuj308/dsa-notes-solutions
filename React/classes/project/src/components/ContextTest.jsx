import { useContext } from 'react'
import { AppContext } from '../context/appContext'

const ContextTest = () => {
    const { course, student } = useContext(AppContext)
  return (
    <div>
      <h1>Course: {course}</h1>
      <h1>Student: {student}</h1>
    </div>
  )
}

export default ContextTest
