import { useState, useEffect } from "react";

export default function TitleBar(){
    const [pageNumber, setPageNumber] = useState(0);
    const inc = ()=>{
        setPageNumber(prev=>prev+1);
    }
    useEffect(() => {
        console.log(`Updating title: Page ${pageNumber}`);
        document.title = `Page: ${pageNumber}`;
    }, [pageNumber]);   
    return(
        <>
            <button onClick={inc}>Turn page</button>
        </>
    )
}