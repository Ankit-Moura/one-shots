import { useState, useRef, useEffect } from "react";

export default function RefExample() {
    const [count, setCount] = useState(0);
    const renderCount = useRef(1);

    useEffect(() => {
        renderCount.current += 1;
        console.log(`state: ${count}`);
        console.log(`ref: ${renderCount.current}`);
    });

    return (
        <>
            <h2>Count: {count}</h2>
            <h3>Component rendered: {renderCount.current} times</h3>
            <button onClick={() => setCount(count + 1)}>Increase</button>
        </>
    );
}
