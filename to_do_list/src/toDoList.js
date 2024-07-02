import React, { useState, useEffect } from "react";
import data from "./data";
import "./ToDoList.css";

const ToDoList = () => {
  // Initialize list from local storage or fallback to default data
  const initialList = JSON.parse(localStorage.getItem("todoListData")) || data;
  const [list, setList] = useState(initialList);
  const [task, setTask] = useState("");
  const [isSortedByTask, setIsSortedByTask] = useState(false);

  useEffect(() => {
    // Save list to local storage whenever it changes
    localStorage.setItem("todoListData", JSON.stringify(list));
  }, [list]);

  const removeItem = (id) => {
    const newList = list.filter((item) => item.id !== id);
    setList(newList);
  };

  const markItem = (id) => {
    const newList = list.map((item) => {
      if (item.id === id) {
        return {
          ...item,
          status: item.status === "Complete" ? "Incomplete" : "Complete",
        };
      }
      return item;
    });
    setList(newList);
  };

  const handleTask = (e) => {
    e.preventDefault();
    if (task) {
      const newItem = {
        id: Date.now(), // Use the current date and time in number format
        username: "Admin",
        toDo: task,
        status: "Incomplete",
      };
      setList([...list, newItem]);
      setTask("");
    } else {
      alert("Please add a task before submitting");
    }
  };

  const sortList = () => {
    let newList;
    if (isSortedByTask) {
      // If currently sorted by task, sort by ID
      newList = [...list].sort((a, b) => a.id - b.id);
    } else {
      // If not sorted by task, sort by task
      newList = [...list].sort((a, b) => {
        if (a.toDo < b.toDo) return -1;
        if (a.toDo > b.toDo) return 1;
        return 0;
      });
    }
    setList(newList);
    setIsSortedByTask(!isSortedByTask); // Toggle the sorting order
  };

  return (
    <div className="App">
      <h1 style={{ color: "red", textAlign: "center" }}>To-Do List</h1>
      <form onSubmit={handleTask}>
        <label htmlFor="toDo">To Do Task</label>
        <input
          type="text"
          className="toDo"
          value={task}
          onChange={(e) => setTask(e.target.value)}
        />
        <button type="submit" style={{ marginLeft: "2%" }}>
          Submit Task to Do
        </button>
      </form>
      <button onClick={sortList} className="btn" style={{ marginLeft: "2%" }}>
        {isSortedByTask ? "Sort by ID" : "Sort by Task"}
      </button>
      <br />
      <br />
      {list.map((item) => {
        const { id, username, toDo, status } = item;
        return (
          <div key={id} className="item">
            <h3>Username: {username}</h3>
            <h2>Task: {toDo}</h2>

            {status === "Complete" && (
              <img
                src="https://image.similarpng.com/very-thumbnail/2021/12/Green-check-mark-on-transparent-background-PNG.png"
                height="17px"
                width="17px"
                alt="tick img"
              />
            )}
            <button className="btn" onClick={() => removeItem(id)}>
              Remove
            </button>
            <br />
            <button className="btn" onClick={() => markItem(id)}>
              {status === "Complete" ? "Mark Incomplete" : "Mark Complete"}
            </button>
          </div>
        );
      })}
      <br />
      <br />
      <br />
    </div>
  );
};

export default ToDoList;
