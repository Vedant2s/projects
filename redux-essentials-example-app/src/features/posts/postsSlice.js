import { createSlice, nanoid, createAsyncThunk } from '@reduxjs/toolkit'
import { client } from '../../api/client'
// import { sub } from 'date-fns'
const initialState = {
  posts: [],
  status: 'idle',
  error: null,
}
const postsSlice = createSlice({
  name: 'posts',
  initialState,

  reducers: {
    reactionAdded(state, action) {
      const { postId, reaction } = action.payload

      const existingPost = state.posts.find((post) => post.id === postId)
      // let existingPostCount = state.count.find((post) => post.id === postId)
      if (existingPost) {
        // Ensure reactions object exists
        if (!existingPost.reactions) {
          existingPost.reactions = {
            thumbsUp: 0,
            hooray: 0,
            heart: 0,
            rocket: 0,
            eyes: 0,
          }
        }
      }
      if (existingPost) {
        // Check if any other reaction was previously clicked
        Object.keys(existingPost.reactions).forEach((key) => {
          while (existingPost.reactions[key] > 0 && key !== reaction) {
            existingPost.reactions[key]--
          }
        })

        // Increment the selected reaction
        existingPost.reactions[reaction]++
      }
    },
    postAdded: {
      reducer(state, action) {
        state.posts.push(action.payload)
      },
      prepare(title, content, userId) {
        return {
          payload: {
            id: nanoid(),
            title,
            content,
            user: userId,
            date: new Date().toISOString(),
          },
        }
      },
    },
    postUpdated(state, action) {
      const { id, title, content } = action.payload
      const existingPost = state.posts.find((post) => post.id === id)
      if (existingPost) {
        existingPost.title = title
        existingPost.content = content
      }
    },
  },
  extraReducers(builder) {
    builder
      .addCase(fetchPosts.pending, (state, action) => {
        state.status = 'loading'
      })
      .addCase(fetchPosts.fulfilled, (state, action) => {
        state.status = 'succeeded'
        // Add any fetched posts to the array
        state.posts = state.posts.concat(action.payload)
      })
      .addCase(fetchPosts.rejected, (state, action) => {
        state.status = 'failed'
        state.error = action.error.message
      })
      .addCase(addNewPost.fulfilled, (state, action) => {
        // We can directly add the new post object to our posts array
        state.posts.push(action.payload)
      })
  },
})

export const { postAdded, postUpdated, reactionAdded } = postsSlice.actions
export default postsSlice.reducer

export const selectAllPosts = (state) => state.posts.posts

export const selectPostById = (state, postId) =>
  state.posts.posts.find((post) => post.id === postId)

export const fetchPosts = createAsyncThunk('posts/fetchPosts', async () => {
  const response = await client.get('/fakeApi/posts')
  return response.data
})

export const addNewPost = createAsyncThunk(
  'posts/addNewPost',
  // The payload creator receives the partial `{title, content, user}` object
  async (initialPost) => {
    // We send the initial data to the fake API server
    const response = await client.post('/fakeApi/posts', initialPost)
    // The response includes the complete post object, including unique ID
    return response.data
  },
)
