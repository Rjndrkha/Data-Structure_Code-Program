import {createStore} from 'redux'

const reducerfn = (state={counter:100},action) => {
    if(action.type==='INC')
    {
        return {counter:state.counter+1}
    }
    else if(action.type==='DEC')
    {
        return {counter:state.counter-1}
    }
    else if(action.type === 'ADD')
    {
        return {counter:state.counter+ action.payload}
    }
    else if(action.type === 'SUB')
    {
        return {counter:state.counter - action.payload}
    }
    return state;
}
const store = createStore(reducerfn);
export default store;