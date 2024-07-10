import React, { useContext } from "react";
import { FaBars } from "react-icons/fa";
import { useGlobalContext } from "./context";
const Home = () => {
  const context = useGlobalContext();
  const { openModal, openSidebar } = useGlobalContext();
  console.log(context);
  return (
    <main>
      <button className="sidebar-toggle" onClick={openSidebar}>
        <FaBars />
      </button>
      <button className="btn" onClick={openModal}>
        show modal
      </button>
    </main>
  );
};

export default Home;
