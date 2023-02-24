/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:20:45 by ralves-g          #+#    #+#             */
/*   Updated: 2023/02/24 16:20:11 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	starting_loop(t_cub *cub)
{
	t_coords	c;

	mlx_mouse_get_pos(cub->mlx, cub->mlx_w, &c.ix, &c.iy);
	mlx_clear_window(cub->mlx, cub->mlx_w);
	mlx_put_image_to_window(cub->mlx, cub->mlx_w, cub->background, 0, 0);
	if (c.ix >= 350 && c.ix <= 650 && c.iy >= 300 && c.iy <= 409)
		mlx_put_image_to_window(cub->mlx, cub->mlx_w, cub->start, 350, 300);
	else
		mlx_put_image_to_window(cub->mlx, cub->mlx_w, cub->start_selected, \
			350, 300);
}

int	game(t_cub *cub)
{
	if (*starting_screen())
		starting_loop(cub);
	else
		raycasting_loop(cub);
	return (1);
}

// print_vars(cub);
int	main(int ac, char **av)
{
	t_cub	cub;

	if (parse_file(ac, av, &cub))
		return (1);
	if (init_textures(&cub))
		return (1);
	ray_main(&cub);
}
