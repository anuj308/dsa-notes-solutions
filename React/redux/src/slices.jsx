/**
 * Redux Slices for Form and Todo Management
 * 
 * This file contains Redux Toolkit slices for:
 * 1. Form State Management
 * 2. Todo List Management
 */

import { createSlice } from '@reduxjs/toolkit';

// ===================== FORM SLICE =====================

const initialFormState = {
  loginForm: {
    values: {
      email: '',
      password: '',
    },
    errors: {},
    touched: {},
    isSubmitting: false,
    submitted: false,
  },
  registerForm: {
    values: {
      fullName: '',
      email: '',
      password: '',
      confirmPassword: '',
    },
    errors: {},
    touched: {},
    isSubmitting: false,
    submitted: false,
  },
};

export const formSlice = createSlice({
  name: 'forms',
  initialState: initialFormState,
  reducers: {
    // Login Form Actions
    updateLoginFormValue: (state, action) => {
      const { field, value } = action.payload;
      state.loginForm.values[field] = value;
    },

    setLoginFormTouched: (state, action) => {
      const { field } = action.payload;
      state.loginForm.touched[field] = true;
    },

    setLoginFormErrors: (state, action) => {
      state.loginForm.errors = action.payload;
    },

    setLoginFormSubmitting: (state, action) => {
      state.loginForm.isSubmitting = action.payload;
    },

    resetLoginForm: (state) => {
      state.loginForm = initialFormState.loginForm;
    },

    setLoginFormSubmitted: (state, action) => {
      state.loginForm.submitted = action.payload;
    },

    // Register Form Actions
    updateRegisterFormValue: (state, action) => {
      const { field, value } = action.payload;
      state.registerForm.values[field] = value;
    },

    setRegisterFormTouched: (state, action) => {
      const { field } = action.payload;
      state.registerForm.touched[field] = true;
    },

    setRegisterFormErrors: (state, action) => {
      state.registerForm.errors = action.payload;
    },

    setRegisterFormSubmitting: (state, action) => {
      state.registerForm.isSubmitting = action.payload;
    },

    resetRegisterForm: (state) => {
      state.registerForm = initialFormState.registerForm;
    },

    setRegisterFormSubmitted: (state, action) => {
      state.registerForm.submitted = action.payload;
    },

    // Reset all forms
    resetAllForms: (state) => {
      state.loginForm = initialFormState.loginForm;
      state.registerForm = initialFormState.registerForm;
    },
  },
});

// ===================== TODO SLICE =====================

const initialTodoState = {
  todos: [
    {
      id: 1,
      title: 'Learn React Hooks',
      description: 'Study custom hooks like useForm',
      completed: false,
      priority: 'high',
      createdAt: new Date().toISOString(),
    },
    {
      id: 2,
      title: 'Redux Implementation',
      description: 'Implement Redux for state management',
      completed: false,
      priority: 'medium',
      createdAt: new Date().toISOString(),
    },
  ],
  filter: 'all', // 'all', 'completed', 'pending'
  nextId: 3,
};

export const todoSlice = createSlice({
  name: 'todos',
  initialState: initialTodoState,
  reducers: {
    addTodo: (state, action) => {
      const { title, description = '', priority = 'medium' } = action.payload;
      state.todos.push({
        id: state.nextId,
        title,
        description,
        completed: false,
        priority,
        createdAt: new Date().toISOString(),
      });
      state.nextId += 1;
    },

    deleteTodo: (state, action) => {
      const { id } = action.payload;
      state.todos = state.todos.filter((todo) => todo.id !== id);
    },

    toggleTodo: (state, action) => {
      const { id } = action.payload;
      const todo = state.todos.find((t) => t.id === id);
      if (todo) {
        todo.completed = !todo.completed;
      }
    },

    updateTodo: (state, action) => {
      const { id, updates } = action.payload;
      const todo = state.todos.find((t) => t.id === id);
      if (todo) {
        Object.assign(todo, updates);
      }
    },

    setFilter: (state, action) => {
      state.filter = action.payload;
    },

    clearCompleted: (state) => {
      state.todos = state.todos.filter((todo) => !todo.completed);
    },

    resetTodos: (state) => {
      state.todos = [];
      state.filter = 'all';
    },
  },
});

// Export actions
export const {
  updateLoginFormValue,
  setLoginFormTouched,
  setLoginFormErrors,
  setLoginFormSubmitting,
  resetLoginForm,
  setLoginFormSubmitted,
  updateRegisterFormValue,
  setRegisterFormTouched,
  setRegisterFormErrors,
  setRegisterFormSubmitting,
  resetRegisterForm,
  setRegisterFormSubmitted,
  resetAllForms,
} = formSlice.actions;

export const {
  addTodo,
  deleteTodo,
  toggleTodo,
  updateTodo,
  setFilter,
  clearCompleted,
  resetTodos,
} = todoSlice.actions;

// Export reducers
export default {
  forms: formSlice.reducer,
  todos: todoSlice.reducer,
};
