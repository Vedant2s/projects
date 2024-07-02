import React from 'react'
import { useDispatch } from 'react-redux'

import { reactionAdded } from './postsSlice'
const reactionEmoji = {
  thumbsUp: '👍',
  hooray: '🎉',
  heart: '❤️',
  rocket: '🚀',
  eyes: '👀',
}

export const ReactionButtons = ({ post }) => {
  const dispatch = useDispatch()
  const reactions = post.reactions || {
    thumbsUp: 0,
    hooray: 0,
    heart: 0,
    rocket: 0,
    eyes: 0,
  }
  const reactionButtons = Object.entries(reactionEmoji).map(([name, emoji]) => {
    return (
      <button
        key={name}
        type="button"
        className="muted-button reaction-button"
        onClick={() =>
          dispatch(reactionAdded({ postId: post.id, reaction: name }))
        }
      >
        {emoji}
        {reactions[name]}
      </button>
    )
  })

  return <div>{reactionButtons}</div>
}
