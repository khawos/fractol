#ifndef FRACTAL_H
# define FRACTAL_H
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h> // to delete
#include "minilibx-linux/mlx.h"
#define WIDTH 800
#define HEIGHT 800

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define ORANGE_FIRE   0xFFA500  // Blazing Orange
#define PURPLE_HAZE   0x800080  // Intense Purple
#define AQUA_SPLASH   0x00FFFF  // Vibrant Aqua
#define PINK_FLARE    0xFFC0CB  // Neon Pink
#define CYAN_WAVE     0x00CED1  // Cool Cyan
#define LAVENDER_DREAM 0xE6E6FA // Soft Lavender
#define GOLDEN_GLOW   0xFFD700  // Radiant Gold
#define GRASS_RUSH    0x7CFC00  // Vivid Lime Green
#define BLOOD_ORANGE  0xFF4500  // Fiery Red-Orange
#define COSMIC_PURPLE 0x9400D3  // Galactic Purple
#define NEON_TURQUOISE 0x40E0D0 // Electric Turquoise

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
    void    *mlx_ptr;
    void	*mlx_win;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
    t_data	img;
}           t_fractal;

typedef struct s_complex
{
	double x;
	double y;
}			t_complex;


// init
void    fractal_init(t_fractal *fractal);

// render
void    draw(t_fractal *fractal);
void    place_pixel(t_fractal *fractal, int x, int y);

// event
int    Key_handler(int keycode, t_fractal *fractal);
int    close_handler(t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);

// utils
int ft_strcmp(char *s1, char *s2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// math
double	convert_range(double value, double max_src, double min_dst, double max_dst);
t_complex   complex_sum(t_complex z, t_complex c);
t_complex   complex_sqrt(t_complex z);

#endif
