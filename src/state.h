/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:48:57 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:51:49 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct	s_fract
{
	double		zoom;
	double		mov_x;
	double		mov_y;
	double		jul_cr;
	double		jul_ci;
	int			type;
	int			max_iterations;
	int			color_scheme;
	int			init;
}				t_fract;

typedef struct	s_game
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			mouse[127];
	int			init_click_x;
	int			init_click_y;
	t_fract		fract;
}				t_game;

#endif
