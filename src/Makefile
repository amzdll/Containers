CPP = g++ -std=c++17
CPPFLAGS = -Wall -Werror -Wextra
NAME = list
SOURCE = $(wildcard s21_*.cpp)

all:


git:
	git add map/ set/ queue/ vector/ stack/ list/ s21_containers.h Makefile
	git commit -m "auto-commit"
	git push origin develop

test:
	@cd list && make && make clean

clean:
	cd list && make clean