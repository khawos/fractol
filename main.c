#include "fractal.h"


int	main(int argv, char **argc)
{
	t_fractal	fractal;

	if (!ft_strcmp(argc[1], "mandelbrot"))
	{
		fractal_init(&fractal);
		draw(&fractal);
		// met l'image sur la fenetre
		mlx_put_image_to_window(fractal.mlx_ptr, fractal.mlx_win, fractal.img.img, 0, 0);
		mlx_loop(fractal.mlx_ptr);

	}
	else
		printf("%s\n", "non");
	return (0);
}
