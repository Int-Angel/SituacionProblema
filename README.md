# SituacionProblema

## Game.h
La clase game se encarga de todo el loop del juego, crea todos los items, habiatciones y eventos, todo lo saca de archivos de texto.

## Comando.h
Recive los comandos los procesa, necesita el string ingresado y al personaje como parametro.
Revisa en la lista de items del jugador y de la habitacion actual para hacer la accion item.iteractuar()
si es una accion de desplazar esto lo hace el jugador.

## Jugador
Desplazar debe revisar a donde se desplaza, si esta permitido, etc.

## Eventos
Cada habitacion tiene un evento y cada que el juagdor hace algo estos eventos deben checar si se cumplen las condiciones para que sean activados.
