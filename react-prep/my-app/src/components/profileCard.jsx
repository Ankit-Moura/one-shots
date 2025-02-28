import { useState, useEffect } from "react";

export default function DarkModeToggle() {
    const [isDarkMode, setIsDarkMode] = useState(false);
    document.body.style.color = isDarkMode ? "white" : "black";
    // useEffect(() => {
    //     document.body.style.background = isDarkMode ? "black" : "white";
        
    // }, [isDarkMode]); // Runs whenever isDarkMode changes

    return (
        <>
            <h2>{isDarkMode ? "Dark Mode 🌙" : "Light Mode ☀️"}</h2>
            <button onClick={() => setIsDarkMode(prev => !prev)}>
                Toggle Mode
            </button>
        </>
    );
}
