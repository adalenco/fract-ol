#define WINX 1920
#define WINY 1080
#define MIDX 960
#define MIDY 540

typedef struct   s_complex
{
    long double  i;
    long double  r;
}                t_complex;

t_complex mult_complex(t_complex z1, t_complex z2)
{
    t_complex res;

    res.r = z1.r * z2.r - z1.i * z2.i;
    res.i = z1.r * z2.i + z1.i * z2.r;
    return (res);
}

t_complex	power_complex(t_complex z, int n)
{
	t_complex	res;
	int			i;

	i = 1;
	res = z;
	while (i < n)
	{
		res = mult_complex(res, z);
		i++;
	}
	return (res);
}

t_complex   mult_real(t_complex z, int i)
{
    t_complex res;

    res.r = z.r * i;
    res.i = z.i * i;
    return (res);
}

t_complex  add_complex(t_complex z1, t_complex z2)
{
    t_complex res;

    res.r = z1.r + z2.r;
    res.i = z1.i + z2.i;
    return (res);
}

t_complex sub_complex(t_complex z1, t_complex z2)
{
    t_complex res;

    res.r = z1.r - z2.r;
    res.i = z1.i - z2.i;
    return (res);
}

t_complex   conj_complex(t_complex z)
{
     t_complex res;

     res.r = z.r;
     res.i = -z.i;
     return (res);
}

long double   modsquare_complex(t_complex z)
{
    return (z.r * z.r + z.i * z.i);
}

t_complex     div_complex(t_complex z1, t_complex z2)
{
    t_complex res;

    res = mult_complex(z1, conj_complex(z2));
    res.r = res.r / modsquare_complex(z2);
    res.i = res.i / modsquare_complex(z2);
    return (res);
}

t_complex   div_real(t_complex z1, t_complex z2)
{
    t_complex res;

    res.r = z1.r / z2.r;
    res.i = z1.i / z2.r;
    return (res);
}

t_complex   p_3(t_complex z)
{
    t_complex res;

	res = mult_complex(z, z);
	res = mult_complex(res, z);
	res.r -= 1;
	return (res);
}

t_complex   p_5(t_complex z)
{
    t_complex res;

    res = mult_complex(z, z);
    res = mult_complex(res, z);
	res = mult_complex(res, z);
	res = mult_complex(res, z);
    res.r -= 1;
    return (res);
}

t_complex	p_3_moins(t_complex z)
{
	t_complex	res;

	res = p_3(z);
	res = sub_complex(res, mult_real(z, 2));
	res.r += 2;
	return (res);
}

t_complex   p_hyp(t_complex z)
{
    t_complex res;

    res.r = cos((double)z.r) * cos((double)z.i);
	res.i = sinh((double)z.r) * sin((double)z.i);
	res.r -= 1;

	return (res);
}

t_complex	p_6_3(t_complex z)
{
	t_complex	res;

	res = p_5(z);
	res = mult_complex(res, z);
	res = add_complex(res, p_3(z));
	res.r -= 1;
	return (res);
}

t_complex	p_sin(t_complex z)
{
	t_complex res;

	res.r = sin((double)z.r) * cosh((double)z.i);
	res.i = cos((double)z.r) * sinh((double)z.i);
	res.r -= 1;
	return (res);
}

t_complex	p(t_complex z, int n)
{
	if (n == 0)
		return (p_3(z));
	else if (n == 1)
		return (p_5(z));
	else if (n == 2)
		return (p_6_3(z));
	else if (n == 3)
		return (p_3_moins(z));
	else if (n == 4)
		return (p_sin(z));
	return (p_hyp(z));
}

t_complex   p_prime(t_complex z, t_complex h, int n)
{
    t_complex res;

    res = sub_complex(p(add_complex(z, h), n), p(z, n));
    res = div_real(res, h);
    return (res);
}

t_complex   zn_plus(t_complex z, t_complex h, int n)
{
    t_complex res;

    res = sub_complex(z, div_complex(p(z, n), p_prime(z, h, n)));
    return (res);
}

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
    int               color;

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

void        c_palette1(int palette[16])
{
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
}

