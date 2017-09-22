#define WINX 1920
#define WINY 1080
#define MIDX 960
#define MIDY 540

long double kabs(long double n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int         c_interpol(int color1, int color2, float it)
{
    unsigned char     r1;
    unsigned char     g1;
    unsigned char     b1;
    unsigned char     r2;
    unsigned char     g2;
    unsigned char     b2;
    unsigned char     r3;
    unsigned char     g3;
    unsigned char     b3;
    int     color;

    color = 0;
    r1 = (0x00FF0000 & color1) >> 16;
    g1 = (0x0000FF00 & color1) >> 8;
    b1 = (0x000000FF & color1);
    r2 = (0x00FF0000 & color2) >> 16;
    g2 = (0x0000FF00 & color2) >> 8;
    b2 = (0x000000FF & color2);
    r3 = r1 + (r2 - r1) * it;
    g3 = g1 + (g2 - g1) * it;
    b3 = b1 + (b2 - b1) * it;
    color = (r3 << 16) + (g3 << 8) + b3;

    return (color);
}

__kernel void fractal(
                        __global char *output,
                        int winx,
                        int winy,
                        double dec_x,
                        double dec_y,
                        double zoom,
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
    long double     tmp;
    int             color;
    long double     z;
    long double     nu;
    float            log_zn;
    float            it_color;
    int             color1;
    int             color2;
    int             palette[16];

    palette[0] = 0x0019081A;
    palette[1] = 0x0009032E;
    palette[2] = 0x00050848;
    palette[3] = 0x00010E62;
    palette[4] = 0x00103088;
    palette[5] = 0x001D55AE;
    palette[6] = 0x003D7FCE;
    palette[7] = 0x0088B6E3;
    palette[8] = 0x00D4ECF7;
    palette[9] = 0x00F1E8C1;
    palette[10] = 0x00F7C867;
    palette[11] = 0x00FDA929;
    palette[12] = 0x00CA7F1E;
    palette[13] = 0x00985712;
    palette[14] = 0x0069340B;
    palette[15] = 0x00411E11;
    color = 0;
    id = get_global_id(0);
    x = id % winx;
    y = id / winx;
    img_x = (long double)x + dec_x - MIDX;
    img_y = (long double)y + dec_y - MIDY;

    if (fract == 0)
        {
            c_r = (img_x / 200) * zoom;
            c_i = (img_y / 200) * zoom;
            z_r = ((long double)mousex - MIDX) / WINX * 3;
            z_i = ((long double)mousey - MIDY) / WINY * 3;
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
                log_zn = log((float)(z_r * z_r) + (float)(z_i * z_i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
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
                log_zn = log((float)(z_r * z_r) + (float)(z_i * z_i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 2)
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
                z_r = kabs(z_r);
                z_i = 2 * z_i * tmp + c_i;
                z_i = kabs(z_i);
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z_r * z_r) + (float)(z_i * z_i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
}
