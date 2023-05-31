/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:03 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/31 14:27:16 by aestraic         ###   ########.fr       */
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
// 	obj = ft_calloc(sizeof(t_obj), 5);
// 	t_plane	p1;
// 	t_plane	p2;
// 	t_plane	p3;
// 	t_vector P1;
// 	t_vector N1;
// 	t_vector P2;
// 	t_vector N2;
// 	t_vector P3;
// 	t_vector N3;
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
// 	N1.x = 0;
// 	N1.y = 1;
// 	N1.z = 1;
// 	p1.normal = N1;
// 	p1.position_p = P1;
// 	p1.color.r = 0;
// 	p1.color.g = 0;
// 	p1.color.b = 0.5;
// 	p1.exist = true;
	
// 	P2.x = 0;
// 	P2.y = 0.0;
// 	P2.z = 10;
// 	N2.x = 1;
// 	N2.y = 1;
// 	N2.z = 1;
// 	p2.normal = N2;
// 	p2.position_p = P2;
// 	p2.color.r = 0;
// 	p2.color.g = 0.5;
// 	p2.color.b = 0;
// 	p2.exist = true;

// 	P3.x = 0;
// 	P3.y = 0.0;
// 	P3.z = 10;
// 	N3.x = 1;
// 	N3.y = 0;
// 	N3.z = 1;
// 	p3.normal = N3;
// 	p3.position_p = P3;
// 	p3.color.r = 0.5;
// 	p3.color.g = 0;
// 	p3.color.b = 0;
// 	p3.exist = true;
	
// 	obj[1].color = &p1.color;
// 	obj[1].exist = &p1.exist;
// 	obj[1].plane = &p1;
// 	obj[2].color = &p2.color;
// 	obj[2].exist = &p2.exist;
// 	obj[2].plane = &p2;
// 	obj[3].color = &p3.color;
// 	obj[3].exist = &p3.exist;
// 	obj[3].plane = &p3;
	
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
// 	C1.x = 0.5f;
// 	C1.y = 0.0f;
// 	C1.z = 10.2f;
// 	C2.x = -0.5f;
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

static void	ft_init(t_struct *mrt, char **argv)
{
	int		fd;
	int		number;
	char	*str;

	number = 1;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		number++;
		str = get_next_line(fd);
	}
	mrt->obj = ft_calloc(sizeof(t_obj), number);
	mrt->zero.x = 0.0f;
	mrt->zero.y = 0.0f;
	mrt->zero.z = 0.0f;
	mrt->bg.color.r = 0.2;
	mrt->bg.color.g = 0.2;
	mrt->bg.color.b = 0.2;
	mrt->bg.exist = true;
	mrt->obj[0].color = &mrt->bg.color;
	mrt->obj[0].exist = &mrt->bg.exist;
	ft_input(mrt, argv);
	mrt->allocations = ft_calloc(sizeof(t_alloc), 1);
	mrt->vp = viewport_coordinates(mrt->allocations);
	mrt->vp_coord = viewport_coord_into_points(*mrt->vp, mrt->allocations);
	mrt->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	mrt->img = mlx_new_image(mrt->mlx, WIDTH, HEIGHT);
}

int	main(int argc, char **argv)
{
	t_struct	mrt;
	t_ray		ray;
	t_ray		sray;
	t_ray		lray;
	int			i;
	int 		obj_index;
	int			in_shadow;

	if (argc != 2)
		return (1);
	ft_init(&mrt, argv);
	init_ray(&ray, 0);
	init_ray(&sray, 1);
	mlx_image_to_window(mrt.mlx, mrt.img, 0, 0);
	i = 0;
	obj_index = 0;
	in_shadow = 0;
	(void) sray;
	while (i < (WIDTH * HEIGHT))
	{
		send_ray(&ray, mrt.zero, mrt.vp_coord[i]);
		while (ray.bounces < BOUNCES)
		{
			obj_index = ft_intersection(&ray, &mrt);
			if (obj_index > 0)
			{
				in_shadow = hardshadows(&sray, &ray, obj_index, &mrt);
				ambient_light(&ray, &mrt);
				if (in_shadow == 0)
				{
					send_ray(&lray, mrt.light.light_p, ft_calculate_point(ray, ray.t));
					diffuse_lighting(&ray, &lray, obj_index, &mrt);
				}
			}
			else
				paint_obj_color(&ray, mrt.obj[0]);
			
			// update_color(&ray);
			ray.bounces++;
		}
		place_pixel(&ray, mrt.img);
		ft_putlight(mrt.light, &mrt);
		ray.bounces = 0;
		i++;
	}
	mlx_loop(mrt.mlx);
	mlx_terminate(mrt.mlx);
	ft_cleanup(mrt.allocations);
	free(mrt.vp);
	// system("leaks miniRT");
	return (0);
}
