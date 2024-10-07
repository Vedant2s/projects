import React from "react";
import ProductCard from "./ProductCard";
function ProductGrid() {
  return (
    <>
      <div className="grid grid-cols-2  md:grid-cols-3 xl:grid-cols-4 gap-2">
        <ProductCard list={false} />
      </div>
    </>
  );
}

export default ProductGrid;
