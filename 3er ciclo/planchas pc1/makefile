CXX = g++
CXXFLAGS = -Wall -std=c++11

# 1. Definimos los ejecutables
UNI_TARGET1 = ejercicio1_uni.exe
UNI_TARGET2 = ejercicio2_25I.exe
EXAMEN_P3   = ejercicio3_25I.exe
UNI_TARGET4 = ejercicio4_25I.exe 
UNI_TARGET5 = NumerosPerfectos.exe
FREC_TARGET = OrdenarPorFrecuencia.exe  # <--- NUEVO TARGET
CF_A = problemA.exe
CF_B = problemB.exe

# 2. Regla "all" (Agregamos el nuevo target aquí)
all: $(UNI_TARGET1) $(UNI_TARGET2) $(EXAMEN_P3) $(UNI_TARGET4) $(UNI_TARGET5) $(FREC_TARGET) $(CF_A) $(CF_B)

# --- REGLA PARA EL NUEVO EJERCICIO (OrdenarPorFrecuencia) ---
$(FREC_TARGET): OrdenarPorFrecuencia.o OrdenarAscendente.o
	$(CXX) $(CXXFLAGS) -o $(FREC_TARGET) OrdenarPorFrecuencia.o OrdenarAscendente.o

OrdenarPorFrecuencia.o: OrdenarPorFrecuencia.cpp OrdenarAscendente.h
	$(CXX) $(CXXFLAGS) -c OrdenarPorFrecuencia.cpp -o OrdenarPorFrecuencia.o

OrdenarAscendente.o: OrdenarAscendente.cpp OrdenarAscendente.h
	$(CXX) $(CXXFLAGS) -c OrdenarAscendente.cpp -o OrdenarAscendente.o

# --- REGLA PARA EL EJERCICIO (PerfectNum) ---
$(UNI_TARGET5): NumerosPerfectos.o PerfectNum.o
	$(CXX) $(CXXFLAGS) -o $(UNI_TARGET5) NumerosPerfectos.o PerfectNum.o

NumerosPerfectos.o: NumerosPerfectos.cpp PerfectNum.h
	$(CXX) $(CXXFLAGS) -c NumerosPerfectos.cpp -o NumerosPerfectos.o

PerfectNum.o: PerfectNum.cpp PerfectNum.h
	$(CXX) $(CXXFLAGS) -c PerfectNum.cpp -o PerfectNum.o

# --- REGLA PARA LA PREGUNTA 3 ---
$(EXAMEN_P3): ejercicio3_25I.o Sorting.o Array.o
	$(CXX) $(CXXFLAGS) -o $(EXAMEN_P3) ejercicio3_25I.o Sorting.o Array.o

ejercicio3_25I.o: ejercicio3_25I.cpp Sorting.h Array.h
	$(CXX) $(CXXFLAGS) -c ejercicio3_25I.cpp -o ejercicio3_25I.o

Sorting.o: Sorting.cpp Sorting.h
	$(CXX) $(CXXFLAGS) -c Sorting.cpp -o Sorting.o

Array.o: Array.cpp Array.h
	$(CXX) $(CXXFLAGS) -c Array.cpp -o Array.o

# --- REGLA PARA LA PREGUNTA 4 (Delivery) ---
$(UNI_TARGET4): ejercicio4_25I.o Delivery.o
	$(CXX) $(CXXFLAGS) -o $(UNI_TARGET4) ejercicio4_25I.o Delivery.o

ejercicio4_25I.o: ejercicio4_25I.cpp Delivery.h
	$(CXX) $(CXXFLAGS) -c ejercicio4_25I.cpp -o ejercicio4_25I.o

Delivery.o: Delivery.cpp Delivery.h
	$(CXX) $(CXXFLAGS) -c Delivery.cpp -o Delivery.o

# --- OTRAS REGLAS ---
$(UNI_TARGET1): p1_pc1.o funciones.o
	$(CXX) $(CXXFLAGS) -o $(UNI_TARGET1) p1_pc1.o funciones.o

$(UNI_TARGET2): ejercicio2-25I.o
	$(CXX) $(CXXFLAGS) -o $(UNI_TARGET2) ejercicio2-25I.o

$(CF_A): problemA.o
	$(CXX) $(CXXFLAGS) -o $(CF_A) problemA.o

$(CF_B): problemB.o
	$(CXX) $(CXXFLAGS) -o $(CF_B) problemB.o

# Regla genérica para los demás archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza (Agregamos FREC_TARGET)
clean:
	rm -f *.o $(UNI_TARGET1) $(UNI_TARGET2) $(EXAMEN_P3) $(UNI_TARGET4) $(UNI_TARGET5) $(FREC_TARGET) $(CF_A) $(CF_B)