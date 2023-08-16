# Makefile: Chess Game
# EECS 22L - Spring 2022
# Team 12: Tram Le, Sarah Catania-Orozco, Diego Rodriguez-Orozco, Brandon Huynh, Pranav Balamurali
# Date Modified: 04/12/2022 Alpha Version
# Date Modified: 04/25/2022 Final Release


#Variables definition
CC = gcc
CFLAGS = -Wall -c -std=c11 -g
LFLAGS = -Wall


#Default target
all: bin/chess

#Test board display
test: bin/test

#Generates Setting.o
bin/Setting.o: src/Setting.c src/Setting.h
	$(CC) $(CFLAGS) src/Setting.c -o bin/Setting.o

#Generates Board.o
bin/Board.o: src/Board.c src/Board.h
	$(CC) $(CFLAGS) src/Board.c -o bin/Board.o

#Generates Move.o
bin/Move.o: src/Move.c src/Move.h src/Board.h
	$(CC) $(CFLAGS) src/Move.c -o bin/Move.o

#Generates PlayGame.o
bin/PlayGame.o: src/PlayGame.c src/PlayGame.h src/Board.h src/Move.h
	$(CC) $(CFLAGS) src/PlayGame.c -o bin/PlayGame.o
#Generates AI.o
bin/AI.o: src/AI.c src/AI.h src/Board.h src/Move.h
	$(CC) $(CFLAGS) src/AI.c -o bin/AI.o

#Generates Main.o
bin/main.o: src/main.c src/Move.h src/Board.h src/Setting.h
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

bin/chess: bin/main.o bin/Board.o bin/Move.o bin/Setting.o bin/PlayGame.o bin/AI.o
	$(CC) $(LFLAGS) bin/main.o bin/Board.o bin/Move.o bin/Setting.o bin/PlayGame.o bin/AI.o -o bin/chess

#Test Board Display
bin/TestBoardDisplay.o: src/TestBoardDisplay.c
	$(CC) $(CFLAGS) src/TestBoardDisplay.c -o bin/TestBoardDisplay.o

bin/test: bin/TestBoardDisplay.o bin/Board.o bin/Move.o bin/Setting.o bin/PlayGame.o bin/AI.o  
	$(CC) $(LFLAGS) bin/TestBoardDisplay.o bin/Board.o bin/Move.o bin/Setting.o bin/PlayGame.o bin/AI.o -o bin/test

#Target for clean-up
clean:
	rm -f bin/*.o
	rm -f bin/chess
	rm -f bin/test
	rm -f bin/log.txt

tar:
#SourceArchive
	tar -zcvf Chess_V1.0_src.tar.gz ./doc ./bin ./src ./Makefile ./README ./COPYRIGHT ./INSTALL

tar2:
#BinaryArchive  
	tar -zcvf Chess_V1.0.tar.gz ./doc/Chess_UserManual.pdf ./bin/chess ./README ./COPYRIGHT ./INSTALL

#Target for remove the tar files
cleantar:
	rm *.tar.gz

#Target for remove the bin and doc directory
uninstall:
	rm -rf bin
	rm -rf doc
	rm Makefile

