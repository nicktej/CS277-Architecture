all:
	@echo make test OR
	@echo make perf-stdlib OR
	@echo make perf-local

test: build/unit/test
	@build/unit/test

perf-stdlib: build/perf/perf-stdlib
	@build/perf/perf-stdlib

perf-local: build/perf/perf-local
	@build/perf/perf-local

build/src/memcpy.o: build/src src/memcpy.c
	cc -c -o build/src/memcpy.o src/memcpy.c

build/unit/test.o: build/unit unit/test.c
	cc -c -o build/unit/test.o unit/test.c

build/perf/perf-stdlib.o: build/perf perf/perf.c
	cc -c -o build/perf/perf-stdlib.o perf/perf.c

build/perf/perf-local.o: build/perf perf/perf.c
	cc -DLOCAL -c -o build/perf/perf-local.o perf/perf.c

build/unit/test: build/src/memcpy.o build/unit/test.o
	cc -o build/unit/test build/unit/test.o build/src/memcpy.o

build/perf/perf-stdlib: build/perf/perf-stdlib.o
	cc -o build/perf/perf-stdlib build/perf/perf-stdlib.o

build/perf/perf-local: build/src/memcpy.o build/perf/perf-local.o
	cc -o build/perf/perf-local build/src/memcpy.o build/perf/perf-local.o

build/src:
	mkdir -p build/src

build/unit:
	mkdir -p build/unit

build/perf:
	mkdir -p build/perf
