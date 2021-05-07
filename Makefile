
.PHONY: all build doxygen run pack clean

all: build

build:
	if [ -d "build" ]; then rm -r build; fi && \
	mkdir build && \
	cd build && \
	qmake ../src/ICP-projekt-2021.pro  && \
	make && \
	cp ICP-projekt-2021 ../

pack: clean
	zip -r xkomar33-xkolev00.zip src/ exemples/ makefile README.txt

run:
	test -f ICP-projekt-2021 && ./ICP-projekt-2021

doxygen:
	doxygen src/doxygen/Doxyfile

clean:
	rm -rf ICP-projekt-2021 build/ 