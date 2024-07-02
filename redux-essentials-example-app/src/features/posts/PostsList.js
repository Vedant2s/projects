// // import React from 'react'
// import { Link } from 'react-router-dom'
// import PostAuthor from './PostAuthor' // Adjust the import path as needed
// import { TimeAgo } from './TimeAgo' // Adjust the import path as needed
// // import { selectAllPosts } from './postsSlice'
// import React, { useEffect } from 'react'
// import { useSelector, useDispatch } from 'react-redux'
// // omit other imports
// import { selectAllPosts, fetchPosts } from './postsSlice'
// import { Spinner } from '../../components/Spinner'
// import { ReactionButtons } from './ReactionButtons'
// const PostExcerpt = ({ post }) => {
//   return (
//     <article className="post-excerpt">
//       <h3>{post.title}</h3>
//       <div>
//         <PostAuthor userId={post.user} />
//         <TimeAgo timestamp={post.date} />
//       </div>
//       <p className="post-content">{post.content.substring(0, 100)}</p>

//       <ReactionButtons post={post} />
//       <Link to={`/posts/${post.id}`} className="button muted-button">
//         View Post
//       </Link>
//     </article>
//   )
// }
// export const PostsList = () => {
//   const posts = useSelector(selectAllPosts)
//   const dispatch = useDispatch()
//   const error = useSelector((state) => state.posts.error)
//   const postStatus = useSelector((state) => state.posts.status)

//   useEffect(() => {
//     if (postStatus === 'idle') {
//       dispatch(fetchPosts())
//     }
//   }, [postStatus, dispatch])
//   let content

//   if (postStatus === 'loading') {
//     content = <Spinner text="Loading..." />
//   } else if (postStatus === 'succeeded') {
//     // Sort posts in reverse chronological order by datetime string
//     const orderedPosts = posts
//       .slice()
//       .sort((a, b) => b.date.localeCompare(a.date))

//     content = orderedPosts.map((post) => (
//       <PostExcerpt key={post.id} post={post} />
//     ))
//   } else if (postStatus === 'failed') {
//     content = <div>{error}</div>
//   }
//   // const orderedPosts = Array.isArray(posts)
//   //   ? [...posts].sort((a, b) => {
//   //       const dateA = a.date || ''
//   //       const dateB = b.date || ''
//   //       return dateB.localeCompare(dateA)
//   //     })
//   //   : []

//   // const renderedPosts = orderedPosts.map((post) => {
//   //   return (
//   //     <article className="post-excerpt" key={post.id}>
//   //       <h3>{post.title}</h3>
//   //       <div>
//   //         <PostAuthor userId={post.user} />
//   //         <TimeAgo timestamp={post.date} />
//   //       </div>
//   //       <p className="post-content">{post.content.substring(0, 100)}</p>
//   //       <Link to={`/posts/${post.id}`} className="button muted-button">
//   //         View Post
//   //       </Link>
//   //     </article>
//   //   )
//   // })

//   return (
//     <section className="posts-list">
//       <h2>Posts {content} </h2>
//       {/* {renderedPosts} */}
//       {/* {content}  */}
//     </section>
//   )
// }

import React, { useEffect } from 'react'
import { useSelector, useDispatch } from 'react-redux'
import { Link } from 'react-router-dom'
import PostAuthor from './PostAuthor' // Adjust the import path as needed
import { TimeAgo } from './TimeAgo' // Adjust the import path as needed
import { selectAllPosts, fetchPosts } from './postsSlice'
import { Spinner } from '../../components/Spinner'
import { ReactionButtons } from './ReactionButtons'

const PostExcerpt = ({ post }) => {
  return (
    <article className="post-excerpt">
      <h3>{post.title}</h3>
      <div>
        <PostAuthor userId={post.user} />
        <TimeAgo timestamp={post.date} />
      </div>
      <p className="post-content">{post.content.substring(0, 100)}</p>

      <ReactionButtons post={post} />
      <Link to={`/posts/${post.id}`} className="button muted-button">
        View Post
      </Link>
    </article>
  )
}

export const PostsList = () => {
  const posts = useSelector(selectAllPosts)
  const dispatch = useDispatch()
  const error = useSelector((state) => state.posts.error)
  const postStatus = useSelector((state) => state.posts.status)

  useEffect(() => {
    if (postStatus === 'idle') {
      dispatch(fetchPosts())
    }
  }, [postStatus, dispatch])

  let content

  if (postStatus === 'loading') {
    content = <Spinner text="Loading..." />
  } else if (postStatus === 'succeeded') {
    // Sort posts in reverse chronological order by datetime string
    const orderedPosts = posts
      .slice()
      .sort((a, b) => b.date.localeCompare(a.date))

    content = orderedPosts.map((post) => (
      <PostExcerpt key={post.id} post={post} />
    ))
  } else if (postStatus === 'failed') {
    content = <div>{error}</div>
  }

  return (
    <section className="posts-list">
      <h2>Posts</h2>
      {content}
    </section>
  )
}
