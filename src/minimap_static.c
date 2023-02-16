/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:21:36 by ralves-g          #+#    #+#             */
/*   Updated: 2023/02/16 15:01:00 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map_door_s(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == 'D' || cub->map[y][x] == 'd')
				print_map_door2_s(cub, x * (*mp_unit()), y
					* (*mp_unit()), cub->map[y][x]);
		}
	}
}

void	print_map_door2_s(t_cub *cub, int m_x, int m_y, char chr)
{
	t_coords	c;
	t_wall		w;

	c.y = m_y - 1;
	while (++c.y < m_y + (*mp_unit()))
	{
		c.x = m_x - 1;
		while (++c.x < m_x + (*mp_unit()))
		{
			w.offset = 0;
			w.color = 0xFFFF0000;
			if (chr == 'D')
				minimap_wall_pixel_s(cub, c, w, 0);
			else
				minimap_wall_pixel_s(cub, c, w, 2);
		}
	}
}

void	minimap_wall_pixel_s(t_cub *cub, t_coords c, t_wall w, int mode)
{
	double	new_x;
	double	new_y;

	new_x = c.x + w.offset - cub->pos_x * (*mp_unit());
	new_y = c.y + w.offset - cub->pos_y * (*mp_unit());
	if ((cub->tab || (new_x * new_x + new_y * new_y <= MAP_RADIUS * MAP_RADIUS))
		&& check_borders(new_x + cub->mp_x, new_y + cub->mp_y))
	{
		if (!mode)
			my_mlx_pixel_put_add(&(cub->frame), new_x + cub->mp_x,
				new_y + cub->mp_y, w.color);
		else if (mode == 1)
			my_mlx_pixel_put(&(cub->frame), new_x + cub->mp_x,
				new_y + cub->mp_y, 0x00FFFFFF);
		else
		{
			my_mlx_pixel_put_door(&(cub->frame), new_x + cub->mp_x,
				new_y + cub->mp_y);
		}
	}
}

void	print_minimap_wall_s(t_cub *cub, int m_x, int m_y)
{
	t_coords	c;
	t_wall		w;

	c.y = m_y - 1;
	while (++c.y < m_y + (*mp_unit()))
	{
		c.x = m_x - 1;
		while (++c.x < m_x + (*mp_unit()))
		{
			w.offset = 0;
			w.color = 0xFF00FF00;
			minimap_wall_pixel(cub, c, w, 0);
			w.color = 0xFFFF0000;
			w.offset = -OFFSET;
			minimap_wall_pixel(cub, c, w, 0);
			w.color = 0xFF0000FF;
			w.offset = OFFSET;
			minimap_wall_pixel(cub, c, w, 0);
		}
	}
}

void	print_minimap_s(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	if (cub->tab)
	{
		cub->mp_x = CUB_W / 2;
		cub->mp_y = CUB_H / 2;
	}
	else
	{
		cub->mp_x = CUB_W - MAP_RADIUS * 1.2;
		cub->mp_y = MAP_RADIUS * 1.2;
	}
	if (!cub->tab)
		print_outline(cub);
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == '1')
				print_minimap_wall_s(cub, x * (*mp_unit()), y * (*mp_unit()));
		}
	}
}
