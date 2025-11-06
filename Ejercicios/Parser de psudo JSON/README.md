Tópicos de Programación
2C 2025

### Parser de psudo JSON

1)
Se tiene un archivo de texto con formato similar al JSON que contiene un resumen de los datos de los jugadores de la sesión actual de un juego web. La sintaxis del formato de este archivo es correcta y no necesita validación.
Se solicita que lea los jugadores provenientes del archivo de texto "jugadores.txt" utilizando la estructura más conveniente para guardar los datos.

```
{ 
	nombre: Carlos,
	clase: Paladin,
	nivel: 12
},
{ 
	nombre: Pepe,
	clase: Mago,
	nivel: 5
},
{ 
	nombre: Ana,
	clase: Bruja,
	nivel: 9
},
{ 
	nombre: Pancho,
	clase: NULL,
	nivel: 0
},	
{ 
	nombre: Manuel,
	clase: Elfo,
	nivel: 3
}
```

Tenga en cuenta que en este formato:
	- El formato se basa en Clave-Valor.
	- Los caracteres en blanco y de control no son tenidos en cuenta.

2)
Cargue todos los jugadores en un TDA Vector a un archivo binario ordenado por alguna clave de su preferencia (puede ser una clave simple o compuesta).