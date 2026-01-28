/**
 * Form Validation Utilities for Redux Forms
 */

const EMAIL_REGEX = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

/**
 * Validate login form
 * @param {Object} values - Form values
 * @returns {Object} Errors object
 */
export const validateLoginForm = (values) => {
  const errors = {};

  if (!values.email) {
    errors.email = 'Email is required';
  } else if (!EMAIL_REGEX.test(values.email)) {
    errors.email = 'Please enter a valid email address';
  }

  if (!values.password) {
    errors.password = 'Password is required';
  } else if (values.password.length < 6) {
    errors.password = 'Password must be at least 6 characters long';
  }

  return errors;
};

export default validateLoginForm;
