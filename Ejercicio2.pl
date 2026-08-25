:- use_module(library(clpfd)).

%en prolog la declaración de variables es básicamente cualquier nombre que empiece por mayúscula o "_".
%por lo que para este proyecto y a manera en la cual se pueda diferenciar de una manera más visual.
%ocuparemos "_" para todas las variables, consiguiendo así que se puedan diferenciar del resto.
%se declararán constantes usando el concepto de Átomos(constantes).
%consiste en declarar variables fijas las cuales no cambiarán su contenido a lo largo del código.


%salas fijas: sala((ID), _capacidad, [equipamiento]).
sala(sala_1, 10, [pizarra]).
sala(sala_2, 20, [pizarra]).
sala(sala_3, 50, [pizarra]).

%2. al no existir funciones en prolog se crearan "reglas" las cuales contendran.
% el catalogo. flujo_solicitudes(_solicitudes, _aceptado, _rechazo):-.
flujo_solicitudes(_solicitudes, _aceptado, _rechazo):-
    %creamos otra regla, la cual estará dentro de la regla ya creada para así se active cuando llamemos a la anterior.
    porcesar_solicitud(_solicitudes, [], _aceptado, _rechazo).

%ahora pasaremos a creear los 2 casos.

%caso 1: no hay más solicitudes.
porcesar_fluujo([], _, [], []).

%caso 2: procesar solicitud siguiente (recursivo).
%(((((motor central del programa)))))
porcesar_fluujo([solicitud(_reqID, _franja, _asistentes, _reqEquip) | _resto], _estadoActual, _asignadas, _rechazadas) :-
        
    (asignar_sala(_franja, _asistentes, _reqEquip, _estadoActual, _salaID))
    %de cumplirse la condición, se registra y se agrega al estado actual.
    %cuano una linea termina con "," significa que sigue.
    _asignadas = [asignacion(_reqID, _salaID, _franja) | _restoAsignadas], 
    _rechazadas = _restoRechazadas,
    _nuevoEstado = [asignacion(_reqID, _salaID, _franja) | _estadoActual],
    porcesar_fluujo(_resto, _nuevoEstado, _restoAsignadas, _restoRechazadas);
    %si la condición no se cumple, se busca el motivo (sin alterar el estado de las salas).
    det_motivo(_asistentes, _reqEquip, _franja, _estadoActual, _motivo),
    _asignadas = _restoAsignadas,
    _rechazadas = [rechazo(_reqID, _motivo) | _restoRechazadas],
    porcesar_fluujo(_resto, _estadoActual, _restoAsignadas, _restoRechazadas).

%Restriccioens y condiciones para agregar a una sala.
asignar_sala(_franja, _asistentes, _reqEquip, _estadoActual, _salaID):-
    sala(_salaID, _capacidad, _equipamiento),
    _capacidad #>= _asistentes,
    objetos(_reqEquip, _equipamiento),
    \+ usuario(asignacion(_, _capacidad, _), _capacidad #>= _asistentes)!.

%Lógica que se usará para implementar el rechazo.
det_motivo(_asistentes, _reqEquip, _estadoActual, _salaID):-
    (\+ (sala(_, _capacidad, _), _capacidad #>= _asistentes)
    _motivo = capacidad_insuficiente);
    \+ (sala(_, _, _equipamiento), objetos(_reqEquip, _equipamiento))
    _motivo = equipamiento_insuficiente;
    _motivo = sin_disponibilidad_en_franja).

    