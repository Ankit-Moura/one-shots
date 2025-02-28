import { useReducer , useRef} from "react";

const reducer = (state, action) => {
    switch (action.type) {
        case "increment":
            return { count: state.count + 1 };
        case "halve":
            return{count: state.count? Math.floor(state.count/2):0};
        case "decrement":
            return { count: Math.max(state.count - 1, 0) };
        case "reset":
            return { count: 0 };
        case "double":
            return {count: state.count? state.count*2: 0}
        case "setUsername":
            return {...state, username: action.payload
            }
        default:
            return state;
    }
};

export default function Counter() {
    const [state, dispatch] = useReducer(reducer, { count: 0, username: "", });

    return (
        <>
            <h2>Counter: {state.count}</h2>
            <button onClick={() => dispatch({ type: "increment" })}>+</button>
            <button onClick={() => dispatch({ type: "decrement" })}>-</button>
            <button onClick={()=> dispatch({type: "double"})}>+2</button>
            <button onClick={()=>dispatch({type: "halve"})}>/2</button>
            <button onClick={() => dispatch({ type: "reset" })} disabled={state.count===0}>Reset</button>
            <h2>Username: {state.username}</h2>
            <input
                type="text"
                value={state.username}
                onChange={(e) => dispatch({ type: "setUsername", payload: e.target.value })}
            />
        </>
    );
}
