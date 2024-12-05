#include "fractal.h"

void    event_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, Key_handler, fractal);
    mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, fractal);
    mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask, close_handler, fractal);
}

void    fractal_init(t_fractal *fractal)
{
    // cree une fenetre
    fractal->mlx_ptr = mlx_init();
    fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "test");
    // cree un buffer image
    fractal->img.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length,
								&fractal->img.endian);
    // data init;
    fractal->iterations = 20;
    fractal->shift_x = 0;
    fractal->shift_y = 0;
    fractal->zoom = 1;
    event_init(fractal);
}
