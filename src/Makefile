.PHONY: all clean rebuild

all:
	@cd list/ && make
	@cd stack/ && make
	@cd queue/ && make
	@cd vector/ && make
	@cd map/ && make
	@cd set/ && make

test:
	@cd list/ && make test
	@cd queue/ && make test
	@cd stack/ && make test
	@cd vector/ && make test
	@cd map/ && make test
	@cd set/ && make test

gcov_report:
	@cd list/ && make gcov_report
	@cd queue/ && make gcov_report
	@cd stack/ && make gcov_report
	@cd vector/ && make gcov_report
	@cd map/ && make gcov_report
	@cd set/ && make gcov_report

clean:
	@cd list/ && make clean
	@cd queue/ && make clean
	@cd stack/ && make clean
	@cd vector/ && make clean
	@cd map/ && make clean
	@cd set/ && make clean

check:
	@cd list/ && make check
	@cd queue/ && make check
	@cd stack/ && make check
	@cd vector/ && make check
	@cd map/ && make check
	@cd set/ && make check

style:
	cd list/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc
	cd queue/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc
	cd stack/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc
	cd vector/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc
	cd map/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc
	cd set/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc
	cd tree/ && clang-format -style=google -n *.cc *.h && cppcheck *.cc

rebuild: clean all
