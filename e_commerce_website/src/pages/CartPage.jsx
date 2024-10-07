import React, { useEffect, useState } from "react";
import useCartContext from "../contexts/CartContext";
import Navbar from "../components/Layout/Navbar";
import { Link } from "react-router-dom";
import StripeCheckout from "react-stripe-checkout";
import CheckoutForm from "../components/Checkout/CheckoutForm";

function CartPage() {
  const { cartItems, removeCart, setCartItems } = useCartContext();
  const [cPrice, setCPrice] = useState(0);
  const [paymentDone, setPaymentDone] = useState(false);

  const handleIncrement = (id) => {
    setCartItems((prevItems) =>
      prevItems.map((item) =>
        item.id === id ? { ...item, amount: item.amount + 1 } : item
      )
    );
  };

  const handleDecrement = (id) => {
    setCartItems((prevItems) =>
      prevItems
        .map((item) =>
          item.id === id ? { ...item, amount: item.amount - 1 } : item
        )
        .filter((item) => item.amount > 0)
    );
  };

  useEffect(() => {
    const calculateTotalPrice = () => {
      let totalPrice = 0;
      cartItems.forEach((item) => {
        const numericPrice = parseFloat(
          String(item.price).replace(/[$,]/g, "")
        );
        totalPrice += numericPrice * item.amount;
      });
      setCPrice(totalPrice);
    };
    calculateTotalPrice();
  }, [cartItems]);

  const handleToken = (token) => {
    console.log(token);
    // Handle the token received from Stripe, e.g., send it to your backend for processing
    // Simulate payment processing
    setTimeout(() => {
      setPaymentDone(true);
    }, 2000); // Simulate a delay for payment processing
  };

  return (
    <div className="min-h-screen bg-gray-100">
      <Navbar />
      <h1 className="text-2xl bg-green-400 w-1/2 m-auto p-4 border-2 border-green-500 rounded-lg text-center shadow-lg">
        Total Price : ${cPrice.toFixed(2)}
        <CheckoutForm />
      </h1>

      <div className="container mx-auto p-4">
        <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-4">
          {cartItems.map((item, index) => {
            const { image, title, amount, price, id } = item;
            let numericPrice = parseFloat(String(price).replace(/[$,]/g, ""));
            return (
              <div
                key={index}
                className="bg-white rounded-lg shadow-md overflow-hidden"
              >
                <Link to={`/ProductDetails/:${id}`}>
                  <img
                    src={image}
                    alt={title}
                    className="w-full h-48 object-contain"
                  />
                </Link>
                <div className="p-4">
                  <h1 className="text-lg font-bold mb-2">Title: {title}</h1>
                  <p className="text-gray-700">
                    Price: ${numericPrice}
                    <br />
                    Amount: {amount}
                  </p>
                  <button
                    onClick={() => {
                      removeCart(id);
                      setCPrice(cPrice - numericPrice * amount);
                    }}
                    className="mt-2 p-2 bg-blue-500 text-white rounded-md hover:bg-green-400 hover:text-black"
                  >
                    Remove
                  </button>
                  <button
                    onClick={() => handleIncrement(id)}
                    className="ml-2 p-2 bg-white border-2 border-black text-black rounded-md cursor-pointer"
                  >
                    +
                  </button>
                  <button
                    onClick={() => handleDecrement(id)}
                    className="ml-2 p-2 bg-white border-2 border-black text-black rounded-md cursor-pointer"
                  >
                    -
                  </button>
                </div>
              </div>
            );
          })}
        </div>
      </div>

      <div className="text-center m-4">
        <StripeCheckout
          stripeKey="pk_test_51PdQ0WIUpNC7OCxh44lclew7Bf15cSbAIACprKTA6iG5SpGDRoVl5EVS8KTDUOhHN35aeEv16ZXoKlwnK7MiSBe400nEbkJ9yd"
          token={handleToken}
          amount={cPrice * 100}
          name={`Pay ${cPrice}$`}
          billingAddress
          shippingAddress
        />
      </div>

      {paymentDone && (
        <div className="text-center mt-4 p-4 bg-green-200 border-2 border-green-500 rounded-lg">
          Payment Successful!
        </div>
      )}
    </div>
  );
}

export default CartPage;
