import React from 'react'
import { createRoot } from 'react-dom/client'
import { Provider } from 'react-redux'

import App from './App'
// import { store } from './app/store' // Ensure this is a named import
import { store } from './app/store'
import { fetchUsers } from './features/users/usersSlice'
import './index.css'

import { worker } from './api/server'

// Wrap app rendering so we can wait for the mock API to initialize
async function start() {
  // Start our mock API server
  await worker.start({ onUnhandledRequest: 'bypass' })

  const root = createRoot(document.getElementById('root'))
  store.dispatch(fetchUsers())
  root.render(
    <Provider store={store}>
      <App />
    </Provider>,
  )
}

start()
