CC = gcc
TESTFLAGS = -lcheck
GCCFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: s21_math.a gcov_report test

s21_math.a: clean
	$(CC) $(GCCFLAGS) -std=c11 -c s21_functions/*.c 
	ar rc s21_math.a *.o
	mkdir binary_files
	mv *.o binary_files

gcov_report: s21_math.a
	gcc $(GCCFLAGS) $(GCOVFLAGS) s21_math_test.c $(TESTFLAGS) s21_functions/*.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno s21_math_test.gcda s21_math_test.gcno

test: s21_math.a
	$(CC) $(GCCFLAGS) $(TESTFLAGS) s21_math_test.c s21_math.a -o s21_math_test
	./s21_math_test

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info binary_files test s21_math_test report