#config
name=ld55
od=out/
wd=web/
rd=release/
p=8881

#hardcoded less goooo(set to your raylib)
rl=/home/madi/proj/c/raylib/
rlw=/home/madi/proj/c/raylibw/

#compiler
l_gcc=gcc
w_gcc=x86_64-w64-mingw32-gcc
e_gcc=emcc

files=src/main.c

#--Run---------------------------
run: linux
	./$(od)$(name)
runwin: windows
	wine ./$(od)$(name).exe
runweb: wasm
	firefox-esr http://0.0.0.0:$(p)/
	cd $(wd) && python3 -m http.server $(p)


#--Compile-----------------------
linux:
	-mkdir $(od)
	$(l_gcc) $(files)  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lm -o $(od)$(name)
windows:
	-mkdir $(od)
	$(w_gcc) $(files) -o $(od)$(name).exe -L$(rl)src/ -I$(rl)src -lm  -lraylib
	cp $(rl)src/raylib.dll $(od)

wasm:
	-mkdir $(od)
	-mkdir $(wd)
	$(e_gcc) $(files) -sASYNCIFY -s USE_GLFW=3 -o $(wd)$(name).html -I$(rlw)src -L$(rlw)src -lm -lglfw -lraylib -s ALLOW_MEMORY_GROWTH=1

#--Release-----------------------
windows_rel: windows
	tar cf $(rd)$(name)_win.tar $(od)$(name).exe $(od)raylib.dll
linux_rel: linux
	cp $(od)$(name) $(rd)$(name)_linux
web_rel: wasm
	echo "not yet"

#--Release-----------------------
compilecmd: clean 
	bear -- make

clean:
	-rm -r $(od)
	-rm -r $(wd)
	-rm -r $(rd)

all: clean linux windows wasm
