all:
	- mkdir build
	- cd build && cmake .. && make

release:
	- mkdir build
	- cd build && cmake -DCMAKE_BUILD_TYPE=Release && make

ci:
	- mkdir build
	- cd build && cmake -DCMAKE_BUILD_TYPE=Release -DCOVERAGE_FLAG=ON


.PHONY:
clean:
	- rm -rf build/
