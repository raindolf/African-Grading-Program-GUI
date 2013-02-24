##
##*****************************************************************************
## $Id: makefile 38 2013-02-20 00:32:35Z mkwayisi $
## ----------------------------------------------------------------------------
## Authored by Michael Kwayisi. Copyright (c) 2009-2013. All rights reserved.
## Please send your comments to mkwayisi@gmail.com | Web: michaelkwayisi.com
## ----------------------------------------------------------------------------
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are
## stringently met:
##   1. Redistributions of source code must retain the above copyright notice,
##      this list of conditions, and the following disclaimer.
##   2. Redistributions in binary form must reproduce the above copyright
##      notice, this list of conditions, and the following disclaimer in the
##      documentation and/or other materials provided with the package.
##   3. The end-user documentation included with the redistribution, if any,
##      must include the following acknowledgment:
##         "This product includes software developed by Michael Kwayisi"
##      Alternately, this acknowledgment may appear in the software itself,
##      if and wherever such third-party acknowledgments normally appear.
##   4. Neither the name of the software nor the name of its author and/or
##      contributors may be used to endorse or promote products derived from
##      this software without specific prior written permission.
##*****************************************************************************
##

UNICODE = Yes

EXEF := afgp.exe
BIND := bin
OBJD := obj
OBJS := $(OBJD)/main.o $(OBJD)/libwin32.o $(OBJD)/main.res

CC := gcc
CFLAGS := -c -Wall
ifdef UNICODE
CFLAGS := $(CFLAGS) -D_UNICODE -DUNICODE
endif
LFLAGS := -Wall -mwindows -o $(BIND)/$(EXEF) $(OBJS) -lcomctl32

RC := windres
RFLAGS := -O coff

##===========================================================================##

.PHONY : all clean debug release trace launch
all : clean release

clean :
	if exist $(OBJD) rd $(OBJD) /s /q
	if exist $(BIND) rd $(BIND) /s /q

debug : CFLAGS := -g $(CFLAGS)
debug : $(OBJD) $(OBJS) $(BIND)
	$(CC) -g $(LFLAGS)

release : CFLAGS := -s -O3 $(CFLAGS)
release : $(OBJD) $(OBJS) $(BIND)
	$(CC) -s -O3 $(LFLAGS)

trace :
	cd $(BIND) && $(EXEF)
launch :
	cd $(BIND) && start $(EXEF)

##===========================================================================##

$(OBJD)/main.o : src/main.c src/main.h src/design.h
	$(CC) $(CFLAGS) -o $@ $<

$(OBJD)/main.res : src/main.rc src/main.h
	$(RC) $(RFLAGS) -o $@ $<

$(OBJD)/libwin32.o : src/libwin32.c src/libwin32.h
	$(CC) $(CFLAGS) -o $@ $<

$(OBJD) $(BIND) :
	md $@
