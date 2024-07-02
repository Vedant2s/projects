import React, { useState } from "react";
import { data } from "./data";
// import App from "../App";
import "../App.css";
// import ReactDOM from "react-dom/client";
import Root from "../index";
import ToDoList from "../toDoList";
function Login() {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  //   const [route, setRoute] = useState(false);
  const handleSubmit = (e) => {
    e.preventDefault();
    // addUser({ username, password });
    console.log(data); // You should see the updated data array here
    data.forEach((use) => {
      if (use.username === username && use.password === password) {
        console.log("Successfull login");
        // usew = use.username;
        //   const root = ReactDOM.createRoot(document.getElementById("root"));
        Root.render(
          <React.StrictMode>
            {/* <App /> */}
            <ToDoList />
          </React.StrictMode>
        );
      }
    });
  };

  return (
    <React.Fragment>
      {/* <img
        src="https://t4.ftcdn.net/jpg/01/19/11/55/360_F_119115529_mEnw3lGpLdlDkfLgRcVSbFRuVl6sMDty.jpg"
        className="background"
        alt="nope"
        width={"100%"}
        height={"100%"}
      ></img> */}
      <form onSubmit={handleSubmit}>
        <div className="divCenter">
          <label htmlFor="username">Username</label>
          <input
            type="text"
            name="username"
            id="username"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
          ></input>
        </div>
        <div className="divCenterBelow">
          <label htmlFor="password">Password</label>
          <input
            type="text"
            name="password"
            id="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
          ></input>
        </div>
        <button type="submit" className="btnlogin">
          Verify
        </button>
        <p>Username is "Admin" & password is "Er"</p>
      </form>
    </React.Fragment>
  );
}

export default Login;
