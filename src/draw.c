/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:41:12 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/24 16:41:51 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "state.h"
#include "color.h"

void	put_pixel(int x, int y, int color, t_game *g)
{
	t_rgb			rgb;
	unsigned int	n_color;

	n_color = mlx_get_color_value(g->mlx, color);
	rgb = int_to_rgb(n_color);
	g->img_data[x * (g->bits_per_pixel / 8) + 0 + y * g->size_line] = rgb.b;
	g->img_data[x * (g->bits_per_pixel / 8) + 1 + y * g->size_line] = rgb.g;
	g->img_data[x * (g->bits_per_pixel / 8) + 2 + y * g->size_line] = rgb.r;
	g->img_data[x * (g->bits_per_pixel / 8) + 3 + y * g->size_line] = 0;
}
