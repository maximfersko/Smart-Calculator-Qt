SRC         =     $(foreach dir, $(SOURCEDIR), $(wildcard $(dir)/*.cc))
CC          =     g++ -std=c++17
LIBCHECK    =     -lgtest
TESTF       =     test.cc $(SRC)
OS          =     $(shell uname -s)
SOURCEDIR   =     smartCalcMvc/model/

.PHONY:
	clean rebuild test leaks all default

clean:
	rm -rf *.txt test valgrind leaks *.dSYM *.out *.cfg
	rm -rf *.gcno *.gcda *.gcov *.info report .clang-format main
	rm -rf *.o *.a

install: uninstall
	mkdir app
	cp -r smartCalcMvc/* app
	cd app; qmake smartCalcMvc.pro
	make -C app
	open app/smartCalcMvc.app/Contents/MacOS/smartCalcMvc

uninstall:
	rm -rf app

test: clean
	$(CC) $(TESTF) $(LIBCHECK) --coverage -o test
	./test

gcov_report: test
	lcov -t "test" --no-external -o test.info -c -d ./
	genhtml -o report test.info
	open report/index.html

leaks: clean
	$(CC) $(LIBCHECK) test.cc $(SRC) -o leaks 
	leaks  -atExit -- ./leaks

