CFLAGS := $(shell curl-config --cflags)
LDFLAGS := $(shell curl-config --libs)

APPS = https_get

all: ${APPS}

https_get: https_get.c
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS) 

clean:
	rm -rf ${APPS}

