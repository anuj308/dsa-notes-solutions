/**
 * Form Validation Functions
 * 
 * Reusable validation logic for form fields
 */

// Regular expression for email validation
const EMAIL_REGEX = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

/**
 * Validate login form
 * @param {Object} values - Form values containing email and password
 * @returns {Object} Errors object with field names as keys
 */
export const validateLoginForm = (values) => {
  const errors = {};

  // Email validation
  if (!values.email) {
    errors.email = 'Email is required';
  } else if (!EMAIL_REGEX.test(values.email)) {
    errors.email = 'Please enter a valid email address';
  }

  // Password validation
  if (!values.password) {
    errors.password = 'Password is required';
  } else if (values.password.length < 6) {
    errors.password = 'Password must be at least 6 characters long';
  }

  return errors;
};

/**
 * Validate registration form (extended validation)
 * @param {Object} values - Form values
 * @returns {Object} Errors object
 */
export const validateRegisterForm = (values) => {
  const errors = validateLoginForm(values);

  // Additional validations for registration
  if (!values.fullName) {
    errors.fullName = 'Full name is required';
  }

  if (values.password && values.confirmPassword) {
    if (values.password !== values.confirmPassword) {
      errors.confirmPassword = 'Passwords do not match';
    }
  }

  if (!values.confirmPassword) {
    errors.confirmPassword = 'Please confirm your password';
  }

  return errors;
};

/**
 * Generic field validator
 * @param {string} value - Field value
 * @param {Object} rules - Validation rules { required, minLength, pattern, custom }
 * @returns {string} Error message or empty string
 */
export const validateField = (value, rules) => {
  if (rules.required && !value) {
    return rules.requiredMessage || 'This field is required';
  }

  if (rules.minLength && value.length < rules.minLength) {
    return rules.minLengthMessage || `Minimum ${rules.minLength} characters required`;
  }

  if (rules.pattern && !rules.pattern.test(value)) {
    return rules.patternMessage || 'Invalid format';
  }

  if (rules.custom) {
    const customError = rules.custom(value);
    if (customError) return customError;
  }

  return '';
};
