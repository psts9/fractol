/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:36:42 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 17:36:53 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		rgb_to_int(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

t_rgb	int_to_rgb(int color)
{
	t_rgb rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}
