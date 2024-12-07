/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:39:32 by amedenec          #+#    #+#             */
/*   Updated: 2024/12/07 00:39:32 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argv, char **argc)
{
	t_fractal	fractal;

	if (!ft_strcmp(argc[1], "mandelbrot") || !ft_strcmp(argc[1], "julia"))
	{
		fractal.name = argc[1];
		fractal.boo = 0;
		if (argc[2] && argc[3])
		{
			fractal.julia_x = atoi_double(argc[2]);
			fractal.julia_y = atoi_double(argc[3]);
			fractal.boo = 1;
		}
		fractal_init(&fractal);
		draw(&fractal);
		mlx_put_image_to_window(fractal.mlx_ptr,
			fractal.mlx_win,
			fractal.img.img, 0, 0);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		printf("%s\n", "non");
	return (0);
}
