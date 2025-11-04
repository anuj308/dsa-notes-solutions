import React from 'react'

const User = ({username,email,country}) => {
  return (
    <>
    <div>User</div>
    <div>{username}</div>
    <div>{email}</div>
    <div>{country}</div>
    </>
  )
}

export default User