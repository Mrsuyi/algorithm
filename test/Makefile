all:
	g++ -std=c++11 code.cpp
	./a.out < input.txt
	pbcopy < code.cpp

out:
	g++ -std=c++11 code.cpp
	./a.out < input.txt > output.txt
	pbcopy < output.txt

.PHONY: clean
clean:
	rm -rf a.out
