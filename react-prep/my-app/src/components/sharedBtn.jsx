export default function SharedBtn({count, setCount}){
    return(<>
        <h2>Count: {count}</h2>
       <button onClick={()=>setCount(prev=>prev+1)}>Click me!!!!</button>
    </>)
}