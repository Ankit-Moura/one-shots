import { useState } from "react";

export default function ToggleBtn(){
    const [btn, setBtn] = useState(0);
    const toggle = ()=>{
        setBtn(prevState=>prevState==0?1:0);
    }
    return(
        <>
            <h2>btn state : {btn}</h2>
            <button onClick={toggle}>toggle btn</button>
        </>
    )
}