void        c_palette2(int palette[16])
{
    palette[0] = 0x00FBFF12;
    palette[1] = 0x00FF206E;
    palette[2] = 0x00FD5200;
    palette[3] = 0x00A01A7D;
    palette[4] = 0x003A86FF;
    palette[5] = 0x0092BFB1;
    palette[6] = 0x00F2BB05;
    palette[7] = 0x000CAADC;
    palette[8] = 0x0082FF9E;
    palette[9] = 0x008F3985;
    palette[10] = 0x00E28413;
    palette[11] = 0x0059CD90;
    palette[12] = 0x00DD403A;
    palette[13] = 0x00d00000;
    palette[14] = 0x00FF0054;
    palette[15] = 0x00390099;
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
                        int mousey,
                        char pal,
						int newton,
						char ncolor,
                        int mult)
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
    long double     nu;
    float           log_zn;
    float           it_color;
    int             color1;
    int             color2;
    int             palette[16];
    long double     m;
    t_complex       z;
    t_complex       z2;

    if (pal == 1)
        c_palette1(palette);
    else if (pal == 2)
        c_palette2(palette);
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
            while (z_r * z_r + z_i * z_i < 400 && i < it)
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
                log_zn = log((float)(z_r * z_r) + (float)(z_i * z_i)) / 2;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                if (it_color < 0)
                    it_color = 0;
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
            while (z_r * z_r + z_i * z_i < 400 && i < it)
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
                if (it_color < 0)
                    it_color = 0;
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
            while (z_r * z_r + z_i * z_i < 400 && i < it)
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
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 3)
        {
            c_r = (img_x / 200) * zoom;
            c_i = (img_y / 200) * zoom;
            z_r = 0;
            z_i = 0;
            i = 0;
            while (z_r * z_r + z_i * z_i < 400 && i < it)
            {
                tmp = z_r;
                z_r = kabs(z_r * z_r - z_i * z_i) + c_r;
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
        else if (fract == 4)
        {
            c_r = (img_x / 200) * zoom;
            c_i = (img_y / 200) * zoom;
            z_r = 0;
            z_i = 0;
            i = 0;
            while (z_r * z_r + z_i * z_i < 400 && i < it)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i - c_r;
                z_i = -2 * z_i * tmp + c_i;
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
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 5)
        {
            c_r = ((-img_y / 200) * zoom);
            c_i = ((img_x / 200) * zoom);
            z_r = c_r;
            z_i = c_i;
            i = 0;
            while (z_r * z_r + z_i * z_i < 400 && i < it)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i - c_r;
                z_i = -2 * z_i * tmp + c_i;
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
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 6)
        {
            c_r = ((-img_y / 200) * zoom);
            c_i = ((img_x / 200) * zoom);
            m = c_r * c_r + c_i * c_i;
            c_r = c_r / m;
            c_i = -c_i / m;
            z_r = c_r;
            z_i = c_i;
            i = 0;
            while (z_r * z_r + z_i * z_i < 400 && i < it)
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
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 7)
        {
            t_complex h;
            long double eps;
            h.r = 0.0001;
            h.i = 0;
            z.r = ((img_x / 200) * zoom);
            z.i = ((img_y / 200) * zoom);
            i = 0;
            eps = 0.1;
            while (eps > 0.001 && i < it)
            {
                i++;
                z2 = zn_plus(z, h, newton);
                eps = modsquare_complex(sub_complex(z2, z));
                z = z2;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
				if (ncolor == 1)
				{
					log_zn = log((double)(z.r * z.r) + (double)(z.i * z.i)) / 2.0;
					nu = log(log_zn / log(2.0)) / log(2.0);
					it_color = i + 1 - nu;
					if (it_color < 0)
					it_color = 0;
					color1 = palette[(int)floor(it_color) % 16];
					color2 = palette[((int)floor(it_color) + 1) % 16];
				}
				else
				{
					color1 = palette[(int)i % 16];
					color2 = palette[((int)i + 1) % 16];
				}
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
		else if (fract == 8)
		{
			z2.r = (img_x / 200) * zoom;
            z2.i = (img_y / 200) * zoom;
            z.r = ((long double)mousex - MIDX) / WINX * 3;
            z.i = ((long double)mousey - MIDY) / WINY * 3;
            i = 0;
            while (modsquare_complex(z) < 400 && i < it)
            {
                z = add_complex(power_complex(z, mult), z2);
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z.r * z.r) + (float)(z.i * z.i)) / 2;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }

		}
        else if (fract == 9)
        {
            t_complex z3;
            z2.r = ((-img_y / 200) * zoom);
            z2.i = ((img_x / 200) * zoom);
            z3.r = modsquare_complex(z2);
            z2 = div_real(z2, z3);
            z.r = z2.r;
            z.i = z2.i;
            i = 0;
            while (modsquare_complex(z) < 400 && i < it)
            {
                z = add_complex(power_complex(z, mult), z2);
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z.r * z.r) + (float)(z.i * z.i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 10)
        {
            z2.r = (img_x / 200) * zoom;
            z2.i = (img_y / 200) * zoom;
            z.r = 0;
            z.i = 0;
            i = 0;
            while (modsquare_complex(z) < 400 && i < it)
            {
                z = add_complex(power_complex(z, mult), z2);
                z.r = kabs(z.r);
                z.i = kabs(z.i);
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z.r * z.r) + (float)(z.i * z.i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 11)
        {
            z.r = (img_x / 200) * zoom;
            z.i = (img_y / 200) * zoom;
            z2.r = ((double)mousex - MIDX) / winx * 3;
            z2.i = ((double)mousey - MIDY) / winy * 3;
            i = 0;
            while (modsquare_complex(z) < 400 && i < it)
            {
                z = add_complex(power_complex(z, mult), z2);
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z.r * z.r) + (float)(z.i * z.i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                if (it_color < 0)
                    it_color = 0;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 12)
        {
            z2.r = (img_x / 200) * zoom;
            z2.i = (img_y / 200) * zoom;
            z.r = 0;
            z.i = 0;
            i = 0;
            while (modsquare_complex(z) < 400 && i < it)
            {
                z = power_complex(z, mult);
                z.r = kabs(z.r);
                z = add_complex(z, z2);
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z.r * z.r) + (float)(z.i * z.i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
        else if (fract == 13)
        {
            z2.r = (img_x / 200) * zoom;
            z2.i = (img_y / 200) * zoom;
            z.r = 0;
            z.i = 0;
            i = 0;
            while (modsquare_complex(z) < 400 && i < it)
            {
                z = power_complex(z, mult);
                z.r = z.r - z2.r;
                z.i = -z.i + z2.i;
                i++;
            }
            if (i == it)
            {
                color = 0x00000000;
                ((__global unsigned int *)output)[id] = color;
            }
            else
            {
                log_zn = log((float)(z.r * z.r) + (float)(z.i * z.i)) / 2.0;
                nu = log(log_zn / log(2.0)) / log(2.0);
                it_color = i + 1 - nu;
                color1 = palette[(int)floor(it_color) % 16];
                color2 = palette[((int)floor(it_color) + 1) % 16];
                ((__global unsigned int *)output)[id] = c_interpol(color1, color2, it_color - floor(it_color));
            }
        }
}
