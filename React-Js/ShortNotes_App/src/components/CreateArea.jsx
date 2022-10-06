import React from "react";
import AddIcon from '@material-ui/icons/Add';

function CreateArea(props) {
  return (
    <div>
      <form>
        <input 
          onChange={props.setValues} 
          value={props.title}
          name="title" 
          placeholder="Title" />
        <textarea 
          onChange={props.setValues} 
          value={props.content}
          name="content" placeholder="Take a note..." rows="3" />
        <button style={{cursor:"pointer"}} onClick={props.newNote}>
          <AddIcon />
        </button>
      </form>
    </div>
  );
}

export default CreateArea;
