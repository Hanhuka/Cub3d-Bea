/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanhuka <hanhuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:20:22 by bshintak          #+#    #+#             */
/*   Updated: 2023/02/15 20:21:35 by hanhuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put_drk(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = (*(unsigned int *)dst & 0x00FEFEFE) >> 1;
}

unsigned int	get_image_color(t_data *data, int x, int y)
{
	if (x > data->x_size)
		x = data->x_size;
	if (y > data->y_size)
		y = data->y_size;
	return (*(unsigned int *)(data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8))));
}
