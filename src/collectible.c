/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:46:57 by bshintak          #+#    #+#             */
/*   Updated: 2023/02/24 15:49:59 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_collectible(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	cub->parsing_collectible = 0;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == 'B')
				cub->parsing_collectible = 1;
		}
	}
	if (!cub->parsing_collectible)
		return (0);
	cub->collec.img = mlx_xpm_file_to_image(cub->mlx, BATTERY_TEXTURE,
			&cub->collec.x_size, &cub->collec.y_size);
	if (!cub->collec.img)
		return (1);
	cub->collec.addr = mlx_get_data_addr(cub->collec.img,
			&cub->collec.bits_per_pixel, &cub->collec.line_length,
			&cub->collec.endian);
	return (0);
}

void	print_map_collectible2(t_cub *cub, int m_x, int m_y, char chr)
{
	t_coords	c;
	t_wall		w;

	w.angle = atan2(-cub->dir_y, cub->dir_x) - M_PI_2;
	c.y = m_y - 1;
	while (++c.y < m_y + (*mp_unit()))
	{
		c.x = m_x - 1;
		while (++c.x < m_x + (*mp_unit()))
		{
			w.offset = 0;
			w.color = 0xFF00FF00;
			if (chr == 'B')
				minimap_wall_pixel(cub, c, w, 0);
			else
				minimap_wall_pixel(cub, c, w, 2);
		}
	}
}

void	print_map_collectible(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == 'B')
				print_map_collectible2(cub, x * (*mp_unit()), y
					* (*mp_unit()), cub->map[y][x]);
		}
	}
}

void	print_map_collectible_s(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == 'B')
				print_map_collectible2_s(cub, x * (*mp_unit()), y
					* (*mp_unit()), cub->map[y][x]);
		}
	}
}

void	print_map_collectible2_s(t_cub *cub, int m_x, int m_y, char chr)
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
			if (chr == 'B')
				minimap_wall_pixel_s(cub, c, w, 0);
			else
				minimap_wall_pixel_s(cub, c, w, 2);
		}
	}
}
