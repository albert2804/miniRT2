/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:03 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/28 19:31:50 by aestraic         ###   ########.fr       */
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
//In the Objectlist, the first entry (obj[0]) is always background
// int main(void)
// {
// 	//POINTS AND VECTORS
// 	t_vector O;
// 	t_ray	ray;
// 	t_obj 	*obj;
// 	obj = ft_calloc(sizeof(t_obj), 4);
// 	t_sphere s1;
// 	t_vector C1;
// 	t_sphere s2;
// 	t_vector C2;
// 	t_bg bg;
	
// 	O.x = 0.0f;
// 	O.y = 0.0f;
// 	O.z = 0.0f;
// 	bg.color.r = 0;
// 	bg.color.g = 0;
// 	bg.color.b = 0;
// 	bg.exist = true;
// 	obj[0].color = &bg.color;
// 	obj[0].exist = &bg.exist;
	
// 	C1.x = 1.0f;
// 	C1.y = 0.0f;
// 	C1.z = 10.0f;
// 	C2.x = -1.0f;
// 	C2.y = 0.0f;
// 	C2.z = 10.0f;
// 	s1.centre = C1;
// 	s1.radius = 0.8f;
// 	s1.color.r = 0;
// 	s1.color.g = 0.5;
// 	s1.color.b = 0;
// 	s1.exist = true;
// 	s2.centre = C2;
// 	s2.radius = 0.8f;
// 	s2.color.r = 0;
// 	s2.color.g = 0;
// 	s2.color.b = 0.5;
// 	s2.exist = true;
// 	obj[1].color = &s1.color;
// 	obj[1].exist = &s1.exist;
// 	obj[1].sphere = &s1;
// 	obj[2].color = &s2.color;
// 	obj[2].exist = &s2.exist;
// 	obj[2].sphere = &s2;
	
// 	//VIEWPORT
// 	t_viewport *vp;
// 	t_alloc *allocations;
// 	t_vector *vp_coord;
// 	allocations = ft_calloc(sizeof(t_alloc), 1);
// 	vp = viewport_coordinates(allocations);
// 	vp_coord = viewport_coord_into_points(*vp, allocations);
	
// 	//MLX
// 	mlx_t		*mlx;
// 	mlx_image_t	*img;
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(mlx, img, 0, 0);
	
// 	int i = 0;
// 	int obj_index = 0;
// 	while(i < (WIDTH * HEIGHT))
// 	{
// 		send_ray(&ray, O, vp_coord[i]);
// 		while (ray.bounces < BOUNCES)
// 		{
// 			obj_index = ft_intersection(obj, &ray); //calculates if there is an intersection and with which object
// 			calculate_color(&ray, obj[obj_index]); // updates the color for that ray
// 			ray.bounces++;
// 		}
// 		place_pixel(&ray, img);
// 		ray.bounces = 0;
// 		i++;
// 	}
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	ft_cleanup(allocations);
// 	free(vp);
// 	// system("leaks miniRT");
// }

// // RENDER PLANE WITHOUT BOUNCES AND LIGHT
// int main(void)
// {
// 	//POINTS AND VECTORS
// 	t_vector O;
// 	t_ray	ray;
// 	t_obj 	*obj;
// 	obj = ft_calloc(sizeof(t_obj), 4);
// 	t_plane	p1;
// 	t_plane	p2;
// 	t_vector P1;
// 	t_vector N1;
// 	t_vector P2;
// 	t_vector N2;
// 	t_bg bg;
	
	
// 	O.x = 0.0f;
// 	O.y = 0.0f;
// 	O.z = 0.0f;
// 	bg.color.r = 0;
// 	bg.color.g = 0;
// 	bg.color.b = 0;
// 	bg.exist = true;
// 	obj[0].color = &bg.color;
// 	obj[0].exist = &bg.exist;
	
// 	P1.x = 0;
// 	P1.y = 0.0;
// 	P1.z = 10;
// 	N1.x = 0.0;
// 	N1.y = 0.0;
// 	N1.z = 0.1;
// 	p1.normal = N1;
// 	p1.position = P1;
// 	p1.color.r = 0.0;
// 	p1.color.g = 0.5;
// 	p1.color.b = 0.0;
// 	p1.exist = true;
	
// 	P2.x = 0;
// 	P2.y = 0.0;
// 	P2.z = 10;
// 	N2.x = 0.0;
// 	N2.y = 0.0;
// 	N2.z = 0.0;
// 	p2.normal = N2;
// 	p2.position = P2;
// 	p2.color.r = 0;
// 	p2.color.g = 0;
// 	p2.color.b = 0.5;
// 	p2.exist = true;
	
// 	obj[1].color = &p1.color;
// 	obj[1].exist = &p1.exist;
// 	obj[1].plane = &p1;
// 	obj[2].color = &p2.color;
// 	obj[2].exist = &p2.exist;
// 	obj[2].plane = &p2;
	
// 	// printf("OBJ:%d", *obj[1].exist);
// 	// printf("SPHERE:%d", (obj[1]).sphere->exist);
// 	// exit(0);
	
