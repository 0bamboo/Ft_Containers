#!/bin/bash

function run () {
	clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=ft -o ft
	clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=std -o std

	./ft > ft_test
	./std > std_test

	diff ft_test std_test > diff_file
	# rm ./ft ./std ft_test std_test
}

function ttime () {
	clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=ft -o ft
	clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=std -o std

	time ./ft ; time ./std
	rm ./ft ./std

	diff ft_test std_test
}


if [ $@ = "run" ]; then
	run
elif [ $@ = "run11" ]; then
	run11
elif [ $@ = "ttime" ]; then
	ttime
fi