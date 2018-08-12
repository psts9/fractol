/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:45:45 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:03:56 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "color_scheme.h"
#include "draw.h"
#include "keys.h"

#define ABS(x) (x < 0 ? -x : x)

static void	set_julia(double *cr, double *ci, t_game *g)
{
	*cr = g->fract.jul_cr;
	*ci = g->fract.jul_ci;
}

int			is_control(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S)
		return (1);
	if (keycode == KEY_ONE || keycode == KEY_TWO)
		return (1);
	if (keycode == KEY_THREE || keycode == KEY_FOUR)
		return (1);
	return (0);
}

int			get_fractal_pixel(t_game *g, double cr, double ci)
{
	double	zr;
	double	zi;
	double	zrsqr;
	double	zisqr;
	int		i;

	zr = (g->fract.type == 1 ? cr : 0);
	zi = (g->fract.type == 1 ? ci : 0);
	if (g->fract.type == 1)
		set_julia(&cr, &ci, g);
	zrsqr = zr * zr;
	zisqr = zi * zi;
	i = 0;
	while (zrsqr + zisqr <= 4.0)
	{
		zi = (zr + zi) * (zr + zi) - zrsqr - zisqr;
		zi += ci;
		zr = zrsqr - zisqr + cr;
		zrsqr = zr * zr;
		zisqr = zi * zi;
		if (i >= g->fract.max_iterations)
			break ;
		++i;
	}
	return (i);
}

int			get_fractal_burning_ship(t_game *g, double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;

	zr = cr;
	zi = ci;
	i = 0;
	while (zr * zr + zi * zi <= 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = ABS(2 * zr * zi) + ci;
		zr = ABS(temp);
		if (i >= g->fract.max_iterations)
			break ;
		++i;
	}
	return (i);
}

#define GZOOM g->fract.zoom
#define GMOVX g->fract.mov_x
#define GMOVY g->fract.mov_y
#define GMAXI g->fract.max_iterations
#define GCOLS g->fract.color_scheme
#define DRESX (double)RES_X
#define DRESY (double)RES_Y

void		do_fract(t_game *g, int x, int y)
{
	double	cr;
	double	ci;
	int		color;

	color = 0;
	cr = (DRESX / DRESY) * (x - RES_X / 2.0) / (GZOOM * RES_X / 2.0) + GMOVX;
	ci = (y - RES_Y / 2.0) / (GZOOM * RES_Y / 2.0) - GMOVY;
	if (g->fract.type == 0 || g->fract.type == 1)
		color = set_color(get_fractal_pixel(g, cr, ci), GMAXI, GCOLS);
	else if (g->fract.type == 2)
		color = set_color(get_fractal_burning_ship(g, cr, ci), GMAXI, GCOLS);
	put_pixel(x, y, color, g);
}
