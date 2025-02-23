import { useState, useRef } from "react";

export default function StopWatch(){
    const [laps, setLaps] = useState([]);
    const [time, setTime] = useState(0);
    const timerRef = useRef(null);
    const [isRunning, setIsRunning] = useState(false);
    const startTimer = () => {
        if (!timerRef.current) { // ✅ Prevent multiple intervals
            setIsRunning(true);
            timerRef.current = setInterval(() => {
                setTime(prevTime => {
                    return prevTime + 1
                });
            }, 1000);
        }
    };
    

    const stopTimer = ()=>{
        clearInterval(timerRef.current);
        timerRef.current = null;
        setIsRunning(false);
    }
    const resetTimer = ()=>{
        stopTimer();
        setTime(0);
        setLaps([]);
    }

    const handleTimerClick = ()=>{
        if(isRunning){
            stopTimer();
            return;
        }
        if(!isRunning){
            startTimer();
            return;
        }

    }

    const handleLapClick = () =>{
    console.log(`lap: ${time}`)
    console.log(laps);
        setLaps(laps=>[...laps, time])
    }

    return(
        <>
        <h2>⏱ Time: {time} sec</h2>
        {laps.map((lap, index)=>{
            return <h3 key={index}>lap {index + 1}: {lap}</h3>
        })}
        <button onClick={handleTimerClick}>{isRunning? "Stop": "Start"}</button>
        <button onClick={handleLapClick}>Lap</button>
        <button onClick={resetTimer}>Reset</button>
    </>
    )
}