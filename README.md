# Corebel Engine

**Corebel Engine** is a modular, open-source 3D game engine designed to empower developers with an efficient and highly customizable framework for building games and interactive experiences. Built with cutting-edge libraries and tools, Corebel Engine prioritizes flexibility, performance, and ease of integration.

---

## Features
- **Project Management**: Easy creation, loading, and saving of projects with a robust file management system.
- **Rendering**: Powered by `bgfx`, `Ogre3D`, and `Dear ImGui` for modern graphics and UI rendering.
- **Physics**: Realistic simulation using `Bullet` physics and `Eigen` for mathematical computations.
- **Networking**: Seamless multiplayer capabilities with `RakNet`.
- **Audio**: Immersive sound design enabled by `FMOD`.
- **Scripting**: Flexible game logic scripting using `Lua`.
- **Asset Management**: Load and manage 3D assets with `Assimp`.
- **Entity System**: Manage entities and components with `entt`.
- **File Handling**: Reliable file operations with `Boost.filesystem`, `zlib` for compression, and `RapidJSON` for configurations.

---

## Getting Started

### Prerequisites
- **Development Environment**: Codespaces or local environment with C++17 support.
- **Dependencies**: Ensure the following libraries are available in the `libs` directory:
  - [bgfx](https://github.com/bkaradzic/bgfx)
  - [Bullet Physics](https://github.com/bulletphysics/bullet3)
  - [Eigen](https://eigen.tuxfamily.org/)
  - [FMOD](https://www.fmod.com/)
  - [SDL2](https://www.libsdl.org/)
  - [Lua](https://www.lua.org/)
  - [Assimp](https://github.com/assimp/assimp)
  - [Dear ImGui](https://github.com/ocornut/imgui)
  - [RakNet](https://github.com/facebookarchive/RakNet)
  - [Ogre3D](https://www.ogre3d.org/)
  - [Boost.Filesystem](https://www.boost.org/)
  - [zlib](https://zlib.net/)
  - [RapidJSON](https://rapidjson.org/)

### Building the Engine
1. Clone the repository:
   ```bash
   git clone https://github.com/wizcann/CorebelEngine.git
   cd CorebelEngine
