/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:42:02 by bshintak          #+#    #+#             */
/*   Updated: 2023/02/18 05:58:59 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	mouse_hook(int code)
{
	t_coords	c;

	if (*starting_screen())
	{
		mlx_mouse_get_pos(mouse_cub()->mlx, mouse_cub()->mlx_w, &c.ix, &c.iy);
		if (c.ix >= 350 && c.ix <= 650 && c.iy >= 300 && c.iy <= 409
			&& code == 1)
		{
			*starting_screen() = 0;
			mlx_mouse_hide(mouse_cub()->mlx, mouse_cub()->mlx_w);
		}
		return (1);
	}
	if (code == WHEEL_UP && *mp_unit() < 20)
		*mp_unit() += 1;
	else if (code == WHEEL_DW && *mp_unit() > 5)
		*mp_unit() -= 1;
	return (0);
}
