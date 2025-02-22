import PersonCard from "./components/personCard"
import Counter from "./components/counter"
export default function app(){
  return <>
    <h1>hey its a react functional component!!!</h1>
    <Counter/>
    <PersonCard age="22" name="ankit" />
    <PersonCard age="23" name="joe" />
    <PersonCard age="24" name="roe" />
  </>
}
