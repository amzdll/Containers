CPP = g++
CPPFLAGS = -std=c++17 -Wall -Werror -Wextra
NAME = s21_list
SOURCE = $(wildcard s21_*.cpp)

all: clean $(NAME)

$(NAME): $(SOURCE)
	@clear
	@$(CPP) $(CPPFLAGS) $(NAME).cpp
	@./a.out && rm -rf a.out

$(NAME).a: $(SOURCE)
	@$(CPP) $(CPPFLAGS) $(SOURCE) -c
	@ar rcs $(NAME).a *.o
	@ranlib $(NAME).a

$(NAME)_test:
	@clear
	@$(CPP) $(CPPFLAGS) $(NAME)_test.cpp $(NAME).a -o $(NAME)_test -lgtest
	@./test

clean:
	@rm -rf $(NAME).a
	@rm -rf $(NAME).o
	@rm -rf $(NAME)_test
	@rm -rf a.out
