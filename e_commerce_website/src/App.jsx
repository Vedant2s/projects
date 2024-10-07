import HomePage from "./pages/HomePage";
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import About from "./pages/About";
import CartPage from "./pages/CartPage";
import ProductDetails from "./components/Product/ProductDetails";
import Errorr from "./pages/Errorr";

function App() {
  return (
    <>
      <Router>
        {/* <Navbar /> */}
        <Routes>
          <Route exact path="/" element={<HomePage />} />
          <Route exact path="/about" element={<About />} />
          <Route exact path="/cart" element={<CartPage />} />
          <Route
            exact
            path="/ProductDetails/:id"
            element={<ProductDetails />}
          />
          <Route path="*" element={<Errorr />} />
        </Routes>
      </Router>
    </>
  );
}

export default App;
