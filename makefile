# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g
TARGET = programa

# Encuentra automáticamente todos los archivos .cpp
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(wildcard *.h)

# Regla principal
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para compilar cada .cpp a .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reglas utilitarias
clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

all: $(TARGET)

# Ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make       - Compila el programa"
	@echo "  make run   - Compila y ejecuta"
	@echo "  make clean - Elimina archivos compilados"
	@echo "  make help  - Muestra esta ayuda"

.PHONY: clean run all help