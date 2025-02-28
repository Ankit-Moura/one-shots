// import { useContext } from "react";
// import { ThemeContext } from "../themeProvider";

import { useContext } from "react";
import { ThemeContext } from "../themeProvider"; // ✅ Correct import

export default function ToggleBtn(){
    // const {isDarkMode, toggleTheme} = useContext(ThemeContext)    
    const { isDarkMode, toggleTheme } = useContext(ThemeContext); // ✅ Correct unpacking  
    return(
        <>
            {/* <h2>theme state : {isDarkMode}</h2> */}
            {/* <button onClick={toggleTheme}>toggle btn</button> */}
            <h2>Theme state: {isDarkMode ? "Dark Mode 🌙" : "Light Mode ☀️"}</h2>
            <button onClick={toggleTheme}>Toggle Theme</button>
        </>
    )
}