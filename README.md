# Chatty 🤖  
*A friendly conversational bot made in C++*

---

## Overview

**Chatty** is a lightweight, voice-enabled chatbot written in modern C++. Powered by the **Claude 3.5 Sonnet API**, it delivers intelligent and natural conversations—designed with extra friendliness and personality in mind.

Whether you're using it via text or voice, Chatty aims to be helpful, responsive, and pleasant to interact with.

---

## Features

- 🧠 **Claude 3.5 Sonnet Integration**  
  Uses Anthropic’s Claude 3.5 Sonnet model for high-quality language generation.

- 🔊 **Text-to-Speech (TTS) Support**  
  Chatty can speak its replies, offering a more immersive experience.

- 😊 **Custom Friendliness Layer**  
  Additional prompt engineering and logic ensures more personable and engaging interactions.

- ⚡ **Fast and Lightweight**  
  Built in C++ for speed and low resource usage.

---

## How It Works

1. The user types a message (or speaks it, if STT is integrated).
2. Chatty sends the prompt to Claude 3.5 Sonnet via API.
3. The response is received and displayed in the terminal (and optionally spoken via TTS).
4. The cycle repeats, maintaining context and tone.

---

## Requirements

- C++17 or later
- cURL (for HTTP requests)
- JSON library (e.g., [nlohmann/json](https://github.com/nlohmann/json))
- API Key for Claude 3.5 (via [Anthropic](https://www.anthropic.com/))
- TTS engine (e.g., eSpeak, Festival, or any system-level TTS)

---

## Setup

1. **Clone the repository**  
   ```bash
   git clone https://github.com/yourusername/chatty.git
   cd chatty
