/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanhuka <hanhuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:53:12 by bshintak          #+#    #+#             */
/*   Updated: 2023/02/15 21:12:53 by hanhuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ceiling_color(t_cub *cub, t_ray *ray, double *start)
{
	while (*start < ray->start)
	{
		if (*start >= 0 && *start <= CUB_H)
			my_mlx_pixel_put(&cub->frame, CUB_W - ray->i - 1,
				*start, cub->color[CEILING]);
		*start += 1;
	}
}

void	floor_color(t_cub *cub, t_ray *ray, double *start)
{
	ray->start = *start + ray->size * 2;
	while (ray->start <= CUB_H)
	{
		my_mlx_pixel_put(&cub->frame, CUB_W - ray->i - 1,
			ray->start, cub->color[FLOOR]);
		ray->start++;
	}
}

void	textures(t_cub *cub, t_ray *ray, double *start, int *side)
{
	double	tmp_start;
	int		tmp_side;

	tmp_start = *start;
	tmp_side = *side;
	my_mlx_pixel_put(&cub->frame, CUB_W - ray->i - 1, ray->start,
		get_image_color(&cub->wall_t[tmp_side], cub->wall_t[tmp_side].x_size
			- cub->wall_t[tmp_side].x_size * ray->wall_x,
			cub->wall_t[tmp_side].y_size
			* ((ray->start - tmp_start + 1) / ray->size)));
	*start = tmp_start;
	*side = tmp_side;
}

void	reflections(t_cub *cub, t_ray *ray, double *start, int *side)
{
	double	tmp_start;
	int		tmp_side;

	tmp_start = *start;
	tmp_side = *side;
	my_mlx_pixel_put(&cub->frame, CUB_W - ray->i - 1,
		tmp_start * 2 + ray->size * 2 - ray->start, cub->color[FLOOR]);
	my_mlx_pixel_put_sub(&cub->frame, CUB_W - ray->i - 1,
		tmp_start * 2 + ray->size * 2 - ray->start,
		get_image_color(&cub->wall_t[tmp_side], cub->wall_t[tmp_side].x_size
			- cub->wall_t[tmp_side].x_size * ray->wall_x,
			cub->wall_t[tmp_side].y_size
			* ((ray->start - tmp_start + 1) / ray->size)));
	my_mlx_pixel_put_drk(&cub->frame, CUB_W
		- ray->i - 1, tmp_start * 2 + ray->size * 2 - ray->start);
	my_mlx_pixel_put_drk(&cub->frame, CUB_W - ray->i
		- 1, tmp_start * 2 + ray->size * 2 - ray->start);
	my_mlx_pixel_put_drk(&cub->frame, CUB_W - ray->i
		- 1, tmp_start * 2 + ray->size * 2 - ray->start);
	*start = tmp_start;
	*side = tmp_side;
}

void	print_textures(t_cub *cub, t_ray ray)
{
	double	start;
	int		side;

	start = 0;
	ray.size = ray.end - ray.start;
	side = get_side(ray);
	ceiling_color(cub, &ray, &start);
	start = ray.start;
	if (ray.start < 0)
		ray.start = 0;
	if (ray.end > CUB_H)
		ray.end = CUB_H;
	while (ray.start <= ray.end)
	{
		if (ray.start >= 0 && ray.start <= CUB_H)
			textures(cub, &ray, &start, &side);
		if (start * 2 + ray.size * 2 - ray.start >= 0 && start * 2
			+ ray.size * 2 - ray.start <= CUB_H)
			reflections(cub, &ray, &start, &side);
		ray.start++;
	}
	floor_color(cub, &ray, &start);
}
