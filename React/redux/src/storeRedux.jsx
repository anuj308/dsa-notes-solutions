/**
 * Redux Store Configuration
 * 
 * Combines all slices and creates the Redux store using Redux Toolkit
 */

import { configureStore } from '@reduxjs/toolkit';
import formReducer from './slices';
import todoReducer from './slices';

export const store = configureStore({
  reducer: {
    forms: formReducer.forms,
    todos: formReducer.todos,
  },
});

export default store;
