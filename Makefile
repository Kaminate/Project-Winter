OBJ=main.o
EXE=Shadersnow.exe

$(EXE) : $(OBJ)
	g++ $(OBJ) -o $(EXE)
	rm main.o
	
main.o:
	g++ -c main.cpp

clean:
	rm -f $(OBJ) Shadersnow
	
