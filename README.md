Sebasti�n Campos 201773517-1 
Github: Pantuflaa

Axel Reyes 201773502-3
Github: AxlKings


- Para compilar, utilizar el comando make tomc, para ejecutar utilizar el comando make run.

- Si desea ejecutar nuevamente el programa, debe borrar las carpetas creadas (para que no se acumulen las cartas).

-Aportes:

Sebasti�n Campos:  Creaci�n de carpetas y repartimiento de cartas.

Axel Reyes: Creaci�n de strings, colores, y cartas del mazo.

ENTREGA 2:

- Al pedir el n�mero de la opci�n deseada, por favor no ingresar strings (o explota).
- Para mayor facilidad en la verificaci�n de jugadas v�lidas, se estandariz� al siguiente formato para el nombre de las cartas:

carta = CopiaColorTipo".txt" || Copian"ngr"Tipon".txt" 
Copia = '1' || '2'
Copian = '1' || '2' || '3'|| '4'
Color = 'roj'|| 'ver'|| 'zul' || 'ama' 
Tipo = 'r' || 'b' || 'p' || '0'|| '1' || '2'|| '3'|| '4'|| '5'|| '6'|| '7'|| '8'|| '9'
Tipon = '4' || 'c'

Donde:

Copia:
	[1-2] = Numero de copia de la carta (cartas no negras)

Copian:
	[1-4] = Numero de copia de la carta (cartas negras)

Color:
	roj = Color rojo
	ver = Color verde
	zul = Color Azul
	ama = Color amarillo
	ngr = Color negro

Tipo:
	r = Reversa
	b = Bloqueo
	p = +2
	[0-9] = Carta con n�mero (no especial)
Tipon:
	4 = Carta +4 (negra)
	c = Carta cambiocolor (negra)
		
EJEMPLOS:

	2roj8.txt --> Copia n�mero dos del ocho rojo
	3ngr4.txt --> Copia n�mero tres del +4
	1amap.txt --> Copia n�mero uno del +2 amarillo
	1zulr.txt --> Copia n�mero uno del reversa azul
	2verb.txt --> Copia n�mero dos del bloqueo verde

La carta negra de cambio color para efectos pr�cticos de esta entrega genera una carta "dummy" en el pozo la cual indicar� el color elegido por el jugador que la lanz�

Ejemplo de carta dummy:

	El jugador que lanza el color escoge el azul, por ende la carta que se genera en el pozo ser� --> _zul_.txt (Por ende el jugador s�lo podr� jugar cartas azules o negras)


