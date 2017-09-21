#define WINX 1920
#define WINY 1080
#define MIDX 960
#define MIDY 540

__kernel void fractal(
                        __global char *output,
                        int winx,
                        int winy,
                        double dec_x,
                        double dec_y,
                        double zoom,
                        int     s_l,
                        int     endian,
                        char fract,
                        int  it,
                        int mousex,
                        int mousey)
{
    int             id;
    int             x;
    int             y;
    long double     img_x;
    long double     img_y;
    long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
    int             i;
    long double      tmp;
    int              color;

    color = 0;
    id = get_global_id(0);
    x = id % winx;
    y = id / winx;
    i = 0;
    img_x = (long double)x + dec_x - MIDX;
    img_y = (long double)y + dec_y - MIDY;
    if (fract == 0)
    {
        c_r = (img_x / 200) * zoom;
        c_i = (img_y / 200) * zoom;
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
    else if (fract == 1)
    {
        z_r = (img_x / 200) * zoom;
        z_i = (img_y / 200) * zoom;
        c_r = ((double)mousex - MIDX) / WINX * 3;
        c_i = ((double)mousey - MIDY) / WINY * 3;
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
}
