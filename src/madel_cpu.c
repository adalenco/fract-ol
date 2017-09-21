void			ft_mandel(t_ws *prm)
{

	double		img_x;
	double		img_y;
	double		x;
	double		y;
	double		i;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	prm->x1 = -2.1;
	prm->x2 = 0.6;
	prm->y1 = -1.2;
	prm->y2 = 1.2;
	img_x = (prm->x2 - prm->x1) * prm->zoom;
	img_y = (prm->y2 - prm->y1) * prm->zoom;
	x = 0;
	y = 0;
	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			c_r = x / prm->zoom + prm->x1;
			c_i = y / prm->zoom + prm->y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < prm->it)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == prm->it && x + 950 - (prm->zoom) < prm->winx && x + 950 - (prm->zoom) > 0 && y + 540 - (prm->zoom) < prm->winy && y + 540 - (prm->zoom) > 0)
				ft_pixel_to_img(prm, x + 950 - (prm->zoom), y + 540 - (prm->zoom), 0x00000000);
			else if (x + 950 - (prm->zoom) < prm->winx && x + 950 - (prm->zoom) > 0 && y + 540 - (prm->zoom) < prm->winy && y + 540 - (prm->zoom) > 0)
				ft_pixel_to_img(prm, x + 950 - (prm->zoom), y + 540 - (prm->zoom), 0x00000000 + (16 * i));
			y++;
		}
		x++;
	}
}
