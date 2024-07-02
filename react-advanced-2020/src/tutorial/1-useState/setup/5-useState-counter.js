import React, { useState } from "react";

const UseStateCounter = () => {
  const [value, setValue] = useState(0);
  return (
    <React.Fragment>
      <h2>Regular counter</h2>
      <h2>{value}</h2>
      <button className="btn" onClick={() => setValue(value - 1)}>
        Decrease
      </button>
      <button className="btn" onClick={() => setValue(value + 1)}>
        Increase
      </button>
      <button
        className="btn"
        onClick={() => {
          setValue(0);
        }}
      >
        Reset
      </button>
      <button
        className="btn"
        onClick={() => {
          setTimeout(() => {
            // setValue(value + 1);
            setValue((prevState) => {
              return prevState + 1;
            });
          }, 2000);
        }}
      >
        Increase later
      </button>
    </React.Fragment>
  );
};

export default UseStateCounter;
