#!/usr/bin/env bash

function run () {
	clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=ft -o ft
	clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=std -o std

	./ft > ft_test
	./std > std_test

	diff ft_test std_test
}

function check_leak() {
	is_installed=$(which valgrind &>/dev/null; echo -n $?)
	if [[ $is_installed -eq 0 ]]; then
		clang++ -std=c++98 -Wall -Wextra -Werror _main_.cpp -D ns=ft -o ft
		valgrind --leak-check=full -s ./ft
	else
		printf "\e[1;32mPlease run ./script.sh install to install valgrind\e[m"
	fi
}

function spinner() {
	local pid=$!
	local delay=0.75
	local spin_str='|/-\'
	local i=0
	while [[ "$(ps a | awk '{print $1}' | grep "$pid")" ]]; do
		printf "\e[1;32m[%c]\e[m" ${spin_str:${i}}
		sleep $delay 
		((i++))
		if [[ $i -eq 4 ]]; then
			i=0
		fi
		printf "\b\b\b\b\b\b"
	done
}

function install_brew() {
	curl -L https://github.com/Homebrew/brew/archive/1.9.0.tar.gz > brew1.9.0.tar.gz &>/dev/null
	tar -xzvf brew1.9.0.tar.gz &>/dev/null
	mv brew-1.9.0 $HOME/.brew
	rm -rf brew1.9.0.tar.gz
	if ls $HOME/.brew; then
		exit 0
	fi
}

function install_valgrind_for_ubunutu() {
	curl -L https://sourceware.org/pub/valgrind/valgrind-3.18.1.tar.bz2 --output valgrind.tar &>/dev/null
	mv valgrind.tar valgrind.tar.bz2
	tar xv valgrind.tar.bz2 &>/dev/null
	mv valgrind-* valgrind
	rm -rf valgrind.tar.bz2
	cd valgrind ; ./configure --prefix=$HOME/valgrind &>/dev/null; cd -
	cd valgrind; make &>/dev/null; cd -
	cd valgrind; make install &>/dev/null; cd -
	shell_type=$(echo -n $SHELL)
	if [[ "$shell_type" == "/bin/bash" ]]; then
		shell_type="$HOME/.bashrc"
	elif [[ "$shell_type" == "/bin/zsh" ]]; then
		shell_type="$HOME/.zshrc"
	fi
	echo "alias valgrind="$HOME/valgrind/bin/valgrind"" > $shell_type
	exit 0
}

function install_valgrind() {
	is_installed=$(which valgrind &>/dev/null; echo -n $?)
	os_name=$(uname)
	if [[ "$is_installed" == 0 ]]; then
		printf "\e[1;32mValgrind already installed\n\e[0m"
		exit $is_installed
	fi
	confirmation=0
	while true; do
		printf "\e[1;32mDo you want to install valgrind? \e[0m"
		read -r confirmation
		case $confirmation in
			[Yy]*) confirmation=1 && break;;
			[Nn]*) confirmation=0 && break;;
				*) printf "\e[1;31mPlease answer yes or no\n\e[m"
		esac
	done
	if [[ "$confirmation" == "0" ]]; then
		exit 0
	fi
	if [[ "$os_name" == 'Darwin' ]]; then
		install_brew & spinner
		$HOME/.brew/bin/brew install --HEAD ./valgrind.rb & spinner
		is_installed=$(which valgrind &>/dev/null ; echo -n $?)
		if [[ "$is_installed" == "0" ]]; then
			printf "\e[1;32mvalgrind has been instaled now you can run ./script.sh leak\n\e[0m"
			exit 0
		else
			printf "\e[1;31mOpps Something went wrong try again\n\e[m"
			exit 1
		fi
	fi
	# Now we only support Ubuntu
	os_name=$(cat /etc/os-release | grep -E "^NAME" | cut -d '=' -f 2 | tr -d '"')
	if [[ "$os_name" == 'Ubuntu' ]]; then
		install_valgrind_for_ubunutu & spinner
		sc=$?
		if [[ "$?" != "0" ]]; then
			printf "\e[1;31mOpps something went wrong\n\e[m"
			exit $confirmation
		fi
		printf "\e[1;32mvalgrind has been instaled now you can run ./script.sh leak\e[0m"
	fi
	exit 0
}


if [ $@ = "run" ]; then
	run
elif [ $@ = "ttime" ]; then
	ttime
elif [[ $@ = "leak" ]]; then
	check_leak
elif [ $@ = "install" ]; then
	install_valgrind
fi