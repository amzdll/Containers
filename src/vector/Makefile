CPP = g++
CPPFLAGS = -std=c++17 -Wall -Werror -Wextra
NAME = s21_vector
SOURCE = $(wildcard s21_*.cpp)
ifeq ($(OS), Darwin)
	UBUNTU =
else
	UBUNTU = -lpthread
endif

all: clean $(NAME).a test

$(NAME): $(SOURCE)/home/freiqq/Projects/21/c++/containers/src/list/Makefile
	@clear
	@$(CPP) $(CPPFLAGS) $(NAME).cpp
	@./a.out && rm -rf a.out

$(NAME).a: $(SOURCE)
	@$(CPP) $(CPPFLAGS) $(NAME).cpp -c
	@ar rcs $(NAME).a *.o
	@ranlib $(NAME).a

test:
	@clear
	#$(CPPFLAGS)
	@$(CPP)  $(NAME)_test.cpp $(NAME).a -o $(NAME)_test -lgtest $(UBUNTU)
	@./$(NAME)_test

clean:
	@rm -rf $(NAME).a
	@rm -rf $(NAME).o
	@rm -rf $(NAME)_test.o
	@rm -rf a.out
