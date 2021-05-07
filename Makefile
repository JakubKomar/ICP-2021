
.PHONY: all build doxygen run pack clean

TARGET=blockeditor
QT_LIB_PATH=/usr/local/share/Qt-5.5.1/5.5/gcc_64/lib


all: build

build:
	if [ -d "build" ]; then rm -r build; fi && \
	mkdir build && \
	cd build && \
	qmake ../src/ICP-projekt-2021.pro  && \
	make && \
	cp ICP-projekt-2021 ../

run:
	test -f ICP-projekt-2021 && ./ICP-projekt-2021

doxygen:
	doxygen src/Doxyfile

clean:
	rm -rf ICP-projekt-2021 build/ 