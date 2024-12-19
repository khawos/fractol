/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:51:53 by amedenec          #+#    #+#             */
/*   Updated: 2024/12/07 00:51:53 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_handler(fractal);
	else if (keycode == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == XK_plus || keycode == 65451)
		fractal->iterations += 5;
	else if (keycode == XK_minus || keycode == 65453)
		fractal->iterations -= 5;
	else if (keycode == 101)
		fractal->color_change += 50;
	else if (keycode == 106)
	{
		if (fractal->active_julia)
			fractal->active_julia = 0;
		else
			fractal->active_julia = 1;
	}
	draw(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	x = 42;
	y = 42;
	if (button == Button5)
		fractal->zoom *= 1.25;
	else if (button == Button4)
		fractal->zoom *= 0.75;
	draw(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_win, fractal->img.img, 0, 0);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!fractal->active_julia)
		return (0);
	fractal->julia_x = convert_range(x, WIDTH, -2, 2) + fractal->shift_x;
	fractal->julia_y = convert_range(y, HEIGHT, -2, 2) + fractal->shift_y;
	draw(fractal);
	return (0);
}
