CPP = g++ -std=c++17
CPPFLAGS = -Wall -Werror -Wextra
NAME = s21_stack
SOURCE = $(wildcard s21_*.cpp)
ifeq ($(OS), Darwin)
	LIBS = -lgtest
else
	LIBS = -lgtest -lpthread
endif

all: $(NAME).a test

$(NAME): $(SOURCE)
	@$(CPP) $(CPPFLAGS) $(NAME).cpp
	@./a.out && rm -rf a.out

$(NAME).a: $(SOURCE)
	@$(CPP) $(CPPFLAGS) $(SOURCE) -c
	@ar rcs $(NAME).a *.o
	@ranlib $(NAME).a


test:
	@$(CPP) $(NAME)_test.cpp $(NAME).a -o $(NAME)_test  $(LIBS)
	./$(NAME)_test

clean:
	@rm -rf $(NAME).a
	@rm -rf $(NAME).o
	@rm -rf $(NAME)_test
	@rm -rf $(NAME)_test.o
	@rm -rf a.out

check:
	clang-format -n *.cpp
	clang-format -n *.h