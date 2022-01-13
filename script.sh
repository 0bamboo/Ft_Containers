#!/bin/bash

function run () {
	clang++ -std=c++98 -Wall -Wextra -Werror test_test.cpp -D ns=ft -o ft
	clang++ -std=c++98 -Wall -Wextra -Werror test_test.cpp -D ns=std -o std

	./ft > ft_test
	./std > std_test
	rm ./ft ./std

	diff ft_test std_test
}

function check_leak() {
	clang++ -std=c++98 -Wall -Wextra -Werror test_test.cpp -D ns=ft -o ft
	valgrind --leak-check=full -s ./ft
}

if [ $@ = "run" ]; then
	run
elif [ $@ = "leak" ]; then
	check_leak
fi