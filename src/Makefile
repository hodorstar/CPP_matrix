CXX = g++
CFLAGS = -g -Wall -Werror -Wextra -std=c++17
TEST_FLAG = -lgtest 

PROJECT = matrix/*.cc
TESTS = tests/*.cc

all: s21_matrix_oop.a

s21_matrix_oop.a: clean
	$(CXX) -c $(CFLAGS) $(PROJECT) 
	ar rc s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	$(CXX) $(CFLAGS) $(TEST_FLAG) $(TESTS)  s21_matrix_oop.a -o test
	./test
	
gcov_report: clean add_coverage test
	lcov --no-external  -t "s21_matrix_oop" -o s21_matrix_oop.info -c -d . 
	genhtml -o report s21_matrix_oop.info 
	open report/index.html

add_coverage: 
	$(eval CFLAGS += --coverage)

style_check:
	cp tests/.clang-format ./
	clang-format -style=Google -n $(PROJECT) 
	clang-format -style=Google -n $(TESTS) 

clean:
	rm -rf *.o matrix/*.o s21_matrix_oop.a *.gcov *.gcno *.gcda *.info test report