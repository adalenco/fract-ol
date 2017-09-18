/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:52:31 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/15 16:57:04 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <complex.h>
# include "../minilibx_macos/mlx.h"
# include "X.h"
# include "libft.h"
# include <stdlib.h>
# include <OpenCL/opencl.h>

typedef struct			s_ws
{
	void				*mlx;
	void				*win;
	void				*img_ptr;
	char				*img_ad;
	int					bpp;
	int					s_l;
	int					endian;
	int					dec_x;
	int					dec_y;
	int					winx;
	int					winy;
	double				zoom;
	int				it;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	cl_device_id        device_id;             // compute device id
    cl_context          context;                 // compute context
    cl_command_queue    commands;          // compute command queue
    cl_program          program;                 // compute program
    cl_kernel           kernel;                   // compute kernel
    cl_mem              output;
	size_t				global;
	size_t				local;
	unsigned int		count;
	char				*KernelSource;

}						t_ws;

int						ft_key_funct(int keycode, t_ws *prm);
void					ft_refresh_image(t_ws *param);
void					ft_mandel(t_ws *prm);
int	        			ft_opencl_init(t_ws *prm);
void					ft_close_opencl(t_ws *prm);
int						ft_calc_fractal(t_ws *prm);

#endif
