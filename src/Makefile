#all, install, uninstall, clean, dvi, dist, tests, gcov_report
CC = g++
CC_FLAGS = -Wall -Wextra -Werror -std=c++17 #-pedantic-errors
TEST_FLAGS = -lgtest # -pthread
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
SANITIZER_FLAGS = -fsanitize=address
PROJECT_NAME = s21_SmartCalc_v_2_0
SRCS=$(wildcard s21*.cc,*/s21*.cc)
OBJ_FILES=$(patsubst %.cc,%.o,$(SRCS))
REPORT_DIR = report

run: clean
	clear
	$(CC) $(CC_FLAGS) $(SANITIZER_FLAGS) model/s21_*.cc  run.cc -o run -g
#	$(CC) $(CC_FLAGS) $(SANITIZER_FLAGS) model/s21_model.cc model/s21_validation_model.cc model/s21_check_model.cc model/s21_count_model.cc run.cc -o run -g
#	$(OBJ_FILES)
	./run


all: 

install: clean
	qmake -o build/Makefile SmartCalc/SmartCalc.pro CONFIG+=qtquickcompiler
	make -C build/ first
	rm -rf build/*.o build/*.h build/*.cpp build/Makefile

uninstall:
	rm -rf build

clean:
	rm -rf *.o *.gcno *.gcda *.info *.a $(REPORT_DIR) c_tests run *.dSYM SmartCalcPro.tar.gz

dvi: clean
	makeinfo -o report --html --no-warn --no-validate --force doc.texi
	open report/index.html

dist: clean
	tar -czf SmartCalcPro.tar.gz s21_* Makefile SmartCalc 

tests: clean
	clear
	$(CC) $(CC_FLAGS) model/*.cc calc_tests/*_tests.cc -o c_tests $(TEST_FLAGS) $(SANITIZER_FLAGS)
#	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS) $(SANITIZER_FLAGS) model/*.cc calc_tests/calculations_tests.cc calc_tests/main_tests.cc -o c_tests $(TEST_FLAGS)
	./c_tests

gcov_report: clean
	clear
	$(CC) $(CC_FLAGS) $(COVERAGE_FLAGS) $(SANITIZER_FLAGS) model/*.cc calc_tests/*_tests.cc -o c_tests $(TEST_FLAGS)
	./c_tests
	lcov -t "$@" -o $@.info -c -d . --no-external
	lcov -r $@.info "*include*" -o $@.info
	genhtml -o ./$(REPORT_DIR) $@.info
	open ./report/index.html

%.o:%.cc
	$(CC) -c $(FLAGS) $< -o $@ -I .

valgrind: tests
	valgrind --leak-check=full \
        	 --show-leak-kinds=all \
         	 --track-origins=yes \
         	 --verbose \
			 ./c_tests

# valgrind:
# #	brew install valgrind
# 	valgrind --tool=memcheck --leak-check=yes  ./main.out

.PHONY:
	all, clean, tests, gcov_report, install, uninstall, dvi, dist

clang:
	clang-format -i --style=Google **/s21*.cc **/s21*.h 
	clang-format -n --style=Google **/s21*.cc **/s21*.h

cppcheck:
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem **/*s21*.cc **/*s21*.h *s21*.cc

push:
	git push origin trial_develop
