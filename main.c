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

	argv += 0;
	if (!ft_strcmp(argc[1], "mandelbrot") || !ft_strcmp(argc[1], "julia"))
	{
		fractal.name = argc[1];
		fractal.active_julia = 0;
		if (argc[2] && argc[3])
		{
			fractal.julia_x = atoi_double(argc[2]);
			fractal.julia_y = atoi_double(argc[3]);
		}
		fractal_init(&fractal);
		draw(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		ft_putchar(ERROR);
	return (0);
}
