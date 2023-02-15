/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanhuka <hanhuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:51:49 by bshintak          #+#    #+#             */
/*   Updated: 2023/02/15 21:06:26 by hanhuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_textures(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (cub->wall_t[i].img)
			mlx_destroy_image(cub->mlx, cub->wall_t[i].img);
}

int	error_init_textures(t_cub *cub)
{
	printf("Error\nInvalid texture path\n");
	free_matrix(cub->map);
	free_textures_char(*cub);
	free_textures(cub);
	free(cub->mlx);
	return (1);
}

int	init_textures(t_cub *cub)
{
	int	i;

	cub->mlx = mlx_init();
	i = -1;
	while (++i < 4)
		cub->wall_t[i].img = NULL;
	i = 0;
	while (i < 4)
	{
		cub->wall_t[i].img = mlx_xpm_file_to_image(cub->mlx, cub->walls[i],
				&cub->wall_t[i].x_size, &cub->wall_t[i].y_size);
		if (!cub->wall_t[i].img)
			return (error_init_textures(cub));
		cub->wall_t[i].addr = mlx_get_data_addr(cub->wall_t[i].img,
				&cub->wall_t[i].bits_per_pixel, &cub->wall_t[i].line_length,
				&cub->wall_t[i].endian);
		i++;
	}
	free_textures_char(*cub);
	return (0);
}
