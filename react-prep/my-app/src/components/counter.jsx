import { useState } from "react";
export default function Counter(){
    console.log("component re-rendered");
    const [count , setCount] = useState(0);
    const inc = ()=>{
            setCount(count + 1);
            setCount((prev)=>prev + 1);
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