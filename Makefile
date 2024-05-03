NAME	= push_swap

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FILES 			= 	sort	\
					main
SRCS 			=  src/*.c
OBJS	= $(SRCS:.c=.o)
RM  	= rm -rf

# CURSOR MOVEMENTS
MOV_U			= 	\033[1A
MOV_D			= 	\033[1B
MOV_F			= 	\033[1C
MOV_B			= 	\033[1D

ERASE_ALL		= 	\033[0J

# COLORS 
YELLOW 			= 	\033[0;33m
GREEN 			= 	\033[0;32m
BLUE 			= 	\033[0;34m
RED				= 	\033[0;31m
PURPLE 			= 	\033[0;35m
CYAN 			= 	\033[0;36m
BLACK 			= 	\033[0;30
WHITE 			= 	\033[0;37m

all : $(LIBFT) $(NAME)

$(NAME):
	@echo "$(RED)          )     *     (    (    (     (        )            " ;
	@echo "   (   ( /(   (      )\ ) )\ ) )\ )  )\ )  ( /(  (                " ;
	@echo "  )\  )\())  )\))(  (()/((()/((()/( (()/(  )\()) )\ )             " ; 
	@echo " (((_)((_)\  ((_)()\  /(_))/(_))/(_)) /(_))((_)\ (()/(             " ;
	@echo " )\___  ((_) (_()((_)(_)) (_)) (_))  (_))   _((_) /(_))_           " ;
	@echo "((/ __|/ _ \ |  \/  || _ \|_ _|| |   |_ _| | \| |(_)) __|          " ;
	@echo " | (__| (_) || |\/| ||  _/ | | | |__  | |  |    |  | (_ | _  _  _  " ;
	@echo "  \___|\___/ |_|  |_||_|  |___||____||___| |_|\_|   \___|(_)(_)(_) " ;
	@${CC} ${CFLAGS} ${SRCS} $(LIBFT) -o $(NAME) -g3
	@sleep 0.1
	@echo "$(CYAN)$(MOV_U)$(MOV_U)$(MOV_U)$(MOV_U)$(MOV_U)$(MOV_U)$(MOV_U)$(MOV_U)$(MOV_U)"
	@echo "        )     *     (    (    (         (             (        )   "
	@echo "   (   ( /(   (       )\ ) )\ ) )\ )      )\ )      (   )\ )  ( /(   "
	@echo "   )\  )\())  )\))(  (()/((()/((()/(  (  (()/(    ( )\ (()/(  )\())  "
	@echo " (((_)((_)\  ((_)()\  /(_))/(_))/(_)) )\  /(_))   )((_) /(_))((_)\   "
	@echo " )\___  ((_) (_()((_)(_)) (_)) (_))  ((_)(_))_   ((_)_ (_))   ((_)  "
	@echo "((/ __|/ _ \ |  \/  || _ \|_ _|| |   | __||   \   | _ )| _ \ / _ \  "
	@echo " | (__| (_) || |\/| ||  _/ | | | |__ | _| | |) |  | _ \|   /| (_) |  "
	@echo "  \___|\___/ |_|  |_||_|  |___||____||___||___/   |___/|_|_\ \___/  "
	@echo ""

$(LIBFT):
	@make --silent -C $(LIBFT_DIR)

clean :
	@$(RM) $(OBJS)
	@make clean --silent -C $(LIBFT_DIR)
	@echo "$(CYAN)       (                  )        (       )   "
	@echo "   (   )\ )      (     ( /(     (  )\ ) ( /(   "
	@echo "   )\ (()/( (    )\    )\())  ( )\(()/( )\())  "
	@echo " (((_) /(_)))\((((_)( ((_)\   )((_)/(_)|(_)\   "
	@echo " )\___(_)) ((_))\ _ )\ _((_) ((_)_(_)_)   ((_)  "
	@echo "((/ __| |  | __(_/_\(_) \| |  | _ )| _ \ / _ \  "
	@echo " | (__| |__| _| / _ \ |    |  | _ \|   /| (_) | "
	@echo "  \___|____|___/_/ \_\|_|\_|  |___/|_|_\ \___/  "
	@echo ""

fclean : clean
	@$(RM) $(NAME)
	@make fclean --no-print-directory -C $(LIBFT_DIR)

re : fclean all

.PHONY	: all clean fclean re