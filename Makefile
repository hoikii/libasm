NAME		= libasm.a
SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s \
			  ft_read.s ft_write.s ft_strdup.s
ASM			= nasm
ASMFLAG		= -fmacho64
CC			= gcc
CLFAGS		= -Wall -Wextra
TESTNAME	= test
TESTSRCS	= main.c \
			  tester/test_ft_strlen.c \
			  tester/test_ft_strcmp.c \
			  tester/test_ft_strcpy.c \
			  tester/test_ft_read.c \
			  tester/test_ft_write.c \
			  tester/test_ft_strdup.c
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
	$(CC) $(CLFAGS) -L. -lasm -o $(TESTNAME) $(TESTSRCS)
	@./$(TESTNAME)
