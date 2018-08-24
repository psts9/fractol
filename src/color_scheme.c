/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:33:56 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/24 16:41:14 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int	scheme_ultrafractal(int i)
{
	int col_uf[16];

	i %= 16;
	col_uf[0] = rgb_to_int(66, 30, 15);
	col_uf[1] = rgb_to_int(25, 7, 26);
	col_uf[2] = rgb_to_int(9, 1, 47);
	col_uf[3] = rgb_to_int(4, 4, 73);
	col_uf[4] = rgb_to_int(0, 7, 100);
	col_uf[5] = rgb_to_int(12, 44, 138);
	col_uf[6] = rgb_to_int(24, 82, 177);
	col_uf[7] = rgb_to_int(57, 125, 209);
	col_uf[8] = rgb_to_int(134, 181, 229);
	col_uf[9] = rgb_to_int(211, 236, 248);
	col_uf[10] = rgb_to_int(241, 233, 191);
	col_uf[11] = rgb_to_int(248, 201, 95);
	col_uf[12] = rgb_to_int(255, 170, 0);
	col_uf[13] = rgb_to_int(204, 128, 0);
	col_uf[14] = rgb_to_int(153, 87, 0);
	col_uf[15] = rgb_to_int(106, 52, 3);
	return (col_uf[i]);
}

static int	scheme_frosty(int i)
{
	int col_uf[21];

	i %= 21;
	col_uf[0] = rgb_to_int(0, 0, 20);
	col_uf[1] = rgb_to_int(0, 4, 25);
	col_uf[2] = rgb_to_int(0, 9, 30);
	col_uf[3] = rgb_to_int(0, 12, 35);
	col_uf[4] = rgb_to_int(0, 14, 40);
	col_uf[5] = rgb_to_int(0, 20, 45);
	col_uf[6] = rgb_to_int(0, 22, 50);
	col_uf[7] = rgb_to_int(0, 24, 55);
	col_uf[8] = rgb_to_int(0, 26, 60);
	col_uf[9] = rgb_to_int(0, 28, 65);
	col_uf[10] = rgb_to_int(0, 30, 70);
	col_uf[11] = rgb_to_int(25, 89, 179);
	col_uf[12] = rgb_to_int(50, 108, 188);
	col_uf[13] = rgb_to_int(75, 127, 197);
	col_uf[14] = rgb_to_int(100, 146, 206);
	col_uf[15] = rgb_to_int(125, 165, 215);
	col_uf[16] = rgb_to_int(150, 184, 224);
	col_uf[17] = rgb_to_int(175, 203, 233);
	col_uf[18] = rgb_to_int(200, 222, 242);
	col_uf[19] = rgb_to_int(225, 241, 251);
	col_uf[20] = rgb_to_int(255, 255, 255);
	return (col_uf[i]);
}

static int	scheme_grayscale(int i)
{
	int col_uf[16];

	i %= 16;
	col_uf[0] = rgb_to_int(40, 40, 40);
	col_uf[1] = rgb_to_int(60, 60, 60);
	col_uf[2] = rgb_to_int(80, 80, 80);
	col_uf[3] = rgb_to_int(100, 100, 100);
	col_uf[4] = rgb_to_int(120, 120, 120);
	col_uf[5] = rgb_to_int(140, 140, 140);
	col_uf[6] = rgb_to_int(160, 160, 160);
	col_uf[7] = rgb_to_int(180, 180, 180);
	col_uf[8] = rgb_to_int(200, 200, 200);
	col_uf[9] = rgb_to_int(180, 180, 180);
	col_uf[10] = rgb_to_int(160, 160, 160);
	col_uf[11] = rgb_to_int(140, 140, 140);
	col_uf[12] = rgb_to_int(120, 120, 120);
	col_uf[13] = rgb_to_int(100, 100, 100);
	col_uf[14] = rgb_to_int(80, 80, 80);
	col_uf[15] = rgb_to_int(60, 60, 60);
	return (col_uf[i]);
}

static int	scheme_sewer(int i)
{
	int col_uf[2];

	i %= 2;
	col_uf[0] = rgb_to_int(255, 255, 255);
	col_uf[1] = rgb_to_int(255, 0, 0);
	return (col_uf[i]);
}

int			set_color(int iter, int max_iterations, int scheme)
{
	int color;

	color = 0;
	if (iter < max_iterations && iter > 0)
	{
		if (scheme == 0)
			color = scheme_ultrafractal(iter);
		else if (scheme == 1)
			color = scheme_frosty(iter);
		else if (scheme == 2)
			color = scheme_grayscale(iter);
		else if (scheme == 3)
			color = scheme_sewer(iter);
	}
	return (color);
}
