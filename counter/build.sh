#bash
g++ -g -fsanitize=address,undefined -std=c++23 *.cpp -o counter_test
