/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:03 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/23 17:17:57 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

//INTERSECTION AND DISTANCE TO VIEWPORT
// int32_t	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
	
// 	t_vector O;
// 	t_vector B;
// 	t_vector C;
// 	t_vector V;
// 	t_ray	ray;

	
// 	O.x = 0.0f;
// 	O.y = 0.0f;
// 	O.z = 0.0f;
// 	B.x = 1.0f;
// 	B.y = 0.6f;
// 	B.z = 0.0f;
	
	

// 	V.x = 0.0f;
// 	V.y = 0.0f;
// 	V.z = 1.0f;
// 	C.x = 0.0f;
// 	C.y = 0.0f;
// 	C.z = 5.0f;
// 	double r = 1.0f;
	
// 	calc_ray(&ray, O, V);
// 	print_ray("RAY:", ray, 1);


// 	t_vector co = ft_substractv(&O, &C);
// 	print_vector("CO:", co);
// 	double a = ft_dotp(&ray.direction, &ray.direction);
// 	double b = 2 * ft_dotp(&co, &ray.direction);
// 	double c = ft_dotp(&co, &co) - r*r;
// 	printf("a:%f\nb:%f\nc:%f\n", a, b, c); 
// 	double t = ft_midnight(a, b, c);
// 	t_vector intersect = ft_calculate_point(&ray, t);
// 	print_vector("INTERSECT:", intersect);
// 	printf("t_min:%f\n", t);
// 	double distance = distance_vp_camera();
// 	printf("Distance: %f\n", distance);
// 	return (0);
// }

//VIEWPORT COORDIANTES
// int main(void)
// {
// 	t_viewport *vp;
// 	t_alloc *allocations;
	
// 	allocations = ft_calloc(sizeof(t_alloc), 1);
// 	vp = viewport_coordinates(*allocations);
	
// 	int width = 512;
// 	int height = 384;
// 	printf("PIXEL X: %d, PIXEL Y: %d = x: %f y: %f\n", width + 1, height + 1, vp->x[width], vp->y[height]);

// 	int i = 0;
// 	int j = 0;
// 	while (i < HEIGHT)
// 	{
// 		while (j < WIDTH)
// 		{
// 			// printf("PIXEL X: %d, PIXEL Y: %d = x: %f y: %f\n", j, i, vp->x[j], vp->y[i]);
// 			j ++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }

//SEND RAYS THROUGH VP & INTERSECT WITH A SPHERE
// int main(void)
// {
// 	t_vector O;
// 	t_vector C;
// 	t_ray	ray;
// 	t_sphere s;
// 	t_vector intersect;
// 	O.x = 0.0f;
// 	O.y = 0.0f;
// 	O.z = 0.0f;
	
// 	C.x = 0.0f;
// 	C.y = 0.0f;
// 	C.z = 3.0f;
// 	s.centre = C;
// 	s.radius = 2.0f;
	
// 	t_viewport *vp;
// 	t_alloc *allocations;
// 	t_vector *vp_coord;
	
// 	allocations = ft_calloc(sizeof(t_alloc), 1);
// 	vp = viewport_coordinates(allocations);
// 	vp_coord = viewport_coord_into_points(*vp, allocations);
// 	// double distance = distance_vp_camera();
// 	int i = 0;
// 	while(i < (WIDTH * HEIGHT))
// 	{
// 		send_ray(&ray, O, vp_coord[i]);
// 		while (ray.bounces < BOUNCES)
// 		{
// 			intersect = ft_intersection_s(s, &ray);
// 			if (intersect.x == -1.0f && intersect.y == -1.0f && intersect.z == -1.0f)
// 				break ;
// 			// ray.direction = ft_calculate_angle(&ray, obj, intersect) //calculates the returned angle of the new ray
// 			// ray.rgb = ft_calculate_color(&ray, obj, intersect) // updates the color for that ray
// 			// calc_ray(&ray, intersect); // intersect will be the new ray.origin
// 			ray.bounces++;
// 		}
// 		// (void) intersect;
// 		// printf("t: %f\n", t);
// 		printf("intersect_x: %f\n", intersect.x);
// 		printf("intersect_y: %f\n", intersect.y);
// 		printf("intersect_z: %f\n", intersect.z);
// 		// print_ray("RAY[i]", ray, t);
// 		i++;
// 	}
// 	ft_cleanup(allocations);
// 	free(vp);
// 	system("leaks miniRT");
// }

//RENDER SPHERE WITHOUT BOUNCES AND LIGHT
int main(void)
{
	//POINTS AND VECTORS
	t_vector O;
	t_vector C;
	t_ray	ray;
	t_obj obj;
	t_obj obj_bg;
	t_sphere s;
	t_bg bg;
	t_vector intersect;
	
	O.x = 0.0f;
	O.y = 0.0f;
	O.z = 0.0f;
	
	C.x = 0.0f;
	C.y = 0.0f;
	C.z = 5.0f;
	s.centre = C;
	s.radius = 0.5f;
	s.color.r = 0;
	s.color.g = 0.5;
	s.color.b = 0;
	obj.color = &s.color;
	bg.color.r = 0;
	bg.color.g = 0;
	bg.color.b = 0;
	obj_bg.color = &bg.color;
	
	//VIEWPORT
	t_viewport *vp;
	t_alloc *allocations;
	t_vector *vp_coord;
	allocations = ft_calloc(sizeof(t_alloc), 1);
	vp = viewport_coordinates(allocations);
	vp_coord = viewport_coord_into_points(*vp, allocations);
	
	//MLX
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	int i = 0;
	while(i < (WIDTH * HEIGHT))
	{
		send_ray(&ray, O, vp_coord[i]);
		while (ray.bounces < BOUNCES)
		{
			intersect = ft_intersection_s(s, &ray);
			if (intersect.x == CAMERA_X && intersect.y == CAMERA_Y && intersect.z == CAMERA_Z)
			{
				calculate_color(&ray, obj_bg); // updates the color for a ray which doesn't intersect
				break ;
			}
			calculate_color(&ray, obj); // updates the color for that ray
			ray.bounces++;
		}
		place_pixel(&ray, img);
		ray.bounces = 0;
		i++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_cleanup(allocations);
	free(vp);
	// system("leaks miniRT");
}