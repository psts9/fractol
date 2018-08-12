/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 17:42:04 by pthorell          #+#    #+#             */
/*   Updated: 2018/08/11 17:43:27 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	f_exit(void)
{
	exit(1);
	return (0);
}

int	f_exit_err(char *str)
{
	ft_putendl(str);
	return (f_exit());
}
