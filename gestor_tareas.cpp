/**
 * @file gestor_tareas.cpp
 * @brief Programa simple en C++ para gestionar una lista de tareas.
 * 
 * Este programa permite al usuario agregar tareas, marcarlas como completadas,
 * eliminarlas y visualizar la lista de tareas actuales mediante un menú interactivo.
 * 
 * @author Byron
 * @date 2025-04-07
 */

 #include <iostream>
 #include <vector>
 #include <string>
 
 using namespace std;
 
 /**
  * @brief Estructura que representa una tarea.
  */
 struct Tarea {
     string descripcion;  ///< Descripción de la tarea
     bool completada;     ///< Estado de la tarea (completada o pendiente)
 };
 
 /**
  * @brief Muestra el menú principal del programa.
  */
 void mostrarMenu() {
     cout << "\n--- Gestor de Tareas ---\n";
     cout << "1. Agregar Tarea\n";
     cout << "2. Marcar Tarea como Completada\n";
     cout << "3. Eliminar Tarea\n";
     cout << "4. Mostrar Tareas\n";
     cout << "5. Salir\n";
     cout << "Seleccione una opción: ";
 }
 
 /**
  * @brief Agrega una nueva tarea a la lista de tareas.
  * 
  * @param tareas Referencia al vector de tareas.
  */
 void agregarTarea(vector<Tarea>& tareas) {
     Tarea nuevaTarea;
     cout << "Ingrese la descripción de la tarea: ";
     cin.ignore();
     getline(cin, nuevaTarea.descripcion);
     nuevaTarea.completada = false;
     tareas.push_back(nuevaTarea);
     cout << "Tarea agregada exitosamente.\n";
 }
 
 /**
  * @brief Muestra todas las tareas actuales en la lista.
  * 
  * @param tareas Referencia constante al vector de tareas.
  */
 void mostrarTareas(const vector<Tarea>& tareas) {
     if (tareas.empty()) {
         cout << "No hay tareas registradas.\n";
         return;
     }
 
     cout << "\nLista de Tareas:\n";
     for (size_t i = 0; i < tareas.size(); ++i) {
         cout << i + 1 << ". " << tareas[i].descripcion
              << " [" << (tareas[i].completada ? "Completada" : "Pendiente") << "]\n";
     }
 }
 
 /**
  * @brief Marca una tarea como completada en la lista.
  * 
  * @param tareas Referencia al vector de tareas.
  */
 void completarTarea(vector<Tarea>& tareas) {
     mostrarTareas(tareas);
     if (tareas.empty()) return;
 
     cout << "Ingrese el número de la tarea a completar: ";
     size_t indice;
     cin >> indice;
 
     if (indice == 0 || indice > tareas.size()) {
         cout << "Número de tarea inválido.\n";
     } else {
         tareas[indice - 1].completada = true;
         cout << "Tarea marcada como completada.\n";
     }
 }
 
 /**
  * @brief Elimina una tarea de la lista.
  * 
  * @param tareas Referencia al vector de tareas.
  */
 void eliminarTarea(vector<Tarea>& tareas) {
     mostrarTareas(tareas);
     if (tareas.empty()) return;
 
     cout << "Ingrese el número de la tarea a eliminar: ";
     size_t indice;
     cin >> indice;
 
     if (indice == 0 || indice > tareas.size()) {
         cout << "Número de tarea inválido.\n";
     } else {
         tareas.erase(tareas.begin() + indice - 1);
         cout << "Tarea eliminada exitosamente.\n";
     }
 }
 
 /**
  * @brief Función principal del programa.
  * 
  * Controla el flujo del programa mediante un menú de opciones.
  * 
  * @return int Código de retorno del programa.
  */
 int main() {
     vector<Tarea> tareas;
     int opcion;
 
     do {
         mostrarMenu();
         cin >> opcion;
 
         switch (opcion) {
             case 1:
                 agregarTarea(tareas);
                 break;
             case 2:
                 completarTarea(tareas);
                 break;
             case 3:
                 eliminarTarea(tareas);
                 break;
             case 4:
                 mostrarTareas(tareas);
                 break;
             case 5:
                 cout << "Saliendo del programa...\n";
                 break;
             default:
                 cout << "Opción no válida. Intente de nuevo.\n";
         }
 
     } while (opcion != 5);
 
     return 0;
 }
 