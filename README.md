# OpenGL College Project

A small OpenGL application using `glad` and `glfw`.

## Project structure

- `main.cpp` — application entry point
- `include/` — OpenGL headers for `glad`
- `src/` — source files, including `glad.c`
- `.vscode/` — editor settings (excluded from version control)

## Build

On Linux, build with:

```bash
g++ main.cpp src/glad.c -I./include -lGL -lglfw -o opengl_app
```

Then run:

```bash
./opengl_app
```

## Requirements

- `g++`
- `libglfw3` / `libglfw3-dev`
- OpenGL development libraries

## Notes

This repository is set up for an initial commit and push to a remote Git repository.
