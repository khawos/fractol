#include "fractal.h"

double convert_range(double value, double max_src, double min_dst, double max_dst)
{
    return (min_dst + value * (max_dst - min_dst) / max_src);
}

t_complex   complex_sum(t_complex z, t_complex c)
{
    t_complex result;

    result.x = z.x + c.x;
    result.y = z.y + c.y;
    return (result);
}

t_complex   complex_sqrt(t_complex z)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}