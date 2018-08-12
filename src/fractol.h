/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:44:13 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:52:20 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "state.h"

# define RES_X 600
# define RES_Y 400

void	draw_fractal(t_game *g);
void	do_fract(t_game *g, int x, int y);
int		is_control(int keycode);

#endif
