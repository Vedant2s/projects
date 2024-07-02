import React from "react";
import styled from "styled-components";
export default function Login() {
  const handleClick = () => {
    const clientId = "3a0f92a1d9d44823ae93a707cdaf15d5";
    const redirectURL = "http://localhost:3000/";
    const apiURL = "https://accounts.spotify.com/authorize";
    var state = "1234567890123456";
    const scope = [
      "user-read-email",
      "user-read-private",
      "user-read-playback-state",
      "user-modify-playback-state",
      "user-read-currently-playing",
      "user-read-playback-position",
      "user-top-read",
      "user-read-recently-played",
    ];
    window.location.href = `${apiURL}?client_id=${clientId}&redirect_uri=${redirectURL}&scope=${scope.join(
      " "
    )}&response_type=token&show_dialog=true&state:${state}`;
  };
  return (
    <Container>
      <img
        src="https://storage.googleapis.com/pr-newsroom-wp/1/2023/05/Spotify_Full_Logo_RGB_Green.png"
        alt="Spotify"
      />
      <button onClick={handleClick}>Connect Spotify</button>
    </Container>
  );
}
const Container = styled.div`
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  height: 100vh;
  width: 100vw;
  background-color: black;
  gap: 5rem;
  img {
    height: 20vh;
  }
  button {
    padding: 1rem 5rem;
    border-radius: 5rem;
    border: none;
    background-color: #013220;
    color: white;
    font-size: 1.1rem;
    cursor: pointer;
  }
`;
