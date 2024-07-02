import React from "react";
import { createRoot } from "react-dom/client";
import App from "./App";
import "./index.css";
import { ContextProvider } from "./contexts/ContextProvider";
const root = createRoot(document.getElementById("root"));
root.render(
  <ContextProvider>
    <App />
  </ContextProvider>
);
