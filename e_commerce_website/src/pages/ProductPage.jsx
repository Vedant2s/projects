import React, { useState } from "react";
import ProductSearch from "../components/Product/ProductSearch";
import ProductGrid from "../components/Product/ProductGrid";
import ProductList from "../components/Product/ProductList";

function ProductPage() {
  const [isGrid, setIsGrid] = useState(true);

  return (
    <>
      <div className="w-screen flex flex-col md:flex-row relative justify-center items-center">
        <div className="ml-6 py-6 w-full md:w-auto ">
          <ProductSearch />
        </div>
        <button
          className="mt-4 md:mt-0 md:absolute md:right-10 ml-2 p-2 bg-blue-500 text-white rounded-md"
          onClick={() => setIsGrid(!isGrid)}
        >
          {isGrid ? "List view" : "Grid View"}
        </button>
      </div>
      <div className="px-4 py-6">
        {isGrid ? <ProductGrid /> : <ProductList />}
      </div>
    </>
  );
}

export default ProductPage;
