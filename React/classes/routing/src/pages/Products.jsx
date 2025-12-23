import { useEffect, useState } from "react";
import { Link, useNavigate, useSearchParams } from "react-router-dom";

const Products = () => {
  const [products, setProducts] = useState([]);
  const navigate = useNavigate();
  const [params] = useSearchParams();


  const category = params.get("category");

  useEffect(() => {
    fetch("https://fakestoreapi.com/products")
      .then(res => res.json())
      .then(data => setProducts(data));
  }, []);

  return (
    <>
      <h2>Products Page</h2>

      {/* Query Param Display */}
      {category && <p>Category: {category}</p>}

      {products.map(p => (
        <p key={p.id}>
          {/* Link navigation */}
          <Link
            to={`/product/${p.id}`}
            state={{ title: p.title }}
          >
            {p.title}
          </Link>
          <img src={`${p.image}`}/>
        </p>
      ))}

      {/* Back Navigation */}
      <button onClick={() => navigate(-1)}>Back</button>
    </>
  );
};

export default Products;
//Products page fetches data, reads query parameters, passes state while navigating, and supports back navigation