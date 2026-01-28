import React, { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import {
  addTodo,
  deleteTodo,
  toggleTodo,
  updateTodo,
  setFilter,
  clearCompleted,
} from '../slices';
import './TodoList.css';

/**
 * TodoList Component
 * 
 * Manages todo items using Redux:
 * - Add new todos with priority
 * - Toggle todo completion status
 * - Delete todos
 * - Filter todos (all, completed, pending)
 * - Clear completed todos
 */

const TodoList = () => {
  // Redux hooks
  const dispatch = useDispatch();
  const todos = useSelector((state) => state.todos.todos);
  const filter = useSelector((state) => state.todos.filter);

  // Local state
  const [title, setTitle] = useState('');
  const [description, setDescription] = useState('');
  const [priority, setPriority] = useState('medium');
  const [editingId, setEditingId] = useState(null);

  // Filter todos based on current filter
  const filteredTodos = todos.filter((todo) => {
    if (filter === 'completed') return todo.completed;
    if (filter === 'pending') return !todo.completed;
    return true;
  });

  // Handle add todo
  const handleAddTodo = (e) => {
    e.preventDefault();
    if (title.trim()) {
      dispatch(addTodo({ title, description, priority }));
      setTitle('');
      setDescription('');
      setPriority('medium');
    }
  };

  // Handle delete todo
  const handleDeleteTodo = (id) => {
    dispatch(deleteTodo({ id }));
  };

  // Handle toggle todo
  const handleToggleTodo = (id) => {
    dispatch(toggleTodo({ id }));
  };

  // Handle update todo
  const handleUpdateTodo = (id, updates) => {
    dispatch(updateTodo({ id, updates }));
  };

  // Stats
  const completedCount = todos.filter((t) => t.completed).length;
  const totalCount = todos.length;
  const pendingCount = totalCount - completedCount;

  return (
    <div className="todo-container">
      <div className="todo-wrapper">
        {/* Header */}
        <div className="todo-header">
          <h1>📝 My Todo List</h1>
          <p className="stats">
            <span>{pendingCount} pending</span> •{' '}
            <span>{completedCount} completed</span> •{' '}
            <span>{totalCount} total</span>
          </p>
        </div>

        {/* Add Todo Form */}
        <form className="add-todo-form" onSubmit={handleAddTodo}>
          <div className="form-row">
            <input
              type="text"
              placeholder="Add a new task..."
              value={title}
              onChange={(e) => setTitle(e.target.value)}
              className="todo-input"
            />
            <select
              value={priority}
              onChange={(e) => setPriority(e.target.value)}
              className="priority-select"
            >
              <option value="low">Low</option>
              <option value="medium">Medium</option>
              <option value="high">High</option>
            </select>
            <button type="submit" className="btn-add">
              Add
            </button>
          </div>
          <textarea
            placeholder="Add description (optional)"
            value={description}
            onChange={(e) => setDescription(e.target.value)}
            className="todo-description"
            rows="2"
          />
        </form>

        {/* Filter Buttons */}
        <div className="filter-buttons">
          <button
            className={`filter-btn ${filter === 'all' ? 'active' : ''}`}
            onClick={() => dispatch(setFilter('all'))}
          >
            All
          </button>
          <button
            className={`filter-btn ${filter === 'pending' ? 'active' : ''}`}
            onClick={() => dispatch(setFilter('pending'))}
          >
            Pending
          </button>
          <button
            className={`filter-btn ${filter === 'completed' ? 'active' : ''}`}
            onClick={() => dispatch(setFilter('completed'))}
          >
            Completed
          </button>
          {completedCount > 0 && (
            <button
              className="filter-btn clear-btn"
              onClick={() => dispatch(clearCompleted())}
            >
              Clear Completed
            </button>
          )}
        </div>

        {/* Todo List */}
        <div className="todos-list">
          {filteredTodos.length === 0 ? (
            <div className="empty-state">
              <p>
                {filter === 'all'
                  ? 'No todos yet. Create one to get started!'
                  : `No ${filter} todos`}
              </p>
            </div>
          ) : (
            filteredTodos.map((todo) => (
              <div key={todo.id} className={`todo-item ${todo.completed ? 'completed' : ''}`}>
                <div className="todo-content">
                  <input
                    type="checkbox"
                    checked={todo.completed}
                    onChange={() => handleToggleTodo(todo.id)}
                    className="todo-checkbox"
                  />
                  <div className="todo-text">
                    <p className="todo-title">{todo.title}</p>
                    {todo.description && (
                      <p className="todo-desc">{todo.description}</p>
                    )}
                  </div>
                  <span className={`priority-badge priority-${todo.priority}`}>
                    {todo.priority}
                  </span>
                </div>
                <button
                  className="btn-delete"
                  onClick={() => handleDeleteTodo(todo.id)}
                  title="Delete todo"
                >
                  ✕
                </button>
              </div>
            ))
          )}
        </div>

        {/* Progress Bar */}
        {totalCount > 0 && (
          <div className="progress-section">
            <div className="progress-label">
              Progress: {completedCount} of {totalCount}
            </div>
            <div className="progress-bar">
              <div
                className="progress-fill"
                style={{
                  width: `${(completedCount / totalCount) * 100}%`,
                }}
              />
            </div>
          </div>
        )}
      </div>
    </div>
  );
};

export default TodoList;
