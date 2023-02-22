/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:23:52 by hanhuka           #+#    #+#             */
/*   Updated: 2023/02/22 15:17:12 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_doors(t_cub *cub)
{
	if (cub->parsing_doors)
		mlx_destroy_image(cub->mlx, cub->doors.img);
}

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
