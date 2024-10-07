import React, { useEffect, useState } from "react";
import { useParams } from "react-router-dom";
import useCartContext from "../../contexts/CartContext";

function ProductDetails() {
  const { Oproducts } = useCartContext();
  const { id } = useParams();
  const [itemDetails, setItemDetails] = useState(null);

  useEffect(() => {
    // Clean up the id by removing any unnecessary characters
    const cleanId = id.replace(/^[\s:]+/, "").trim();
    const foundItem = Oproducts.find((item) => item.asin === cleanId);
    setItemDetails(foundItem);
  }, [Oproducts, id]);

  // Debugging logs
  console.log("Oproducts:", Oproducts);
  console.log("id from useParams:", id);
  console.log("cleanId:", id.replace(/^[\s:]+/, "").trim());
  console.log("itemDetails:", itemDetails);

  if (!itemDetails) {
    return <div>Product not found</div>;
  }

  return (
    <div className="p-8 max-w-4xl mx-auto bg-white rounded-xl shadow-lg overflow-hidden">
      <div className="flex flex-col md:flex-row">
        <div className="md:flex-shrink-0">
          <img
            className="h-96 w-full object-contain md:h-full md:w-96"
            src={itemDetails.product_photo}
            alt={itemDetails.product_title}
          />
        </div>
        <div className="mt-4 md:mt-0 md:ml-8 p-8">
          <h1 className="text-3xl font-bold text-black mb-4">
            {itemDetails.product_title}
          </h1>
          <h2 className="flex items-baseline gap-2 mb-4">
            <p className="line-through text-gray-500 text-xl">
              {itemDetails.product_original_price}
            </p>
            <span className="text-2xl font-semibold text-green-600">
              {itemDetails.product_price}
            </span>
          </h2>
          <h4 className="text-lg text-gray-600 mb-2">
            Rating: {itemDetails.product_star_rating}
          </h4>
          {itemDetails.is_amazon_choice && (
            <h4 className="text-lg text-blue-500 mb-2">Amazon Choice</h4>
          )}
          {itemDetails.climate_pledge_friendly && (
            <h4 className="text-lg text-green-500 mb-2">
              Climate Pledge Friendly
            </h4>
          )}
          {itemDetails.is_prime && (
            <h4 className="text-lg text-purple-500 mb-2">Prime</h4>
          )}
          <h4 className="text-lg text-red-500 mb-2">
            Delivery: {itemDetails.delivery}
          </h4>
          <h4 className="text-lg text-gray-700 mb-2">
            Unit Count: {itemDetails.unit_count}
          </h4>
          <h4 className="text-lg text-gray-700">
            Sales Volume: {itemDetails.sales_volume}
          </h4>
        </div>
      </div>
    </div>
  );
}

export default ProductDetails;
