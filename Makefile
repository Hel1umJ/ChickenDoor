######################################################################
# Global variables.
######################################################################
#Compiler; gcc (C), g++ (C++)
CC=gcc
#LD is for any dynamically linked libs (libs derrived from .so files)
LD=ld
WARNS=-Wall -pedantic -Wextra
#g3: adds debugging info
#Include C or CPP flags based on what lang you're compiling
CFLAGS=-g3 -std=gnu11 ${WARNS}
CPPFLAGS = -g3 -std=c++14 ${WARNS}
#Include next line if you're using any standard libraries you want to link
#STD_LIBS= -lpthread -lrt

#target = [execName] (and then use this variable in your build rules)

# hello is an executable I want to build, the rest are handy things
#all: [finalExecutable] [any other final build commands]
all: chickenDoor

#This is champions black magic for generating headers. (LOOK INTO THIS
#IF HEADERS ARE IMPORTANT TO YOU)
# This builds visual symbol (.vs) files and the header files.
#headers: *.c tags
#	./headers.sh

#This is champion's black magic for adding tags to files.
# Tags (for C code) are too handy not to keep up to date.
# This lets us use Control-] with vim (ctags command).
# Alternatively, we can use etags with emacs (etags command).
# Comment out the command that you're NOT using.
#tags: *.c
#	ctags -R
#etags -R


# [name of executable]: [all .o (or src files to compile into exec if not using .o princip.)]
# 	${CC} ${CFLAGS} -o ./Build/$@ ./Build/$^

chickenDoor: ./src/chickenDoor.c
	${CC} ${CFLAGS} -o ./build/$@ ./src/* -lwiringPi


#use one of every build rule below if you want to 
#intermediately compile to .o first
# serialRead.o: serialRead.c
# 	${CC} ${CFLAGS} -c -o ./build/$@ $^


#This next rule is champion's black magic to generate all .o
# This is our master compiler rule to generate .o files.
# It needs all 4 warnings (see WARNS variable defined above)
#%.o:%.c #*.h
#	${CC} ${CFLAGS} -c $< -o $@

#Include a *.h in the requirements for any programs with header files
lab2.zip: headers.awk headers.sh headers_timestamp Makefile README.txt tags *.c *.h
	zip lab2.zip headers.awk headers.sh Makefile README.txt *.c

# removes all .o's, the generated zip, and all exe's. 
clean: 
#	 rm -rf *.o lab2.zip *.exe headers_timestamp tags *.vs *.h
	 rm -rf ./build/*


#	 -Include notes about libraries from GPT chat. 
#	 -Using libs in C: add to linux section; Using .h, .c files OR
#	  compiling into a .a or .so library file, putting header files in their own directory, and then using -L and -l flags to include libraries and -I to specify header file locations.
#	 
#	 -Note: for default lib locations and current directory (/lib, /usr/lib, ( . )), compiler auto seraches these directories for included source files and 
#	 dont need to specify their location with -L, you only need to use -l w/ each specific library.

#	-Note: for an exec that has .so dependencies, final deliverable is an exec + all .so files. For a final deliverable for a rpoj. that only uses static libraries (.o or .a), it is just an executable.