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

%2. al no existir funciones en prolog se crearan "reglas" las cuales contendran.
% el catalogo. flujo_solicitudes(Solicitudes, Aceptado, Rechazao):-.
flujo_solicitudes(Solicitudes, Aceptado, Rechazao):-
    %creamos otra regla, la cual estará dentro de la regla ya creada para así se active cuando llamemos a la anterior.
    porcesar_solicitud(Solicitudes, [], Aceptado, Rechazao).

%ahora pasaremos a creear los 2 casos.

%caso 1: no hay más solicitudes.
porcesar_fluujo([], _, [], []).

%caso 2: procesar solicitud siguiente (recursivo).
porcesar_fluujo([solicitud(ReqID, Franja, Asistentes, ReqEquip) | Resto], EstadoActual, Asignadas, Rechazadas) :-