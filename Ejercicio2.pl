:- use_module(library(clpfd)).

%en prolog la declaración de variables es básicamente cualquier nombre que empiece por mayúscula o "_".
%por lo que para este proyecto y a manera en la cual se pueda diferenciar de una manera más visual.
%ocuparemos "_" para todas las variables, consiguiendo así que se puedan diferenciar del resto.
%se declararán constantes usando el concepto de Átomos(constantes).
%consiste en declarar variables fijas las cuales no cambiarán su contenido a lo largo del código.


%salas fijas: sala((ID), capacidad, [equipamiento]).
sala(sala_1, 10, [pizarra]).
sala(sala_2, 20, [pizarra]).
sala(sala_3, 50, [pizarra]).

