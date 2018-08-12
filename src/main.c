/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:28:47 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:33:52 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "state.h"
#include "exit.h"
#include "input_handler.h"
#include "color.h"
#include "draw.h"
#include "libft.h"
#include "color_scheme.h"

#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#define MANDELBROT 0
#define JULIA 1
#define BURNING_SHIP 2

void	set_hooks(t_game *g)
{
	mlx_hook(g->window, 17, 0, &f_exit, g);
	mlx_hook(g->window, 6, 0, &motion_handler, g);
	mlx_hook(g->window, 5, 0, &button_released, g);
	mlx_key_hook(g->window, &input_handler, g);
	mlx_mouse_hook(g->window, &mouse_handler, g);
}

void	init_mouse(t_game *g)
{
	int i;

	i = 0;
	while (i < 127)
	{
		g->mouse[i] = 0;
		++i;
	}
}

int		get_fractal(char *str)
{
	int f;

	f = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
		f = 0;
	else if (ft_strcmp(str, "julia") == 0)
		f = 1;
	else if (ft_strcmp(str, "burning_ship") == 0)
		f = 2;
	else
		f_exit_err("Invalid argument(s)");
	return (f);
}

void	init_pos(t_game *g)
{
	g->fract.zoom = 1.0;
	g->fract.mov_x = 0.0;
	g->fract.mov_y = 0.0;
	g->fract.max_iterations = 256;
	g->fract.jul_ci = 0.0;
	g->fract.jul_cr = 0.0;
	g->fract.color_scheme = 0;
	g->fract.init = (g->fract.type == JULIA);
}

#define GBPS game.bits_per_pixel
#define GSZL game.size_line
#define GEND game.endian
#define GIMG game.image

int		main(int argc, char **argv)
{
	t_game	game;
	int		c;

	c = 1;
	if (argc < 2)
		f_exit_err("Usage: fractol 'fractal1' [fractal2]\n\n\
Fractals:\nmandelbrot\njulia\nburning_ship");
	if (argc == 3)
		c = fork();
	if (argc > 3)
		f_exit_err("Too many arguments");
	if (c == 0)
		game.fract.type = get_fractal(argv[2]);
	else
		game.fract.type = get_fractal(argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, RES_X, RES_Y, "fractol");
	game.image = mlx_new_image(game.mlx, RES_X, RES_Y);
	game.img_data = mlx_get_data_addr(GIMG, &GBPS, &GSZL, &GEND);
	init_pos(&game);
	init_mouse(&game);
	set_hooks(&game);
	draw_fractal(&game);
	mlx_loop(game.mlx);
	return (0);
}
