#include <stdio.h>

/*The Mandelbrot set binds the points outside infinity. When you
leave it, you enter infinity.
A mandelbrot point always stays bounded within mandelbrot zone/*/

typedef struct s_complex
{
	//real n
	double real;

	//imaginary n
	double i;

} t_complex;


//for mac, change the flags, include a library to make it work.
int main()
{
	t_complex z;
	t_complex c;
	double temp;

	z.real = 0;
	z.i = 0;

	c.real = 2;
	c.i = 5;

	int i = 0;
	while (i < 42)
	{
		temp = (z.real * z.real)
	}


}