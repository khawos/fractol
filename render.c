/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:41:38 by amedenec          #+#    #+#             */
/*   Updated: 2024/12/07 00:41:38 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	get_color(int i, int max_iterations)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (i == max_iterations)
		return (0x000000);
	t = (double)i / max_iterations;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

void	give_c(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->y = z->y;
		c->x = z->x;
	}
}

void	place_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int	color;

	i = 0;
	z.x = (convert_range(x, WIDTH, -2, 2) * fractal->zoom) + fractal->shift_x;
	z.y = (convert_range(y, HEIGHT, +2, -2) * fractal->zoom) + fractal->shift_y;
	give_c(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqrt(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = get_color(i, fractal->iterations);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, BLACK);
}

void	draw(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			place_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
}
