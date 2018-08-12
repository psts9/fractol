/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:05:20 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:21:42 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "exit.h"
#include "keys.h"
#include "mouse.h"
#include "fractol.h"
#include "mlx.h"

#include <string.h>

#define RANGE(x, min, max, a, b) (((b - a) * (x - min)) / (max - min) + a)
#define GZOOM g->fract.zoom
#define INITX g->init_click_x
#define INITY g->init_click_y

static void	get_mouse_pos(int *x, int *y)
{
	if (*x < 0)
		*x = 0;
	else if (*x > RES_X)
		*x = RES_X;
	if (*y < 0)
		*y = 0;
	else if (*y > RES_Y)
		*y = RES_Y;
}

int			button_released(int keycode, int x, int y, t_game *g)
{
	if (keycode == MOUSE_LEFT_CLICK && !g->fract.init)
	{
		get_mouse_pos(&x, &y);
		g->fract.mov_x -= (2.0 * (x - g->init_click_x) / RES_Y) / GZOOM;
		g->fract.mov_y += (2.0 * (y - g->init_click_y) / RES_Y) / GZOOM;
		draw_fractal(g);
	}
	g->mouse[keycode] = 0;
	return (1);
}

int			motion_handler(int x, int y, t_game *g)
{
	int movdx;
	int movdy;

	get_mouse_pos(&x, &y);
	if (g->fract.zoom != 1.0)
		g->fract.init = 0;
	if (g->fract.init && g->fract.type == 1)
	{
		g->fract.jul_cr = RANGE(x, 0, RES_X, -2.0, 2.0);
		g->fract.jul_ci = RANGE(y, 0, RES_Y, 2.0, -2.0);
		draw_fractal(g);
	}
	if (!g->fract.init && g->mouse[MOUSE_LEFT_CLICK])
	{
		mlx_clear_window(g->mlx, g->window);
		movdx = x - INITX;
		movdy = y - INITY;
		mlx_put_image_to_window(g->mlx, g->window, g->image, movdx, movdy);
	}
	return (1);
}

int			input_handler(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		f_exit();
	if (is_control(keycode))
	{
		if (keycode == KEY_ONE || keycode == KEY_TWO)
			g->fract.color_scheme = keycode - KEY_ONE;
		if (keycode == KEY_THREE || keycode == KEY_FOUR)
			g->fract.color_scheme = keycode - KEY_ONE;
		if (keycode == KEY_W)
		{
			if (g->fract.max_iterations < 8192)
				g->fract.max_iterations *= 2;
		}
		if (keycode == KEY_S)
		{
			if (g->fract.max_iterations > 2)
				g->fract.max_iterations /= 2;
		}
		draw_fractal(g);
	}
	return (0);
}

int			mouse_handler(int button, int x, int y, t_game *g)
{
	if (button == MOUSE_SCROLL_UP)
	{
		g->fract.zoom *= 1.1;
		g->fract.mov_x += (x - (RES_X / 2.0)) / ((double)RES_Y * 5.0) / GZOOM;
		g->fract.mov_y -= (y - (RES_Y / 2.0)) / ((double)RES_Y * 4.98) / GZOOM;
		draw_fractal(g);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		g->fract.mov_x -= (x - (RES_X / 2.0)) / ((double)RES_Y * 5.0) / GZOOM;
		g->fract.mov_y += ((double)y - RES_Y / 2.0) / (RES_Y * 4.98) / GZOOM;
		g->fract.zoom /= 1.1;
		draw_fractal(g);
	}
	if (button == MOUSE_LEFT_CLICK || button == MOUSE_RIGHT_CLICK)
	{
		g->mouse[button] = 1;
		g->init_click_x = x;
		g->init_click_y = y;
	}
	return (1);
}
