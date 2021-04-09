NAME		= libasm.a
SRCS		= ft_strlen.s
ASM			= nasm
ASMFLAG		= -fmacho64
CC			= gcc
CLFAGS		= -Wall -Wextra
TESTNAME	= test
RM			= rm -rf
OBJS		= $(SRCS:.s=.o)

.PHONY: all bonus clean fclean re test

all: $(NAME)

%.o: %.s
	$(ASM) $(ASMFLAG) -o $@ $<

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "make done!"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

test: all
	$(CC) $(CLFAGS) -L. -lasm -o $(TESTNAME) main.c
	./$(TESTNAME)
