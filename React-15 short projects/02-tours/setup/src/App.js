import React, { useState, useEffect } from "react";
import Loading from "./Loading";
import Tours from "./Tours";
import data from "./data";

// Use a proxy server to bypass CORS issues
// const proxyUrl = "http://localhost:8080/";
// const url = "https://course-api.com/react-tours-project";

function App() {
  const [loading, setLoading] = useState(true);
  const [tours, setTours] = useState([]);
  const removeTour = (id) => {
    const newTours = tours.filter((tour) => tour.id !== id);
    setTours(newTours);
  };
  const fetchTours = () => {
    try {
      //   const response = await fetch(proxyUrl + url);
      //   const tours = await response.json();
      setLoading(false);
      setTours(Array.isArray(data) ? data : []);
      console.log(tours);
    } catch (error) {
      setLoading(false);
      console.log(error);
    }
  };

  useEffect(() => {
    fetchTours();
  }, []);
  if (loading) {
    return (
      <main>
        <Loading />
        {tours}
      </main>
    );
  }
  if (tours.length === 0) {
    return (
      <main>
        <div className="title">
          <h2>No tours left</h2>
          <button onClick={fetchTours} className="btn">
            Reset
          </button>
        </div>
      </main>
    );
  }
  return (
    <main>
      <Tours tours={tours} removeTour={removeTour} />
    </main>
  );
}

export default App;
