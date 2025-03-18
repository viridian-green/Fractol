ractol: Interactive Fractal Renderer with MiniLibX
Introduction
The concept of fractals was introduced by mathematician Benoit Mandelbrot in 1974, derived from the Latin word fractus, meaning "broken" or "fractured." A fractal is a complex mathematical pattern that remains self-similar at any scale, appearing infinitely detailed no matter how much you zoom in.

Many natural phenomena, such as Romanesco cabbage or snowflakes, exhibit fractal-like structures. With fractol, you will generate stunning fractals yourself and explore the mesmerizing world of infinite complexity!

Features
Supports two main fractals:
Mandelbrot set
Julia set (with customizable parameters)
Smooth zooming using the mouse wheel for deep exploration.
Interactive controls for real-time adjustments.
Color customization to enhance fractal depth and aesthetics.
Event handling for smooth window management.
Project Requirements
Written in C, following the 42 Norm.
Uses the MiniLibX library for graphics rendering.
No global variables allowed.
Proper memory management to prevent leaks.
A Makefile with standard rules (all, clean, fclean, re).
Usage

Compile the project using:
make
Run the program with one of the available fractal types:

./fractol mandelbrot
./fractol julia <real_part> <imaginary_part>

Example for a custom Julia set:

./fractol julia -0.8 0.156

Conclusion
This project is a hands-on introduction to computer graphics, complex numbers, and interactive rendering. By completing fractol, you’ll gain experience in graphics programming, event handling, and mathematical visualization while creating visually captivating fractals!
