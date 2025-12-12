import {useReducer} from 'react'

const reducer = (state, action) => {
  switch(action.type) {
    case 'increment':
      return {count: state.count + 1};
    case 'decrement':
      return {count: state.count - 1};
    default:
      return state;
  }
};

// useReducer is useful for managing complex state logic
// it provides a more structured way to handle state updates compared to useState
// especially when the next state depends on the previous state or when multiple state variables are involved

const useReducerCounter = () => {
    const [state, dispatch] = useReducer(reducer, {count: 0});
  return (
    <div>
      <p>Count: {state.count}</p>
      <button onClick={() => dispatch({type: 'increment'})}>Increment</button>
      <button onClick={() => dispatch({type: 'decrement'})}>Decrement</button>
    </div>
  )
}

export default useReducerCounter