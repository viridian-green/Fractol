# Fract'ol: Fractal Explorer with MiniLibX

## 📋 Table of Contents

- [About](#about)
- [Project Overview](#project-overview)
- [Program Specifications](#program-specifications)
- [Installation & Usage](#installation--usage)
- [Fractal Types](#fractal-types)
- [Implementation Details](#implementation-details)
- [Controls & Features](#controls--features)
- [Testing & Validation](#testing--validation)
- [Makefile Targets](#makefile-targets)

## About

**Fract'ol** is a computer graphics project that generates and explores mathematical fractals using the MiniLibX library. This program allows users to visualize complex fractal patterns, including the Mandelbrot set and Julia sets, with interactive zooming and color manipulation.

## Project Overview

Fract'ol demonstrates:
- **Complex number mathematics** and fractal algorithms
- **Computer graphics programming** with MiniLibX
- **Interactive event handling** (keyboard, mouse)
- **Real-time rendering optimization**
- **Color theory applications** for visualization

### Key Features
- Multiple fractal types (Mandelbrot, Julia sets)
- Infinite zoom capability with mouse wheel
- Smooth window management and event handling
- Color palette customization
- Parameterized Julia sets

## Program Specifications

### Command Line Usage
```bash
./fractol [fractal_type] [parameters]
```

### Available Fractal Types
- `mandelbrot` - Classic Mandelbrot set
- `julia` - Julia set with default parameters
- `julia [real] [imaginary]` - Custom Julia set with complex parameters

### Examples
```bash
# Mandelbrot set
./fractol mandelbrot

# Default Julia set
./fractol julia

# Custom Julia set with parameters
./fractol julia -0.7 0.27
./fractol julia 0.355 0.355
./fractol julia -0.54 0.54
```

## Installation & Usage

### Dependencies
- **MiniLibX** - School's graphical library
- **math library** (`-lm` compiler flag)
- **libft** - Custom C library (optional)

### Compilation
```bash
git clone https://github.com/viridian-green/Fractol.git
cd fractol
make
```

### Running the Program
```bash
# Basic usage
./fractol mandelbrot
./fractol julia

# With custom Julia parameters
./fractol julia -0.4 0.6

# Invalid parameter handling
./fractol invalid
# Output: Available fractals: mandelbrot, julia [real] [imaginary]
```

## Fractal Types

### Mandelbrot Set
- Defined by the recurrence relation: zₙ₊₁ = zₙ² + c
- c represents each point in the complex plane
- Colors indicate how quickly points diverge to infinity

### Julia Set
- Defined by: zₙ₊₁ = zₙ² + c (fixed c value)
- c is a complex constant parameter
- Different c values produce dramatically different patterns
- Common Julia sets:
  - c = -0.7 + 0.27i (classic)
  - c = 0.355 + 0.355i (spiral)
  - c = -0.54 + 0.54i (dendritic)


## Controls & Features

### Mouse Controls
- **Scroll Up** - Zoom in at mouse position
- **Scroll Down** - Zoom out
- **Click and Drag** - Pan the view (optional enhancement)

### Keyboard Controls
- **ESC** - Close window and exit program
- **Arrow Keys** - Pan the view

### Window Features
- Smooth window management (minimize, switch windows)
- Clean exit on window close (red cross button)
- Real-time rendering updates
- High-performance rendering for smooth interaction

### Memory Management
```bash
# Check for memory leaks
valgrind --leak-check=full ./fractol mandelbrot

# Test clean exit on various closure methods
# ESC key, window close button, Ctrl-C
```

### Error Handling
```bash
# Test invalid parameters
./fractol invalid_fractal
./fractol julia invalid_number
./fractol julia 0.5  # missing parameter

```
## Optimization Techniques

### Rendering Optimization
- **Pixel-based calculation** for parallel processing
- **Optimized complex number arithmetic**
- **Escape time algorithm** with early termination
- **Progressive rendering** for smoother interaction

### Memory Optimization
- **Single image buffer** for display
- **Efficient color calculation** without storage
- **Clean resource management** with MiniLibX

### Mathematical Optimization
- **Periodicity checking** to avoid redundant calculations
- **Smooth coloring algorithms** for better visual quality
- **Mathematical approximations** for performance

---

**Note**: This implementation demonstrates advanced computer graphics programming with mathematical complexity. The solution provides an interactive fractal exploration experience with smooth performance, beautiful visualizations, and proper resource management while adhering to the MiniLibX library constraints.
