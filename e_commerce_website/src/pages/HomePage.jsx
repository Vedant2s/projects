import React from "react";
// import { data1 } from "../assets/data/data";
import Navbar from "../components/Layout/Navbar";
import Footer from "../components/Layout/Footer";
import ProductPage from "./ProductPage";
import Sidebar from "./Sidebar";
function HomePage() {
  // fetch("https://api.escuelajs.co/api/v1/products/?title=Generic")
  //   .then((res) => res.json())
  // console.log(data1.data.products);
  return (
    <>
      <Navbar />
      <Sidebar />
      <ProductPage />
      <Footer />
    </>
  );
}

export default HomePage;
