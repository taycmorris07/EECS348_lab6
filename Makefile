main: lab_6.cpp
	g++ -o main lab_6.cpp
clean:
	@rm -f main
build-run:
	@g++ -o main lab_6.cpp
	@./main