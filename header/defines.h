# include <math.h>
# include <stdbool.h>
# include <stdio.h>

//Window Size
# ifndef WIDTH
#  define WIDTH 1024
# endif

# ifndef HEIGHT
#  define HEIGHT 768
# endif

//Camera
#define CAMERA_X 0.0f
#define CAMERA_Y 0.0f
#define CAMERA_Z 0.0f
#define FOV 70.0f
#define FOV_R ((float)FOV / (float)M_PI_2)
#define FOV_R ((float)FOV / (float)M_PI_2)
#define T_MIN 0.001f
#define T_MAX 1.0e30f
#define aspect_ratio ((float)WIDTH/ (float)HEIGHT)

//Viewport
# define V_W 2.0f
# define V_H ((float)V_W / (float)aspect_ratio)

//RAYS
# define BOUNCES 2
# define R 255.0f
# define G 255.0f
# define B 255.0f