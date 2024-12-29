CXX = g++
CXXFLAGS = -g -I./Game/include
LDFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

SRC = $(shell find Game -name "*.cpp")
OBJ = $(patsubst Game/%.cpp,obj/%.o,$(SRC))
DEP = $(patsubst obj/%.o,obj/%.d,$(OBJ))
BIN = bin/project_name

all: $(BIN)

# Tworzenie pliku wykonywalnego
$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Kompilowanie plików .cpp do .o i generowanie zależności w .d
obj/%.o: Game/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Dołączanie plików zależności
-include $(DEP)

# Sprzątanie plików .o, .d i pliku wykonywalnego
clean:
	rm -rf obj/ $(BIN)