// 	//VIEWPORT
// 	t_viewport *vp;
// 	t_alloc *allocations;
// 	t_vector *vp_coord;
// 	allocations = ft_calloc(sizeof(t_alloc), 1);
// 	vp = viewport_coordinates(allocations);
// 	vp_coord = viewport_coord_into_points(*vp, allocations);
	
// 	//MLX
// 	mlx_t		*mlx;
// 	mlx_image_t	*img;
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(mlx, img, 0, 0);
	
// 	int i = 0;
// 	int obj_index = 0;
// 	while(i < (WIDTH * HEIGHT))
// 	{
// 		send_ray(&ray, O, vp_coord[i]);
// 		while (ray.bounces < BOUNCES - 1)
// 		{
// 			// printf("RAY: %d\t\t\t", i);
// 			obj_index = ft_intersection(obj, &ray); //calculates if there is an intersection and with which object
// 			calculate_color(&ray, obj[obj_index]); // updates the color for that ray
// 			ray.bounces++;
// 		}
// 		place_pixel(&ray, img);
// 		ray.bounces = 0;
// 		i++;
// 	}
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	ft_cleanup(allocations);
// 	free(vp);
// 	// system("leaks miniRT");
// }

//RENDER SPHERE WITH HARDSHADOWS WITHOUT BOUNCES 
//In the Objectlist, the first entry (obj[0]) is always background
int main(void)
{
	//POINTS AND VECTORS
	t_vector O;
	t_ray	ray;
	t_ray	shadowray;
	t_obj 	*obj;
	t_bg bg;
	obj = ft_calloc(sizeof(t_obj), 3);
	
	O.x = 0.0f;
	O.y = 0.0f;
	O.z = 0.0f;
	bg.color.r = 0.3;
	bg.color.g = 0.3;
	bg.color.b = 0.3;
	bg.exist = true;
	obj[0].color = &bg.color;
	obj[0].exist = &bg.exist;
	
	// t_sphere s1;
	// t_vector C1;
	// C1.x = 0.0f;
	// C1.y = 0.0f;
	// C1.z = 20.0f;
	// s1.centre = C1;
	// s1.radius = 4.0f;
	// s1.color.r = 0;
	// s1.color.g = 0.5;
	// s1.color.b = 0;
	// s1.exist = true;
	// obj[1].sphere = &s1;
	// obj[1].color = &s1.color;
	// obj[1].exist = &s1.exist;

	t_sphere s2;
	t_vector C2;
	C2.x = 0.0f;
	C2.y = 0.0f;
	C2.z = 10.0f;
	s2.centre = C2;
	s2.radius = 0.5f;
	s2.color.r = 0.0;
	s2.color.g = 0.0;
	s2.color.b = 0.5;
	s2.exist = true;
	obj[1].sphere = &s2;
	obj[1].color = &s2.color;
	obj[1].exist = &s2.exist;
	
	// t_plane p1;
	// t_vector N;
	// t_vector P;
	// P.x = 0.0;
	// P.y = 0.0;
	// P.z = 10.0;
	// N.x = 0.0;
	// N.y = 0.0;
	// N.z = 0.0;
	// p1.normal = N;
	// p1.position = P;
	// p1.color.r = 0.0;
	// p1.color.g = 0.0;
	// p1.color.b = 0.5;
	// p1.exist = true;
	// obj[2].plane = &p1;
	// obj[2].color = &p1.color;
	// obj[2].exist = &p1.exist;
	
	t_light L1;
	L1.light_p.x = 0.0;
	L1.light_p.y = 0.0;
	L1.light_p.z = 11.0;
	L1.color.r = 1.0;
	L1.color.g = 1.0;
	L1.color.b = 1.0;
	L1.brightness = 1.0;
	
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
	int obj_index = 0;
	(void) shadowray;
	while(i < (WIDTH * HEIGHT) / 1)
	{
		send_ray(&ray, O, vp_coord[i]);
		while (ray.bounces < BOUNCES - 1)
		{
			obj_index = ft_intersection(obj, &ray); //calculates if there is an intersection and with which object
			if (obj_index > 0)
			{
				send_shadowray(&shadowray, ft_calculate_point(ray, ray.t - T_MIN), L1.light_p);
				print_ray("SHADOWRAY", shadowray, shadowray.t);
				// print_vector("INTERSECT:", ft_calculate_point(ray, ray.t));
				// print_vector("LIGHT:", L1.light_p);
				int ob = ft_intersection(obj, &shadowray);
				if (ob > 0)
				{
					printf("OB: %d\n", ob);
					ray.rgb.r = 0.0;
					ray.rgb.g = 0.0;
					ray.rgb.b = 0.0;
					// print_ray("SHADOW_AFTER", shadowray, shadowray.t);
				}
				else
					calculate_color(&ray, obj[obj_index]); // updates the color for that ray
			// 	// printf("NEW: %f\n", shadowray.t);
			// 	// printf("Shadowray_t: %f\n", shadowray.t);
			}
			else
				calculate_color(&ray, obj[0]); // updates the color for that ray for background
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