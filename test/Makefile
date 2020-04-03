all: code
	./a.out < input.txt
	pbcopy < code.cpp

out: code
	./a.out < input.txt > output.txt
	pbcopy < output.txt

run: code
	./a.out

code:
	g++ -std=c++11 code.cpp

.PHONY: clean
clean:
	rm -rf a.out
