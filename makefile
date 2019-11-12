CPP = g++ -std=c++0x
RES = 
OBJ = Card.o Deck.o go_fish.o Player.o $(RES)
LINKOBJ = Card.o Deck.o go_fish.o Player.o $(RES)
BIN = gofish
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f

all:gofish

clean:
	${RM} $(OBJ) $(BIN)
$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o gofish $(LIBS)

Card.o: Card.cpp
	$(CPP) -c Card.cpp -o Card.o $(CXXFLAGS)

Deck.o: Deck.cpp
	$(CPP) -c Deck.cpp -o Deck.o $(CXXFLAGS)

go_fish.o: go_fish.cpp
	$(CPP) -c go_fish.cpp -o go_fish.o $(CXXFLAGS)

Player.o: Player.cpp
	$(CPP) -c Player.cpp -o Player.o $(CXXFLAGS)

