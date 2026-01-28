import React from 'react';
import useForm from '../hooks/useForm';
import { validateLoginForm } from '../utils/validation';
import './LoginForm.css';

/**
 * LoginForm Component
 * 
 * Demonstrates the useForm hook with proper:
 * - Real-time validation on blur and submit
 * - Error display only after field is touched
 * - Form reset on successful submission
 * - Loading state during submission
 */

const LoginForm = () => {
  // Initial form values
  const initialValues = {
    email: '',
    password: '',
  };

  // Handle form submission
  const handleSubmit = async (values) => {
    // Simulate API call
    await new Promise((resolve) => setTimeout(resolve, 1000));
    
    // Log successful submission
    console.log('✅ Form submitted successfully!');
    console.log('Form data:', values);
    
    // You can send this data to your backend here
    // Example: await loginUser(values);
  };

  // Use the custom hook
  const {
    values,
    errors,
    touched,
    handleChange,
    handleBlur,
    handleSubmit: onSubmit,
    resetForm,
    isSubmitting,
  } = useForm(initialValues, validateLoginForm, handleSubmit);

  return (
    <div className="login-container">
      <div className="login-card">
        <h1>Login</h1>
        <p className="subtitle">Enter your credentials to access your account</p>

        <form onSubmit={onSubmit}>
          {/* Email Field */}
          <div className="form-group">
            <label htmlFor="email">Email Address</label>
            <input
              type="email"
              id="email"
              name="email"
              value={values.email}
              onChange={handleChange}
              onBlur={handleBlur}
              className={`form-input ${
                touched.email && errors.email ? 'error' : ''
              }`}
              placeholder="you@example.com"
            />
            {/* Show error only if field is touched and has error */}
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
              className={`form-input ${
                touched.password && errors.password ? 'error' : ''
              }`}
              placeholder="Enter your password"
            />
            {/* Show error only if field is touched and has error */}
            {touched.password && errors.password && (
              <span className="error-message">{errors.password}</span>
            )}
          </div>

          {/* Form Actions */}
          <div className="form-actions">
            <button
              type="submit"
              className="btn-submit"
              disabled={isSubmitting}
            >
              {isSubmitting ? 'Logging in...' : 'Login'}
            </button>
            <button
              type="button"
              className="btn-reset"
              onClick={resetForm}
              disabled={isSubmitting}
            >
              Reset
            </button>
          </div>
        </form>

        {/* Debug Info - Remove in production */}
        <details className="debug-info">
          <summary>Debug: Form State</summary>
          <pre>{JSON.stringify({ values, errors, touched }, null, 2)}</pre>
        </details>
      </div>
    </div>
  );
};

export default LoginForm;
