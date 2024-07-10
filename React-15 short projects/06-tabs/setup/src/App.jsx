import React, { useState, useEffect } from "react";
import { FaAngleDoubleRight } from "react-icons/fa";
import data from "./data";
// ATTENTION!!!!!!!!!!
// I SWITCHED TO PERMANENT DOMAIN
const url = "https://course-api.com/react-tabs-project";
function App() {
  const [loading, setLoading] = useState(true);
  const [jobs, setJobs] = useState([]);
  const [value, setValue] = useState(0);
  const fetchJobs = () => {
    // const response = await fetch("http://localhost:5000/")
    //   .then((res) => res.json())
    //   .then((data) => console.log(data));
    // const newJobs = await response.json();
    setJobs(data);
    setLoading(false);
  };
  useEffect(() => {
    fetchJobs();
  }, []);
  if (loading) {
    return (
      <section className="section loading">
        <h1>Loading...</h1>
      </section>
    );
  }
  // if (jobs.length === 0) {
  //   return (
  //     <section className="section">
  //       <h2>No jobs available</h2>
  //     </section>
  //   );
  // }
  const { title, dates, duties, company } = jobs[value];
  return (
    <section className="section">
      <div className="title">
        <h2>Experience</h2>
        <div className="underline"></div>
      </div>
      <div className="jobs-center">
        <div className="btn-container">
          {jobs.map((item, index) => (
            <button
              key={item.id}
              onClick={() => setValue(index)}
              className={`job-btn ${index === value && "active-btn"}`}
            >
              {item.company}
            </button>
          ))}
        </div>
        <article className="job-info">
          <h3>{title}</h3>
          <h4>{company}</h4>
          <p className="job-date">{dates}</p>
          {duties.map((duty, index) => {
            return (
              <div key={index} className="job-desc">
                <FaAngleDoubleRight className="job-icon" />
                <p>{duty}</p>
              </div>
            );
          })}
        </article>
      </div>
    </section>
  );
}

export default App;
