import { useParams, useNavigate, useLocation } from "react-router-dom";
import { useEffect, useState } from "react";

const ProductDetails = () => {
  const { id } = useParams();
  const navigate = useNavigate();
  const { state } = useLocation();

  const [product, setProduct] = useState({});

  useEffect(() => {
    fetch(`https://fakestoreapi.com/products/${id}`)
      .then(res => res.json())
      .then(data => setProduct(data));
  }, [id]);

  return (
    <>
      <h2>Product Details</h2>

      <p><b>ID:</b> {id}</p>

      {/* Data from state (if passed) */}
      <p><b>Title:</b> {state?.title || product.title}</p>

      <button onClick={() => navigate(-1)}>Back</button>
    </>
  );
};

export default ProductDetails;
//This component reads the ID from the URL, fetches product data, optionally receives state data, and allows back navigation