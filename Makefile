ifeq '$(findstring ;,$(PATH))' ';'
  CONAN_FLAGS = -s compiler='Visual Studio' -s compiler.version=16 -s cppstd=17 --build missing
else
  CONAN_FLAGS = -s cppstd=17 --build missing
endif

all: prepare

install:
	sudo apt-get install gcovr lcov pkg-config curl zip unzip tar ccache

install_doc:
	pip install jinja2 Pygments
	sudo apt-get install doxygen


prepare:
	rm -rf build
	mkdir build


