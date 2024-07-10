import React from "react";
import { FaEdit, FaTrash } from "react-icons/fa";
const List = ({ items, removeItem, editItem }) => {
  return (
    <div className="grocery-list">
      {items.map((item) => {
        const { id, title } = item;
        return (
          <article className="grocery-item">
            <p className="title">{title}</p>
            <div className="btn-container">
              <button className="edit-btn" onClick={() => editItem(id)}>
                <FaEdit className="icon" />
              </button>

              <button className="delete-btn" onClick={() => removeItem(id)}>
                <FaTrash className="icon" />
              </button>
            </div>
          </article>
        );
      })}
    </div>
  );
};

export default List;
