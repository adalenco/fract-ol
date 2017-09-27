/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:52:31 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/26 13:01:03 by adalenco         ###   ########.fr       */
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
	double				dec_x;
	double				dec_y;
	int					winx;
	int					winy;
	double				zoom;
	int					it;
	char				fract;
	cl_device_id        device_id;
    cl_context          context;
    cl_command_queue    commands;
    cl_program          program;
    cl_kernel           kernel;
    cl_mem              output;
	size_t				global;
	size_t				local;
	size_t				dif;
	unsigned int		count;
	char				*KernelSource;
	int					mousex;
	int					mousey;
	char				mouseact;
	int					button;
	unsigned int		nb_op;
	char				palette;
	int					newton;
	char				ncolor;
	int					mult;
	int					gpu;
}						t_ws;

int						ft_key_funct(int keycode, t_ws *prm);
void					ft_refresh_image(t_ws *param);
void					ft_mandel(t_ws *prm);
int	        			opencl_init(t_ws *prm);
void					opencl_close(t_ws *prm);
int						draw_fractal(t_ws *prm);
int						ft_mouse_hook(int x, int y, t_ws *prm);
int						ft_mouse_clic_hook(int button, int x, int y, t_ws *prm);
void					t_keyfunct(int key, t_ws *prm);
void					zoom_it_keyfunct(int key, t_ws *prm);
void					reset_quit_keyfunct(int key, t_ws *prm);
void					swap_keyfunct(int key, t_ws *prm);
void					options_key(int key, t_ws *prm);
void					mult_keyfunct(int key, t_ws *prm);

#endif
