import React from "react";
import white from "../../assets/images/white.png";
import { Link } from "react-router-dom";
function Navbar() {
  return (
    <div className="z-20 grid grid-cols-4 w-screen bg-white border-solid border-b-4 border-b-red-500 h-20 items-center sticky top-0">
      <div className="flex justify-start pl-4">
        <img src={white} alt="logo" className="xl:h-14 md:h-9 h-5" />
      </div>
      <div className="flex justify-center">
        <Link to="/" className="px-4">
          Home
        </Link>
      </div>
      <div className="flex justify-center">
        <Link to="/cart" className="px-4 ">
          Cart
        </Link>
      </div>
      <div className="flex justify-center">
        <Link to="/about" className="px-4 pr-10">
          About
        </Link>
      </div>
    </div>
  );
}

export default Navbar;
