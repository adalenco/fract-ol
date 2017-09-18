__kernel void fractal(
                        __global char *output,
                        int winx,
                        int winy,
                        int dec_x,
                        int dec_y,
                        long double  zoom,
                        int     s_l,
                        int     endian,
                        int  it)
{
    int         id;
    int         x;
    int         y;
    long double      img_x;
    long double      img_y;
    long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
    long double      x1;
    long double      x2;
    long double      y1;
    long double      y2;
    int             i;
    long double      tmp;
    int              color;

    color = 0;
    id = get_global_id(0);
    x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	img_x = (x2 - x1) * zoom;
	img_y = (y2 - y1) * zoom;
    x = id % winx;
    y = id / winx;
    c_r = (x + dec_x - (winx / 2)) / zoom;
    c_i = (y + dec_y - (winy / 2)) / zoom;
    z_r = 0;
    z_i = 0;
    i = 0;
    while (z_r * z_r + z_i * z_i < 4 && i < it)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    }
    if (i == it)
    {
        color = 0x00000000;
        ((__global unsigned int *)output)[id] = color;
    }
    else
    {
        color = 0x00FFFFFF - (i * 15000);
        ((__global unsigned int *)output)[id] = color;
    }

}
