## INSTALL MLX (update 14.05.23)
## After the MLX42 directory is downloaded,
## - cd MLX42
## - mkdir build
## - cd build
## cmake && make, so that the libmlx42.a is produced inside the build directory.

NAME = miniRT
SRC = 	main.c\
		vector.c\
		vector2.c\
		mem.c\
		obstacle.c\
		obstacle_utils.c\
		midnight.c\
		draw.c\
		camera.c\
		input.c\
		input2.c\
		shadows.c\
		light.c\
		test.c\
		hooks.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c

OBJ  = $(SRC:.c=.o)

C_FLAGS = -Wall -Wextra -Werror -Ofast
HEADER_PATH = header
SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = lib
LIB = $(LIB_PATH)/libft.a
LIB_MLX = ./$(MAKE_MLX_LIB) -lglfw  -L $(INST_GLFW)\
	-framework Cocoa -framework OpenGL -framework IOKit

MLX_DIR = MLX42/
MAKE_MLX_LIB = $(MLX_DIR)build/libmlx42.a
INST_GLFW = /Users/$(USER)/.brew/opt/glfw/lib/
INST_BREW = /Users/$(USER)/.brewconfig.zsh
INST_CMAKE = /Users/$(USER)/.brew/bin/cmake

all: $(NAME)

%.o : %.c
	@gcc $(C_FLAGS) -I$(HEADER_PATH) -c $^
	
$(NAME): $(INST_BREW) $(INST_GLFW) $(INST_CMAKE) $(MAKE_MLX_LIB) $(LIB) $(OBJ)
	@gcc $(C_FLAGS) -Ofast -o $(NAME) $(SRC) $(LIB_MLX) -I$(HEADER_PATH) -Llib -lft

$(LIB):
	@mkdir -p $(LIB_PATH)
	@make all -C	$(SRC_PATH)/libft

#cmake -B<path-to-build> -S<path-to-source(CMakeLists.txt)>
$(MAKE_MLX_LIB): $(MLX_DIR)
	@mkdir -p $(MLX_DIR)build		
	@cmake -B $(MLX_DIR)build $(MLX_DIR)
	@make -C $(MLX_DIR)build
	
$(MLX_DIR):
	@echo Cloning MLX42
	git clone https://github.com/codam-coding-college/MLX42.git
	
$(INST_GLFW):
	@echo Installing GLFW
		brew install glfw
		
$(INST_BREW):
	@echo Installing Brew
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	@source ~/.zshrc

$(INST_CMAKE):
	@echo Installing cmake
		brew install cmake

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_B)
	@make clean -C $(SRC_PATH)/libft
	@echo Objectfiles removed

fclean: clean
	@make fclean -C $(SRC_PATH)/libft
	@rm -f $(NAME) $(BONUS)
	@echo Libraries and exeutables removed

aclean: fclean
	@rm -rf test_maps
	@rm -rf MLX42
	@echo Maps and MLX removed
	
re: fclean all
	@echo REDONE

.PHONY: clean fclean aclean re all bonus val
