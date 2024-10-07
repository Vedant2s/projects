import React from "react";
import { FaTimes } from "react-icons/fa";
import { TiThMenu } from "react-icons/ti";
import useProductContext from "../contexts/ProductContext";
import useCartContext from "../contexts/CartContext";
import {
  amdCpu,
  intelCpu,
  GChair,
  GFuel,
  IBracket,
  Ipad,
  ac1,
  aio1,
  airCooler,
  am4Mobo,
  am5Mobo,
  case1,
  clothMousePad,
  console1,
  cpuBlock,
  ddr4Ram,
  ddr5Ram,
  desk1,
  externalMonitor,
  fanSplitter,
  glassMousePad,
  gpuBlock,
  gtxGpu,
  hdd,
  headphone1,
  highrpmFan,
  intelMobo,
  keyboard,
  laptop,
  laptopCooler,
  lowrpmFaan,
  macbook,
  metallicTP,
  monitor1,
  monitorStand,
  mouse,
  mouseBungee,
  phone,
  psu1,
  rtxGpu,
  rxGpu,
  ssd,
  thermalPaste,
  wAdapter,
  wFittings,
  wLiquid,
  wReservoir,
} from "../assets/data/data";

function Sidebar() {
  const { isSidebarOpen, setIsSidebarOpen } = useProductContext();
  const { setProducts } = useCartContext();

  const categories = [
    { name: "AMD Processors", data: amdCpu },
    { name: "Intel Processors", data: intelCpu },
    { name: "Gaming Chairs", data: GChair },
    { name: "Gaming Fuel", data: GFuel },
    { name: "iPhone Brackets", data: IBracket },
    { name: "iPads", data: Ipad },
    { name: "Air Conditioners", data: ac1 },
    { name: "AIO Coolers", data: aio1 },
    { name: "Air Coolers", data: airCooler },
    { name: "AM4 Motherboards", data: am4Mobo },
    { name: "AM5 Motherboards", data: am5Mobo },
    { name: "PC Cases", data: case1 },
    { name: "Cloth Mouse Pads", data: clothMousePad },
    { name: "Consoles", data: console1 },
    { name: "CPU Blocks", data: cpuBlock },
    { name: "DDR4 RAM", data: ddr4Ram },
    { name: "DDR5 RAM", data: ddr5Ram },
    { name: "Desks", data: desk1 },
    { name: "External Monitors", data: externalMonitor },
    { name: "Fan Splitters", data: fanSplitter },
    { name: "Glass Mouse Pads", data: glassMousePad },
    { name: "GPU Blocks", data: gpuBlock },
    { name: "GTX GPUs", data: gtxGpu },
    { name: "HDDs", data: hdd },
    { name: "Headphones", data: headphone1 },
    { name: "High RPM Fans", data: highrpmFan },
    { name: "Intel Motherboards", data: intelMobo },
    { name: "Keyboards", data: keyboard },
    { name: "Laptops", data: laptop },
    { name: "Laptop Coolers", data: laptopCooler },
    { name: "Low RPM Fans", data: lowrpmFaan },
    { name: "MacBooks", data: macbook },
    { name: "Metallic Thermal Pads", data: metallicTP },
    { name: "Monitors", data: monitor1 },
    { name: "Monitor Stands", data: monitorStand },
    { name: "Mice", data: mouse },
    { name: "Mouse Bungees", data: mouseBungee },
    { name: "Phones", data: phone },
    { name: "PSUs", data: psu1 },
    { name: "RTX GPUs", data: rtxGpu },
    { name: "RX GPUs", data: rxGpu },
    { name: "SSDs", data: ssd },
    { name: "Thermal Paste", data: thermalPaste },
    { name: "Water Adapter", data: wAdapter },
    { name: "Water Fittings", data: wFittings },
    { name: "Water Liquid", data: wLiquid },
    { name: "Water Reservoirs", data: wReservoir },
  ];

  return (
    <div className=" z-20 sticky top-20 max-h-80  overflow-auto bg-gray-900 text-white">
      <button
        onClick={() => setIsSidebarOpen(!isSidebarOpen)}
        className={`p-1 ${!isSidebarOpen ? "bg-green-300" : "bg-red-300"} `}
      >
        {isSidebarOpen ? (
          <FaTimes className="text-orange-700 text-4xl" />
        ) : (
          <TiThMenu className="text-orange-700 text-4xl" />
        )}
      </button>
      {isSidebarOpen && (
        <div className="p-1">
          <ul className="grid grid-cols-2 sm:grid-cols-4 md:grid-cols-5 lg:grid-cols-6 gap-4">
            {categories.map((category) => (
              <li key={category.name}>
                <button
                  onClick={() => {
                    setIsSidebarOpen(false);
                    setProducts(category.data);
                  }}
                  className="hover:bg-gray-700 p-2 rounded "
                >
                  {category.name}
                </button>
              </li>
            ))}
          </ul>
        </div>
      )}
    </div>
  );
}

export default Sidebar;
