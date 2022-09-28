CC=g++
###
debug:
	${CC} -I./headers Quadr.c sources/solve_equations.c sources/test.c   -DDEBUG -O0 -Og -Wall -Wextra -Werror -o debug
release:
	${CC} -I./headers Quadr.c sources/solve_equations.c sources/test.c   -O3 -Wall -Wextra -Werror -o release
