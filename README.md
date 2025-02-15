# Foucault Pendulum Simulation using ncurses
This proyect implements a **Foucault Pendulum** simulation using `ncurses` for terminal-based visualization. The simulation models the pendulum's motion considering the effects of gravity and Earth's rotation.

## Description
A **Foucault Pendulum** is a device that demonstrates the Earth's rotation. It swings in a fixed plane, but due to Earth's rotation, its trajectory appears to change over time. This simulation uses **Runge-Kutta 4th order (RK4) integration** for accurate motion.

## Features
- Uses **ncurses** for terminal-based rendering.
- Implements **RK4 integration** for precise motion updates.
- Interactive: allows real-time visualization.

## Dependencies
Before compiling the program, ensure you have the following installed:
- **GCC** (C compiler) -> [Install GCC](https://gcc.gnu.org/install/)
- **ncurses** (for terminal graphics) -> [Install ncurses](https://invisible-island.net/ncurses/)

## Building and Running
This project uses make to simplify compilation and execution.

- **Compile the program**:
```sh
make
```

- **Run the simulation**:
```sh
make run
```

- **Clean up compiled files**:
```sh
make clean
```

## Future Improvements
The simulation could be enhanced using a graphical library like SDL2 or OpenGL, which would allow:
- Smoother animations and higher frame rates.
- Better visualization of the pendulum's trajectory.
- Support for 3D rendering.
