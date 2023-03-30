SRC         =     smartCalcMvc/model/parser.cc smartCalcMvc/model/calculate.cc smartCalcMvc/model/validator.cc smartCalcMvc/model/graphBuilder.cc smartCalcMvc/model/creditModel.cc smartCalcMvc/model/deposit.cc
CC          =     g++ -std=c++17
LIBCHECK    =     -lgtest
TESTF       =     test.cc smartCalcMvc/model/parser.cc smartCalcMvc/model/calculate.cc smartCalcMvc/controller/controller.cc smartCalcMvc/model/validator.cc smartCalcMvc/model/graphBuilder.cc smartCalcMvc/model/creditModel.cc smartCalcMvc/model/deposit.cc
PUSHCOMMENT =     "finish"
OS          =     $(shell uname -s)

.PHONY:
	clean rebuild test leaks all default

clean:
	rm -rf *.txt test model_matrix_oop valgrind leaks *.dSYM *.out *.cfg
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


lint: clean
	cp ../materials/linters/.clang-format . 
	clang-format -i --verbose ./*.cc $(SRC)
	rm -f .clang-format

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

dvi:
	open documentation/documentation.html

