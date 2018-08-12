/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:34:24 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:47:18 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "state.h"
#include "mlx.h"
#include "color_scheme.h"
#include "draw.h"
#include <pthread.h>

void	*draw_fractal_tl(void *v)
{
	int		x;
	int		y;
	t_game	*g;

	y = 0;
	g = v;
	while (y < RES_Y / 2)
	{
		x = 0;
		while (x < RES_X / 2)
		{
			do_fract(g, x, y);
			++x;
		}
		++y;
	}
	return (NULL);
}

void	*draw_fractal_tr(void *v)
{
	int		x;
	int		y;
	t_game	*g;

	y = 0;
	g = v;
	while (y < RES_Y / 2)
	{
		x = RES_X / 2;
		while (x < RES_X)
		{
			do_fract(g, x, y);
			++x;
		}
		++y;
	}
	return (NULL);
}

void	*draw_fractal_bl(void *v)
{
	int		x;
	int		y;
	t_game	*g;

	y = RES_Y / 2;
	g = v;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X / 2)
		{
			do_fract(g, x, y);
			++x;
		}
		++y;
	}
	return (NULL);
}

void	*draw_fractal_br(void *v)
{
	int		x;
	int		y;
	t_game	*g;

	y = RES_Y / 2;
	g = v;
	while (y < RES_Y)
	{
		x = RES_X / 2;
		while (x < RES_X)
		{
			do_fract(g, x, y);
			++x;
		}
		++y;
	}
	return (NULL);
}

void	draw_fractal(t_game *g)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;

	pthread_create(&thread1, NULL, draw_fractal_tl, g);
	pthread_create(&thread2, NULL, draw_fractal_tr, g);
	pthread_create(&thread3, NULL, draw_fractal_bl, g);
	pthread_create(&thread4, NULL, draw_fractal_br, g);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	mlx_put_image_to_window(g->mlx, g->window, g->image, 0, 0);
}
