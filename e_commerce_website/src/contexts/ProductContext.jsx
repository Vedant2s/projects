// import React, { useEffect, useState, useContext } from "react";

// const ProductContext = React.createContext();

// const AppProvider = ({ children }) => {
//   const [isSidebarOpen, setIsSidebarOpen] = useState(true);

//   return (
//     <ProductContext.Provider value={{ isSidebarOpen, setIsSidebarOpen }}>
//       {children}
//     </ProductContext.Provider>
//   );
// };

// function useProductContext() {
//   return useContext(ProductContext);
// }

// export default useProductContext;
// export { ProductContext, AppProvider };

// import React, { useEffect, useState, useContext } from "react";
// import { data1, amdCpu } from "../assets/data/data";

// const AppContext = React.createContext();

// const AppProvider = ({ children }) => {
//   const [isSidebarOpen, setIsSidebarOpen] = useState(true);
//   console.log(isSidebarOpen);
//   return (
//     <AppContext.Provider value={{ isSidebarOpen, setIsSidebarOpen }}>
//       {children}
//     </AppContext.Provider>
//   );
// };

// function useProductContext() {
//   return useContext(AppContext);
// }

// export default useProductContext;
// export { AppContext, AppProvider };

import React, { useState, useContext } from "react";

const ProductContext2 = React.createContext();

const ProductProvider = ({ children }) => {
  const [isSidebarOpen, setIsSidebarOpen] = useState(true);
  // console.log(isSidebarOpen);
  return (
    <ProductContext2.Provider value={{ isSidebarOpen, setIsSidebarOpen }}>
      {children}
    </ProductContext2.Provider>
  );
};

const useProductContext = () => {
  return useContext(ProductContext2);
};
export default useProductContext;
export { ProductProvider, ProductContext2 };
