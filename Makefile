NAME :=		libftprintf.a
CC :=		gcc
CFLAGS :=	-Wall -Wextra -Werror
AR :=		ar rcs
OBJDIR :=	obj


SRCS := src/ft_printf.c

OBJS : $(SRCS:%.c=$(OBJDIR)/%.o)
	

HEADERS := include/ft_printf.h

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
				$(AR) $@ $^
				echo "Compiled $@"

$(OBJDIR)/%.o: %.c $(HEADERS)                                       
				mkdir -p $(@D)
				echo "Compiling $@"
				$(CC) -c $(CFLAGS) $< -o $@

clean:
				rm -rf $(OBJDIR)

fclean:	
				make clean
				rm -f $(NAME)

re: fclean all

.SILENT:
.PHONY: all clean fclean re