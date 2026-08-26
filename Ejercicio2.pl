%Ejercicio numero 2

%Autores:
%Gonzalo Fuenzalida Pérez
%Trinidad Morales
%Matias Saldias
%Rodrigo Rosales
%Bastian Salvo


%la declaracion de ia estara en el documento del ejercicio numero 1 junto con el link de la conversacion,
:- use_module(library(clpfd)).

% en prolog la declaracion de variables es basicamente cualquier nombre que empiece por mayuscula o "_".
% por lo que para este proyecto y a manera en la cual se pueda diferenciar de una manera mas visual.
% ocuparemos "_" para todas las variables, consiguiendo asi que se puedan diferenciar del resto.
% se declararan constantes usando el concepto de Atomos(constantes).
% consiste en declarar variables fijas las cuales no cambiaran su contenido a lo largo del codigo.

%para este caso usaremos 3 salas, de ser necesario podrian agregarse mas bajo el siguiente formato.
% salas fijas: sala((ID), _capacidad, [equipamiento]).
sala(sala_1, 10, [pizarra]).
sala(sala_2, 20, [proyector]).
sala(sala_3, 50, [computadora]).

% 2. al no existir funciones en prolog se crearan "reglas" las cuales contendran.
% el catalogo. flujo_solicitudes(_solicitudes, _aceptado, _rechazo):-.
flujo_solicitudes(_solicitudes, _aceptado, _rechazo):-
    procesar_flujo(_solicitudes, [], _aceptado, _rechazo).

% ahora pasaremos a crear los 2 casos.

% caso 1: no hay mas solicitudes.
procesar_flujo([], _, [], []).

% caso 2: procesar solicitud siguiente (recursivo).
% (motor central del programa)

%----------------------------------------------------------------------------------
% PUNTO 1 DEL PARADIGMA: UNIFICACIÓN Y PATTERN MATCHING (Listas y Estructuras)
% A diferencia del paradigma imperativo el cual utiliza (for/while)
% aqui el paradigma logico determina la solucion "desarmando" la lista y la estructura 
% "solicitud(...)" de forma automatica al unificarlas en el principio de la regla.
%----------------------------------------------------------------------------------

procesar_flujo([solicitud(_reqID, _franja, _asistentes, _reqEquip) | _resto], _estadoActual, _asignadas, _rechazadas) :-
    
    (   asignar_sala(_franja, _asistentes, _reqEquip, _estadoActual, _salaID)
    ->  
        _asignadas = [asignacion(_reqID, _salaID, _franja) | _restoAsignadas], 
        _rechazadas = _restoRechazadas,
        _nuevoEstado = [asignacion(_reqID, _salaID, _franja) | _estadoActual],
        procesar_flujo(_resto, _nuevoEstado, _restoAsignadas, _restoRechazadas)
    ;   
        det_motivo(_asistentes, _reqEquip, _franja, _estadoActual, _motivo),
        _asignadas = _restoAsignadas,
        _rechazadas = [rechazo(_reqID, _motivo) | _restoRechazadas],
        procesar_flujo(_resto, _estadoActual, _restoAsignadas, _restoRechazadas)
    ).

% Restricciones y condiciones para agregar a una sala.
asignar_sala(_franja, _asistentes, _reqEquip, _estadoActual, _salaID):-

    %----------------------------------------------------------------------------------
    % PUNTO 2 DEL PARADIGMA: BUSQUEDA IMPLICITA Y BACKTRACKING (Base de Conocimientos)
    % El paradigma determina la solucion de forma declarativa. No le decimos "como" 
    % buscar una sala (no hay iteradores sobre un array de salas). Al declarar 
    % "sala(_salaID, _capacidad, _equipamiento)", Prolog usa su motor de inferencia 
    % (backtracking) para buscar automaticamente entre los hechos la primera sala que 
    % cumpla con esta relacion y las restricciones logicas que le siguen (#>=).
    %----------------------------------------------------------------------------------

    sala(_salaID, _capacidad, _equipamiento),
    _capacidad #>= _asistentes,
    subset(_reqEquip, _equipamiento),
    \+ member(asignacion(_, _salaID, _franja), _estadoActual), !.

% Logica que se usara para implementar el rechazo.
% En la programación logica estricta, la verdad se deduce si algo se puede probar.
% Aqui se determina la solución (el motivo del rechazo) comprobando si el motor 
% "falla" al intentar probar que existe una sala con capacidad suficiente. Si 
% no puede probarlo, asume que es falso y asigna el motivo.
det_motivo(_asistentes, _reqEquip, _, _, _motivo) :-
    (   \+ (sala(_, _capacidad, _), _capacidad #>= _asistentes)
    ->  _motivo = capacidad_insuficiente
    ;   \+ (sala(_, _, _equipamiento), subset(_reqEquip, _equipamiento))
    ->  _motivo = equipamiento_insuficiente
    ;   _motivo = sin_disponibilidad_en_franja
    ).



pedir_datos :-
    format('Ingresa lista de solicitudes y termina con un punto (.):~n~n'),
    format('formato [solicitud("cantidad", (manana, tarde, noche), "cantidad de personas", [equipo])].~n~n'),
    format('formato ejemplo: [solicitud(1, manana, 5, [pizarra]).~n~n'),
    read(_solicitudesIngresadas),
    procesar_flujo(_solicitudesIngresadas, [], _aceptadas, _rechazadas),
    format('~n--- RESULTADOS DE LA ASIGNACION ---~n'),
    
    %Imprimir lista aceptadas de solicitudes.
    format('~nSalas Aceptadas:~n'),
    imprimir_lista(_aceptadas),

    %Imprimir lista Rechazadas de solicitudes.
    format('~nSalas Rechazadas:~n'),
    imprimir_lista(_rechazadas).

%Regla para imprimir datos como en una lista
imprimir_lista([]).
imprimir_lista([_elemento | _resto]):-
    format('  ~w~n', [_elemento]),
    imprimir_lista(_resto).