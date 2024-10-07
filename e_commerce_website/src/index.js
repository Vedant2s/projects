import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import App from "./App";
import { AppProvider } from "./contexts/CartContext";
import { ProductProvider } from "./contexts/ProductContext";
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <>
    <AppProvider>
      <ProductProvider>
        <App />
      </ProductProvider>
    </AppProvider>
  </>
);

// Src
// src/assets/images: Store images and other static assets.
// Components
// Cart: Components related to cart management.

// CartItem.js: Represents a single item in the cart.
// CartSummary.js: Displays a summary of the cart contents.
// Checkout: Components related to the checkout process.

// CheckoutForm.js: Form to handle user input during checkout.
// OrderSummary.js: Summary of the order details during checkout.
// Layout: Components for layout and navigation.

// Footer.js: The footer of the website.
// Header.js: The header of the website.
// Navbar.js: The navigation bar.
// Payment: Components related to payment processing.

// PaymentGateway.js: Integration with a payment gateway.
// Product: Components related to product display and search.

// ProductCard.js: A card component to display product information.
// ProductDetails.js: Detailed view of a single product.
// ProductList.js: List view of products.
// ProductGrid.js: Grid view of products.
// ProductSearch.js: Search component for finding products.
// Contexts
// CartContext.js: Context and provider for cart state management.
// ProductContext.js: Context and provider for product state management.
// Hooks
// useCart.js: Custom hook for cart-related operations.
// useProduct.js: Custom hook for product-related operations.
// Pages
// CartPage.js: Page for displaying the cart.
// CheckoutPage.js: Page for the checkout process.
// HomePage.js: The main landing page.
// ProductPage.js: Page for displaying a single product's details.
// SearchResultsPage.js: Page for displaying search results.
// Services
// api.js: API service for making requests to the backend.

// Root Files
// App.js: The main app component that includes routing.
// index.js: The entry point for the React application.
// .env: Environment variables.
// package.json: Project dependencies and scripts.
// README.md: Documentation for the project.
// Additional Notes
// Routing: Use React Router for handling navigation between pages.
// State Management: Use React Context API or a state management library like Redux for managing global state.
// Styling: Use CSS-in-JS libraries like styled-components, or traditional CSS/SCSS files.
// API Integration: Use Axios or Fetch API for making HTTP requests to your backend.
