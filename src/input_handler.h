/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 18:27:07 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 18:27:26 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

# include "state.h"

int	input_handler(int keycode, t_game *g);
int	mouse_handler(int button, int x, int y, t_game *g);
int	motion_handler(int x, int y, t_game *g);
int	button_pressed(int keycode, int x, int y, t_game *g);
int	button_released(int keycode, int x, int y, t_game *g);

#endif
