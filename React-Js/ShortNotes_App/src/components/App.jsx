import React, { useState } from "react";
import Header from "./Header";
import Footer from "./Footer";
import Note from "./Note";
import CreateArea from "./CreateArea";

function App() {
  const [allNotes, setAllNotes] = useState([]);
  const [inputText, setInputText] = useState({
    title:"",
    content:""
  });
  function setValues(e){
    const {name, value} = e.target;
    setInputText({...inputText, [name]:value});
  }
  function addNewNotes(event){
    if(inputText.title.length !==0 && inputText.content.length !==0){
      setAllNotes([...allNotes, inputText]);
      setInputText({title:"", content:""});
    }
    else if(inputText.title.length ===0){
      alert("Please enter the title of the note!!!");
    }else{
      alert("Please enter the content of the note....");
    }
    event.preventDefault();
  }
  function deleteNote(id){
    setAllNotes(allNotes.filter((eachNote, index)=> index!==id));
  }

  return (
    <div>
      <Header />
      <CreateArea 
        setValues={setValues}
        title={inputText.title}
        content={inputText.content}
        newNote={addNewNotes} />
      {allNotes.map((eachNote, index)=>{
        return (
          <Note key={index} id={index} 
            title={eachNote.title} 
            content={eachNote.content} delete={deleteNote}/>
        );
      })}
      <Footer />
    </div>
  );
}

export default App;
