import { useState } from 'react';

/**
 * Custom Hook: useForm
 * 
 * A reusable form handling hook that manages:
 * - Form values (email, password, etc.)
 * - Form validation errors
 * - Touched fields tracking
 * - Form submission and reset
 * 
 * @param {Object} initialValues - Initial values for form fields
 * @param {Function} validate - Validation function that returns errors object
 * @param {Function} onSubmit - Callback function when form is submitted successfully
 * @returns {Object} Form state and handlers
 */

const useForm = (initialValues, validate, onSubmit) => {
  // State management
  const [values, setValues] = useState(initialValues);
  const [errors, setErrors] = useState({});
  const [touched, setTouched] = useState({});
  const [isSubmitting, setIsSubmitting] = useState(false);

  /**
   * Handle input value change
   * Updates the value for the field and clears validation error if field was already touched
   */
  const handleChange = (e) => {
    const { name, value, type, checked } = e.target;
    const fieldValue = type === 'checkbox' ? checked : value;
    
    setValues((prevValues) => ({
      ...prevValues,
      [name]: fieldValue,
    }));

    // Clear error if user starts typing after touching the field
    if (touched[name]) {
      const newErrors = validate({ ...values, [name]: fieldValue });
      setErrors((prevErrors) => ({
        ...prevErrors,
        [name]: newErrors[name] || '',
      }));
    }
  };

  /**
   * Handle field blur event
   * Marks field as touched and runs validation
   */
  const handleBlur = (e) => {
    const { name } = e.target;

    // Mark field as touched
    setTouched((prevTouched) => ({
      ...prevTouched,
      [name]: true,
    }));

    // Run validation
    const newErrors = validate(values);
    setErrors(newErrors);
  };

  /**
   * Handle form submission
   * Validates all fields and calls onSubmit if validation passes
   */
  const handleSubmit = async (e) => {
    e.preventDefault();

    // Mark all fields as touched
    const allTouched = Object.keys(initialValues).reduce(
      (acc, field) => ({
        ...acc,
        [field]: true,
      }),
      {}
    );
    setTouched(allTouched);

    // Validate all fields
    const newErrors = validate(values);
    setErrors(newErrors);

    // Check if there are any errors
    const hasErrors = Object.values(newErrors).some((error) => error);

    if (!hasErrors) {
      setIsSubmitting(true);
      try {
        // Call the onSubmit callback
        await onSubmit(values);
        // Reset form on successful submission
        resetForm();
      } catch (error) {
        console.error('Form submission error:', error);
      } finally {
        setIsSubmitting(false);
      }
    }
  };

  /**
   * Reset form to initial state
   * Clears all values, errors, and touched fields
   */
  const resetForm = () => {
    setValues(initialValues);
    setErrors({});
    setTouched({});
    setIsSubmitting(false);
  };

  return {
    values,
    errors,
    touched,
    handleChange,
    handleBlur,
    handleSubmit,
    resetForm,
    isSubmitting,
    setValues, // For programmatic value updates
    setErrors, // For manual error setting
  };
};

export default useForm;
