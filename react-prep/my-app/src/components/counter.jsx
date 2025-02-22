import { useState } from "react";
export default function Counter(){
    const [count , setCount] = useState(0);
    const inc = ()=>{
            setCount(count + 1);
    }
    const desc = ()=>{
        setCount(count - 1);
    }

    return(
        <>
            <h3>{count}</h3>
            <button onClick={inc}>increase counter</button>
            <button onClick={desc}>decrease counter</button>
        </>
    )
}