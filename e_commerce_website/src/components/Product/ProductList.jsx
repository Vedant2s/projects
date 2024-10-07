import React from "react";
import ProductCard from "./ProductCard";
function ProductList() {
  return (
    <>
      <div className="grid grid-cols-1 gap-2">
        <ProductCard list={true} />
      </div>
    </>
  );
}

export default ProductList;
