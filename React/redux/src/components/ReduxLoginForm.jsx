import React from 'react';
import { useDispatch, useSelector } from 'react-redux';
import {
  updateLoginFormValue,
  setLoginFormTouched,
  setLoginFormErrors,
  resetLoginForm,
} from '../slices';
import { validateLoginForm } from '../utils/validation';
import './ReduxLoginForm.css';

/**
 * ReduxLoginForm Component
 * 
 * Demonstrates form management using Redux instead of local component state
 * All form state is stored in Redux store
 */

const ReduxLoginForm = () => {
  const dispatch = useDispatch();
  
  // Get form state from Redux
  const { values, errors, touched } = useSelector(
    (state) => state.forms.loginForm
  );

  // Handle input change
  const handleChange = (e) => {
    const { name, value } = e.target;
    dispatch(updateLoginFormValue({ field: name, value }));

    // Clear error if field was touched
    if (touched[name]) {
      const newErrors = validateLoginForm({ ...values, [name]: value });
      dispatch(setLoginFormErrors(newErrors));
    }
  };

  // Handle field blur
  const handleBlur = (e) => {
    const { name } = e.target;
    dispatch(setLoginFormTouched({ field: name }));
    
    // Validate on blur
    const newErrors = validateLoginForm(values);
    dispatch(setLoginFormErrors(newErrors));
  };

  // Handle form submission
  const handleSubmit = (e) => {
    e.preventDefault();
    
    // Mark all fields as touched
    Object.keys(values).forEach((field) => {
      dispatch(setLoginFormTouched({ field }));
    });

    // Validate
    const newErrors = validateLoginForm(values);
    dispatch(setLoginFormErrors(newErrors));

    // Check for errors
    const hasErrors = Object.values(newErrors).some((error) => error);

    if (!hasErrors) {
      console.log('✅ Redux Form Submitted:', values);
      // Reset form on success
      setTimeout(() => {
        dispatch(resetLoginForm());
      }, 1000);
    }
  };

  return (
    <div className="redux-form-container">
      <div className="redux-form-card">
        <h1>Redux Login Form</h1>
        <p className="subtitle">Form state managed with Redux Toolkit</p>

        <form onSubmit={handleSubmit}>
          {/* Email Field */}
          <div className="form-group">
            <label htmlFor="email">Email</label>
            <input
              type="email"
              id="email"
              name="email"
              value={values.email}
              onChange={handleChange}
              onBlur={handleBlur}
              className={`form-input ${touched.email && errors.email ? 'error' : ''}`}
              placeholder="you@example.com"
            />
            {touched.email && errors.email && (
              <span className="error-message">{errors.email}</span>
            )}
          </div>

          {/* Password Field */}
          <div className="form-group">
            <label htmlFor="password">Password</label>
            <input
              type="password"
              id="password"
              name="password"
              value={values.password}
              onChange={handleChange}
              onBlur={handleBlur}
              className={`form-input ${touched.password && errors.password ? 'error' : ''}`}
              placeholder="Enter your password"
            />
            {touched.password && errors.password && (
              <span className="error-message">{errors.password}</span>
            )}
          </div>

          {/* Buttons */}
          <div className="form-actions">
            <button type="submit" className="btn-submit">
              Login
            </button>
            <button
              type="button"
              className="btn-reset"
              onClick={() => dispatch(resetLoginForm())}
            >
              Reset
            </button>
          </div>
        </form>

        {/* Debug Info */}
        <details className="debug-info">
          <summary>Redux State</summary>
          <pre>
            {JSON.stringify(
              {
                values,
                errors,
                touched,
              },
              null,
              2
            )}
          </pre>
        </details>
      </div>
    </div>
  );
};

export default ReduxLoginForm;
