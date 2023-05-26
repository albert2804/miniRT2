#ifndef STRUCTS_H
# define STRUCTS_H

//=============================================================================
//RAYS AND VECTORS
//=============================================================================

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}			t_vector;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}			t_color;

/**
 * @param r,g,b are float values from 0 to 1 normalized values
 * @param bounces are at max 10 (#define BOUNCES 10)
*/
typedef struct s_ray
{
	t_vector	viewport;
	t_vector	origin;
	t_vector	direction;
	double		t;
	int			bounces;
	t_color		rgb;
}			t_ray;

//=============================================================================
//OBSTACLES
//=============================================================================

/**
 * @param n_max represents the total number of planes, spheres, cylinders
*/
typedef struct s_plane
{
	t_vector	position;
	t_vector	normal;
	t_color		color;
	bool		exist;
}			t_plane;

typedef struct s_sphere
{
	t_vector	centre;
	double		radius;
	t_color		color;
	bool		exist;
}			t_sphere;

typedef struct s_cylinder
{
	t_vector	centre;
	t_vector	axis_normal;
	double		diameter;
	double		height;
	t_color		color;
	bool		exist;
}
		t_cylinder;

// BACKGROUND_SRTUCT		
typedef struct s_bg
{
	t_color		color;
	bool		exist;
}			t_bg;

/**
 * @param plane, sphere, cylinder: The obstacles will be malloced later
*/
typedef struct s_obj
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_bg		*background;
	t_color		*color;
	bool		*exist;
}			t_obj;

//=============================================================================
//CAMERA AND VIEWPORT
//=============================================================================

typedef struct s_camera
{
	t_vector	view_p;
	t_vector	orientation;
}			t_camera;

typedef struct s_viewport
{
	double	*x;
	double	*y;
	double	distance;
}			t_viewport;

typedef struct s_amb
{
	double		amb_ratio;
	t_color		*color;
}			t_amb;

typedef struct s_light
{
	t_vector	*light_p;
	double		brightness;
	t_color		*color;
}			t_light;

//=============================================================================
//MEM
//=============================================================================

typedef struct s_alloc
{
	double		*vp_x;
	double		*vp_y;
	t_vector	*points;
}				t_alloc;

#endif