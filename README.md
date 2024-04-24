# Enunciado - Requerimientos
Implementar la clase matrix que acepte el tipo de dato double y deberá realizar múltiples operaciones, como lo son:
+ Suma
+ Resta
+ Multiplicación
+ Obtener el máximo/mínimo
+ Cálculo de la transpuesta
+ Guardar la matriz a un archivo
+ Crear una matriz desde un archivo
+ Imprimir en consola

Se le proveerá un archivo -h con las declaraciones de la clase. Usted debe implementar todos los métodos, los cuales deben ser testeados con Google Test.
# Compilar la librería
Compilar la librería es bastante directo. Usando el Makefile adjunto es tan simple como correr:  

    >make init build

Y para correr los tests:

    >make test

Con la tarea compilada, se puede utilizar en un código cpp incluyendo el header de Matrix.h.

>#include "Matrix.h" 

Una vez echo esto, para compilar usando la librería sería necesario escribir lo siguiente en la terminal:

    >g++ -std=c++23 <archivo>.cpp -L. -lGPU_t1

Debido a las complicaciones que tuve al intentar hacer la tarea en windows, la termine haciendo en Debian12 con VS Code, no sé si se podrá compilar en windows de la misma forma.

# Preguntas
#### 1. ¿Afectaría en algo el tipo de dato de su matriz?, ¿Qué pasa si realiza operaciones de multiplicacion tipo dato 'integer' en vez de 'double'?
Probablemente con tipo integer sea un poco más eficiente haciendo operaciones, a costo de limitar el alcance de la librería. De todas formas, a menos que sea a muy gran escala, el cambio no se notara de sobremanera. Puede que haya algún efecto sobre la precicion de las operaciones matemáticas, pero son las mismas que habría en cualquier otro buen programa de c++.
#### 2. Si se empezaran a usar números muy pequeños o muy grandes y principalmente números primos,¿Qué ocurre en terminos de precisión?
Probablemente las operaciones empezarán a tomar más tiempo y la precicion puede que empeore, especialmente en operaciones con números primos o muy pequeños. Aunque, la precicion sigue siendo totalmente dependiente de como c++ maneje los valores.
#### 3. ¿Puede haber problemas de precisión si se comparan dos matrices idénticas pero con diferente tipo? (Matrix p1 == p2)
Probablemente si, puede que las operaciones sean menos precisas actuando sobre 2 tipos diferentes de datos, por ejemplo se podrían truncar los decimales para convertirlos a enteros y así actuar sobre el mismo tipo de dato perdiendo mucha precisión en el proceso. Depende de la forma en que esté implementada la operacion entre tipos de datos que tan preciso llega a ser, pero definitivamente está la posibilidad de que empeore la calidad de la respuesta al usar dos tipos diferentes.