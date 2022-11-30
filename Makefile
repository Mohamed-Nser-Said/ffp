dependency:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png

prepare:
	rm -rf build
	mkdir build

b:
	cmake . -B ./build
	cmake --build ./build

run_app:
	./build/app/debug/Executable.exe

test:
	./build/debug/ffp.exe
