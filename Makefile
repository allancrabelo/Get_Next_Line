NAME = get_next_line
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)

INTRO_DONE = .intro_done

# Cores ANSI
YELLOW = \033[1;33m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

all: intro $(NAME)

intro: $(INTRO_DONE)

$(INTRO_DONE):
	@echo "$(CYAN)"
	@echo " ██████╗ ███████╗████████╗     ███╗   ██╗███████╗██╗  ██╗████████╗     ██╗     ██╗███╗   ██╗███████╗"
	@echo "██╔════╝ ██╔════╝╚══██╔══╝     ████╗  ██║██╔════╝╚██╗██╔╝╚══██╔══╝     ██║     ██║████╗  ██║██╔════╝"
	@echo "██║  ███╗█████╗     ██║        ██╔██╗ ██║█████╗   ╚███╔╝    ██║        ██║     ██║██╔██╗ ██║█████╗  "
	@echo "██║   ██║██╔══╝     ██║        ██║╚██╗██║██╔══╝   ██╔██╗    ██║        ██║     ██║██║╚██╗██║██╔══╝  "
	@echo "╚██████╔╝███████╗   ██║███████╗██║ ╚████║███████╗██╔╝ ██╗   ██║███████╗███████╗██║██║ ╚████║███████╗"
	@echo " ╚═════╝ ╚══════╝   ╚═╝╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝   ╚═╝╚══════╝╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝"
	@echo "                                                                                by Allan Rabelo"
	@echo  "$(RESET)"
	@touch $(INTRO_DONE)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking object files to create executable $(NAME)...$(RESET)"
	@$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $< file...$(RESET)"
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(RESET)"

clean:
	@echo "$(YELLOW)[✗] Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean: clean
	@echo "$(YELLOW)[*] Removing executable and intro flag...$(RESET)"
	@rm -f $(NAME) $(INTRO_DONE)
	@echo "$(GREEN)Full clean complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re intro

