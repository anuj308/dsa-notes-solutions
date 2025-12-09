import React,{useRef} from 'react'

const InputFocus = () => {
    const inputRef = useRef(null);
    const focusInput = () => {
        inputRef.current.focus();
    }
  return (
    <div>
      <input ref={inputRef} type="text"/>
      <button onClick={focusInput}>Focus Input</button>
    </div>
  )
}
// inputRef.current becomes the input DOM element
// clicking the button calls focusInput function which focuses the input field

export default InputFocus
