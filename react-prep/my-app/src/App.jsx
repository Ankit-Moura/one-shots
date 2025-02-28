import ToggleBtn from "./components/toggleBtn";
import { ThemeProvider } from "./themeProvider";

export default function app(){

  return <>
    <h1>hey its a react functional component!!!</h1>
    <ThemeProvider>
      <ToggleBtn/>
    </ThemeProvider>
  </>
}

