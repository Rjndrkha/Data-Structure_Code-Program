import React, {useState, useEffect, useRef} from 'react'

function TodoForm(props) {
  const[input, setInput] = useState('')

  const inputRef  = useRef(null)
  useEffect(() => {
    inputRef.current.focus()
  })

  const handleChange = e =>{
    setInput(e.target.value);
  };

  const handleSubmit = e =>{
    e.preventDefault();

    props.onSubmit({
      id: Math.floor(Math.random() * 1000000),
      text: input
    });

    setInput('');
  };


  return (
    <form className='todo-form' onSubmit={handleSubmit}>
      <input type ='text' placeholder='Add a ToDo' value={input} name='text' className='todo-input' onChange={handleChange}
      ref={inputRef}
      />
      <button className='todo-button'>Add ToDo</button>
    </form>
  )
}

export default TodoForm
