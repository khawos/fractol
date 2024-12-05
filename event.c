#include "fractal.h"

int    close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
    mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
    mlx_destroy_display(fractal->mlx_ptr);
    free(fractal->mlx_ptr);
    exit('\0');
}

int    Key_handler(int keycode, t_fractal *fractal)
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
    draw(fractal);
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->img.img, 0, 0);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button5)
    {
        fractal->zoom *= 1.20;
    }
    else if (button == Button4)
        fractal->zoom *= 0.80;

    draw(fractal);
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->img.img, 0, 0);
    return (0);
}