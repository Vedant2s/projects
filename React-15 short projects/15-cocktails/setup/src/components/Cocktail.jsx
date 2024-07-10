import React from "react";
import { Link } from "react-router-dom";

const Cocktail = ({ id, name, image, info, glass }) => {
  return (
    <article className="cocktail">
      <div className="img-container">
        <img src={image} alt={name} />
      </div>
      <div className="cocktail-footer">
        <h3>{name}</h3>
        <h4>{glass}</h4>
        <p
          style={{
            color: info === "Alcoholic" ? "#f00" : "#26bf26",
            fontWeight: "bold",
          }}
        >
          {info}
        </p>
        <Link to={`/cocktail/${id}`} className="btn btn-primary btn-details">
          Details
        </Link>
      </div>
    </article>
  );
};

export default Cocktail;
