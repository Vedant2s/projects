import React, { useState } from "react";

let clicks = 0;
const UseStateBasics = () => {
  const [text, setText] = useState("random title");
  const handleClick = () => {
    // if (text === "random title") setText("Hello people");
    // else setText("random title");
    clicks++;
    setText("clicks: " + clicks);
  };
  return (
    <React.Fragment>
      <h1>{text}</h1>
      <button type="button" className="btn" onClick={handleClick}>
        Change title
      </button>
    </React.Fragment>
  );
};

export default UseStateBasics;
