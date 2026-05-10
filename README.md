# Solar System Visualization

An interactive 3D solar system visualization using OpenGL and GLUT. The application displays all eight planets orbiting around the sun at different speeds and distances, with a procedurally generated starfield background.

## Features

- Animated planetary orbits with realistic speed ratios
- All planets: Mercury, Venus, Earth (with moon), Mars, Jupiter, Saturn, Uranus, and Neptune
- Dynamic starfield background
- Real-time animation at 60 FPS
- Color-coded planets for easy identification

## Project structure

- `main.cpp` — application entry point and main visualization code
- `include/` — OpenGL headers for `glad` and GLUT
- `src/` — source files, including `glad.c`

## Build

On Linux, build with:

```bash
g++ main.cpp src/glad.c -I./include -lGL -lglfw -o opengl_app && ./opengl_app
```

Or use the VS Code build task: **Ctrl+Shift+B**

## Requirements

- `g++` compiler
- OpenGL development libraries (`libgl1-mesa-dev`)
- GLUT development libraries (`freeglut3-dev`)

## Controls

The visualization runs automatically. The window displays an 800x600 viewport with the solar system centered and all planets in constant orbital motion.
