# PRÁCTICA DE PRO2 FIB: Circuito de torneos de tenis

#### Lista de comandos:

- `nuevo_jugador p`: lee y añade un nuevo jugador con identificador p (si éste es
válido). El comando admite la forma abreviada `nj`. Si ya existe un jugador en el
circuito con el mismo identificador se imprime un mensaje de error. En caso contrario se añade el jugador con estadísticas a cero y última posición en el ranking y
se imprime el número de jugadores P en el circuito después de añadirlo.

- `nuevo_torneo t c`: lee un nuevo torneo con identificador t y categoría c y lo
añade al circuito (si los datos son válidos). El comando admite la forma abreviada
`nt`. Si la categoría c no está entre 1 y C se imprime un mensaje de error. Si lo está,
pero ya existe un torneo en el circuito con el nombre t, se imprime otro mensaje de
error. En caso contrario se imprime el número de torneos T en el circuito después
de añadirlo.

- `baja_jugador p`: da de baja en el circuito al jugador con identificador p. El comando admite la forma abreviada `bj`. Si no existe un jugador con identificador
p se imprime un mensaje de error. En caso contrario se actualiza el ranking (desplazando una posición hacia arriba los jugadores siguientes en el ranking) y se
imprime el número de jugadores P en el circuito después de darlo de baja. Si más
tarde se añade otro jugador con el mismo nombre es como si el anterior no hubiera
existido.

- `baja_torneo t`: da de baja en el circuito al torneo con identificador t. El comando
admite la forma abreviada `bt`. Si no existe un torneo con identificador t se imprime
un mensaje de error. En caso contrario se actualiza el ranking después de restar los
puntos conseguidos por los jugadores en la última edición del torneo (si se hubiera
jugado alguna) y se imprime el número de torneos T en el circuito después de
darlo de baja. Si más tarde se añade otro torneo con el mismo nombre es como si
el anterior no hubiera existido.

- `iniciar_torneo t`: se lee la inscripción en el torneo t y se confecciona e imprime
el cuadro de emparejamientos de los jugadores inscritos. Se garantiza que el torneo
t existe en el circuito. El comando admite la forma abreviada `it`. Primero se lee el
número n de jugadores inscritos y luego se leen n enteros con sus posiciones en
el ranking actual ordenadas crecientemente. El formato de escritura del cuadro de
emparejamientos se deducirá del juego de pruebas público.

- `finalizar_torneo t`: se leen los resultados del torneo t, se produce e imprime
el cuadro oficial de resultados, y se listan los puntos para el ranking ganados por
cada uno de los participantes; también se actualiza el ranking y las estadísticas de
los jugadores. Se garantiza que el torneo t existe en el circuito y que previamente
se ha ejecutado el comando iniciar_torneo t correspondiente†
. El comando
admite la forma abreviada `ft`. Los resultados del torneo se leen como un árbol
binario de strings en preorden siguiendo la estructura del cuadro de emparejamientos. El formato de escritura del cuadro de resultados se deducirá del juego de
pruebas público. La lista de jugadores y puntos ganados por cada uno se escribe
por orden de ranking de los jugadores en el momento de iniciar el torneo. La actualización del ranking ha de tener en cuenta, además de los puntos ganados en
la presente edición que se suman, los puntos ganados en la edición anterior del
torneo, si la hubiera, que se restan.

- `listar_ranking`: se listan, por orden creciente de ranking actual, la posición, el
nombre y los puntos de cada jugador del circuito. El comando admite la forma
abreviada `lr`.

- `listar_jugadores`: se listan, por orden creciente de identificador (nombre), el
nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada
jugador del circuito. El comando admite la forma abreviada `lj`.

- `consultar_jugador p`: lo mismo que la anterior, pero solamente para el jugador con identificador p. Si no existe un jugador con identificador p se imprime un
mensaje de error. El comando admite la forma abreviada `cj`.

- `listar_torneos`: se listan, por orden creciente de identificador (nombre), el
nombre y la categoría de cada torneo del circuito. El comando admite la forma
abreviada `lt`.

- `listar_categorías`: se listan, por orden creciente de identificador, el nombre y
la tabla de puntos por niveles (en orden creciente de nivel) de cada categoría del
circuito. El comando admite la forma abreviada `lc`.

- `fin`: termina la ejecución del programa


<table>
    <tr>
        <td>En proceso de finalizar</td>
    </tr>
</table>

```c++
#include <iostream>
using namespace std;
int main() {
    while (true) cout << "Esto no acabara nunca" << endl; 
}
```
