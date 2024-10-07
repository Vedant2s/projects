import React, { useEffect, useState, useContext } from "react";
import { data1, amdCpu, intelCpu } from "../assets/data/data";

const AppContext = React.createContext();

const AppProvider = ({ children }) => {
  const [loading, setLoading] = useState(false);
  const [searchTerm, setSearchTerm] = useState("");
  const [products, setProducts] = useState(amdCpu);
  const [filteredProducts, setFilteredProducts] = useState(data1.data.products);
  const [cartItems, setCartItems] = useState(() => {
    // Retrieve the initial state from local storage
    const savedCartItems = localStorage.getItem("cartItems");
    return savedCartItems ? JSON.parse(savedCartItems) : [];
  });

  const fetchDrinks = () => {
    const filtered = products.filter((product) =>
      product.product_title.toLowerCase().includes(searchTerm.toLowerCase())
    );
    setFilteredProducts(filtered);
  };

  const updateCart = (id, amount) => {
    const product = products.find((item) => item.asin === id);

    if (product) {
      const newItem = {
        id: product.asin, // Adding id to differentiate items in the cart
        title: product.product_title,
        price: product.product_price,
        amount: amount,
        image: product.product_photo,
      };

      setCartItems((prevItems) => {
        const itemIndex = prevItems.findIndex((item) => item.id === id);

        if (itemIndex !== -1) {
          // If item already exists in the cart, update the amount
          const updatedItems = [...prevItems];
          updatedItems[itemIndex] = {
            ...updatedItems[itemIndex],
            amount: updatedItems[itemIndex].amount + amount,
          };
          return updatedItems;
        } else {
          // If item does not exist in the cart, add it
          return [...prevItems, newItem];
        }
      });
    } else {
      console.log(`Product with id ${id} not found.`);
    }
    console.log(cartItems);
  };
  const removeCart = (id) => {
    setCartItems(cartItems.filter((item) => item.id !== id));
  };
  useEffect(() => {
    fetchDrinks();
    localStorage.setItem("cartItems", JSON.stringify(cartItems));
  }, [searchTerm, products, cartItems]);

  return (
    <AppContext.Provider
      value={{
        products: filteredProducts,
        Oproducts: products,
        setSearchTerm,
        updateCart,
        cartItems,
        removeCart,
        setCartItems,
        setProducts,
      }}
    >
      {children}
    </AppContext.Provider>
  );
};

function useCartContext() {
  return useContext(AppContext);
}

export default useCartContext;
export { AppContext, AppProvider };
