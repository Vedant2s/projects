import React, { useState, useContext } from "react";
import CartContext from "../../contexts/CartContext";
function ProductSearch() {
  const handleSubmit = (e) => {
    e.preventDefault();
    setSearchTerm(searchItem);
  };
  const { setSearchTerm } = CartContext();
  const [searchItem, setSearchItem] = useState("");
  return (
    <>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          onChange={(e) => setSearchItem(e.target.value)}
          className="outline-none  p-2 border-2 border-black rounded-md"
        />
        <button
          type="submit"
          className="ml-2 p-2 bg-blue-500 text-white rounded-md"
        >
          Search
        </button>
      </form>
    </>
  );
}

export default ProductSearch;
