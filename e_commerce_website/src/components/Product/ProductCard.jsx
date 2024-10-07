import React, { useState, useRef, useEffect } from "react";
import CartContext from "../../contexts/CartContext";
import nSearch from "../../assets/images/nSearch.png";
import { Link } from "react-router-dom";

function ProductCard({ list }) {
  const { products, updateCart } = CartContext();
  const amountRefs = useRef([]);

  useEffect(() => {
    amountRefs.current = products.map(() => 0);
  }, [products]);

  const [dummyState, setDummyState] = useState(0); // Dummy state to force re-render

  if (products.length < 1) {
    return (
      <div className="col-span-full flex flex-col justify-center items-center h-full space-y-4">
        <img src={nSearch} alt="logo" className="mb-2 h-20" />
        <h1 className="text-2xl">No products found for your search</h1>
      </div>
    );
  }

  const handleIncrement = (index) => {
    amountRefs.current[index] += 1;
    setDummyState(dummyState + 1); // Update state to trigger re-render
  };

  const handleDecrement = (index) => {
    if (amountRefs.current[index] > 0) {
      amountRefs.current[index] -= 1;
      setDummyState(dummyState - 1); // Update state to trigger re-render
    }
  };

  const handleClick = (id, index) => {
    if (amountRefs.current[index] > 0)
      updateCart(id, amountRefs.current[index]);
    else alert("Please select number of item to be ordered!!");
  };

  return (
    <>
      {products.map((item, index) => {
        const {
          currency,
          asin: id,
          is_amazon_choice: choice,
          product_price: price,
          product_star_rating: rating,
          product_title: title,
          product_photo: image,
        } = item;

        return (
          <div
            key={index}
            className={`${
              !list
                ? "text-center overflow-hidden shadow-md shadow-black pt-3 bg-slate-100"
                : "flex overflow-hidden shadow-md shadow-black p-3 bg-slate-100"
            }`}
          >
            <Link to={`/ProductDetails/:${id}`}>
              <img
                src={image}
                alt={title}
                className="mb-2 h-40 w-40 object-cover"
                style={{ maxWidth: "100px", maxHeight: "100px" }} // Adjusted to max-width and max-height
              />
            </Link>
            <div className={`${list ? "grid-flow-row grid-cols-1 mx-7" : ""}`}>
              <h1
                className={`${
                  list
                    ? "ml-3 text-lg font-bold overflow-hidden text-ellipsis whitespace-nowrap"
                    : "ml-3 text-lg font-bold overflow-hidden text-ellipsis whitespace-nowrap"
                }`}
              >
                {title}
              </h1>
              <h3 className="ml-3 text-base">Rating: {rating}</h3>
              <h4 className="ml-3 text-base">
                Price: {price} {currency}
              </h4>
              <button
                onClick={() => {
                  handleClick(id, index);
                }}
                className="m-2 p-2 bg-blue-500 text-white rounded-md hover:bg-green-400 hover:text-black"
              >
                Select
              </button>
              {amountRefs.current[index]}
              <button
                onClick={() => {
                  handleIncrement(index);
                }}
                className="ml-2 p-2 bg-white border-2 border-black text-black rounded-md cursor-pointer"
              >
                +
              </button>
              <button
                className="ml-1 p-2 bg-white border-2 border-black text-black rounded-md cursor-pointer"
                onClick={() => {
                  handleDecrement(index);
                }}
              >
                -
              </button>
            </div>
          </div>
        );
      })}
    </>
  );
}

export default ProductCard;
