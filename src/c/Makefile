# Copyright 2021 Alex Wu. All rights reserved
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.
CC=cc
LD=cc
CFLAGS=-ggdb -I$(GOROOT)/include \
	-Wno-int-conversion \
	-Wno-parentheses \
	-Wno-gnu-designator \
	-Wno-sizeof-pointer-memaccess \
	-Wno-shift-negative-value \
	-Wno-implicit-function-declaration \
	-Wno-switch \
	-Wno-comment \
	-Wno-strncat-size \
	-Wno-null-dereference \
	-Wno-initializer-overrides \
	-Wno-return-type \
	-Wno-implicit-int

BIN=$(GOROOT)/bin
O=o
YFLAGS=-d

TARG=\
	gc

HFILES=\
	go.h\
	y.tab.h\

YFILES=\
	go.y\

OFILES=\
	y.tab.$O\
	lex.$O\
	const.$O\
	dcl.$O\
	export.$O\
	gen.$O\
	gsubr.$O\
	mpatof.$O\
	obj.$O\
	subr.$O\
	walk.$O\

$(TARG): $(OFILES)
	cc -o $(TARG) -L$(GOROOT)/lib $(OFILES) -lbio -l9

$(OFILES): $(HFILES)

y.tab.c: $(YFILES)
	yacc $(YFLAGS) $(YFILES)

test: test.$O
	cc -o test test.$O
clean:
	rm -f $(TARG) $(OFILES) test test.$O y.tab.h y.tab.c

install: $(TARG)
	cp $(TARG) $(BIN)/$(TARG)

