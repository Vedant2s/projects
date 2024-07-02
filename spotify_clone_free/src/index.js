import React from "react";
// import ReactDOM from "react-dom";
import "./index.css";
import App from "./App.jsx";
import { StateProvider } from "./utils/StateProvider";
import reducer, { initialState } from "./utils/reducer";
import { createRoot } from "react-dom/client";
// App.exports = global.process;
const root = createRoot(document.getElementById("root"));
root.render(
  <StateProvider initialState={initialState} reducer={reducer}>
    <App />
  </StateProvider>
);
