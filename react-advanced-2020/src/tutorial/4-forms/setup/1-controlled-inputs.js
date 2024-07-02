import React, { useState } from "react";
// JS
// const input = document.getElementById('myText');
// const inputValue = input.value
// React
// value, onChange

const ControlledInputs = () => {
  const [firstName, setFirstName] = useState("");
  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(firstName);
  };
  return (
    <>
      <article>
        <form className="form" onSubmit={handleSubmit}>
          <div className="form-control">
            <label htmlFor="firstName">Name :</label>
            <input
              type="text"
              id="firstName"
              name="firstName"
              onChange={(e) => setFirstName(e.target.value)}
            ></input>
          </div>
          <div className="form-control">
            <label htmlFor="email">Email :</label>
            <input type="text" id="email" name="email"></input>
          </div>
          <button type="submit">add person</button>
        </form>
      </article>
    </>
  );
};

export default ControlledInputs;
