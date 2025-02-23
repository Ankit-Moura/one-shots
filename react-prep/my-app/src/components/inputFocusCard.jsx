import { useRef, useEffect } from "react";

export default function InputFocus() {
    const inputRef = useRef(null); // 🔹 Create a ref for the input
    const btnRef = useRef(null);
    useEffect(() => {
        inputRef.current.focus(); // ✅ Focus the input on mount
    }, []);
    const handleClick = ()=>{
        btnRef.current.textContent = "clicked";
    }
    return (
        <>
            <input ref={inputRef} type="text" placeholder="Type something..." />
            <button ref={btnRef} onClick={handleClick}>click me </button>
        </>
    );
}
