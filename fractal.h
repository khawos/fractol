/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:30:22 by amedenec          #+#    #+#             */
/*   Updated: 2024/12/07 00:30:22 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# define WIDTH 700
# define HEIGHT 700
# define ERROR "enter arguments\n\t-> mandelbrot\n\t-> julia <value 1> <value 2>\n"
# define BLACK 0x000000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		iterations;
	char	*name;
	int		active_julia;
	int		color_change;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	zoom;
	t_data	img;
}		t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// init
void		fractal_init(t_fractal *fractal);

// render
void		draw(t_fractal *fractal);
void		place_pixel(t_fractal *fractal, int x, int y);

// event
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

// utils
void		ft_putchar(char *str);
int			ft_strcmp(char *s1, char *s2);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		atoi_double(char *str);

// math
double		convert_range(double v, double m, double min_dst, double max_dst);

//math struct
t_complex	complex_sum(t_complex z, t_complex c);
t_complex	complex_sqrt(t_complex z);

#endif
