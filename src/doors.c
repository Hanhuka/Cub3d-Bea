/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanhuka <hanhuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:23:52 by hanhuka           #+#    #+#             */
/*   Updated: 2023/02/16 01:35:24 by hanhuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_close_door(t_cub *cub)
{
	if (cub->map[(int)(cub->pos_y + cub->dir_y)]
		[(int)(cub->pos_x + cub->dir_x)] == 'D')
		cub->map[(int)(cub->pos_y + cub->dir_y)]
		[(int)(cub->pos_x + cub->dir_x)] = 'd';
	else if (cub->map[(int)(cub->pos_y + cub->dir_y)]
			[(int)(cub->pos_x + cub->dir_x)] == 'd'
		&& ((int)(cub->pos_y) != (int)(cub->pos_y + cub->dir_y)
		|| (int)(cub->pos_x) != (int)(cub->pos_x + cub->dir_x)))
		cub->map[(int)(cub->pos_y + cub->dir_y)]
		[(int)(cub->pos_x + cub->dir_x)] = 'D';
}
