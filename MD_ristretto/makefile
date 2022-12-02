# This Makefile will build a DLL and an application which makes use of the DLL.

# Object files to create for the executable
DLL_OBJS = obj\ristretto-donna.o 
EXE_OBJS = obj\test-ristretto.o

# Warnings to be raised by the C compiler
WARNS = -Wall -Wextra

# Names of tools to use when building
CC = gcc
RC = windres
EXE = ristretto-donna-test.exe
DLL = libristretto-donna.dll

# Compiler flags
EXE_CFLAGS = -O2 -std=c99 ${WARNS} -Iinclude
DLL_CFLAGS = ${EXE_CFLAGS} -D DEBUGGING

# Linker flags
DLL_LDFLAGS = -shared -s -Wl,--subsystem,windows,--out-implib,lib/libristretto-donna.a
EXE_LDFLAGS = -Llib -lristretto-donna -s -Wl,--subsystem,console


# Build DLL and executable by default
all: bin\${DLL} bin\${EXE}

# Delete all build output
clean:
	if exist bin\* del /q bin\*
	if exist lib\* del /q lib\*
	if exist obj\* del /q obj\*

# Create build output directories if they don't exist
bin lib obj:
	@if not exist "$@" mkdir "$@"

# Compile object files for DLL
obj\ristretto-donna.o: src\ristretto-donna.c include\ristretto-donna.h 
	${CC} ${DLL_CFLAGS} -c "$<" -o "$@"

# Compile object files for executable
obj\test-ristretto.o: src\test-ristretto.c include\ristretto-donna.h 
	${CC} ${EXE_CFLAGS} -c "$<" -o "$@"

# Build the DLL
bin\${DLL}: ${DLL_OBJS} 
	${CC} -o "$@" ${DLL_OBJS} ${DLL_LDFLAGS}

# Buld the executable
bin\${EXE}: ${EXE_OBJS} 
	${CC} -o "$@" ${EXE_OBJS} ${EXE_LDFLAGS}
