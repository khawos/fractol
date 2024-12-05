#include "fractal.h"

void    place_pixel(t_fractal *fractal, int x, int y)
{
    t_complex   z;
    t_complex   c;
    int i;
    int color;

    i = 0;
    z.x = 0;
    z.y = 0;

    c.x = (convert_range(x, WIDTH, -2, 2) * fractal->zoom) + fractal->shift_x;
    c.y = (convert_range(y, HEIGHT, +2, -2) * fractal->zoom) + fractal->shift_y;

    while (i < fractal->iterations)
    {
        z = complex_sum(complex_sqrt(z), c);
        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            color = convert_range(i, fractal->iterations, BLACK, WHITE);
            my_mlx_pixel_put(&fractal->img, x, y, color);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->img, x, y, PINK_FLARE);
}

void    draw(t_fractal *fractal)
{
    int x;
    int y;

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
