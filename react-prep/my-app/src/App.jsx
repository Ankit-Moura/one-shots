import PersonCard from "./components/personCard"
import Counter from "./components/counter"
import ToggleBtn from "./components/toggleBtn"
import TitleBar from "./components/tittlebar"
import RefExample from "./components/refEg"
export default function app(){
  return <>
    <h1>hey its a react functional component!!!</h1>
    <Counter/>
    <ToggleBtn/>
    <RefExample/>
    <PersonCard age="22" name="ankit" />
    <PersonCard age="23" name="joe" />
    <PersonCard age="24" name="roe" />
    <TitleBar/>
  </>
}
