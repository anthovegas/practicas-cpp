# Nombre del ejecutable final
TARGET = ejercicio1_uni.exe

# Compilador (en MSYS2 suele ser g++)
CXX = g++

# Banderas de compilación (errores, advertencias y estándar C++11 o superior)
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SRCS = p1_pc1.cpp funciones.cpp

# Lista de archivos objeto (se generan automáticamente a partir de SRCS)
OBJS = $(SRCS:.cpp=.o)

# Regla principal: Compilar el programa
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos .cpp a .o
%.o: %.cpp funciones.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)