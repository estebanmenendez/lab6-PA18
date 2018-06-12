#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/cc38c26e/ListDiccIterator.o \
	${OBJECTDIR}/_ext/cc38c26e/ListDiccIteratorKey.o \
	${OBJECTDIR}/_ext/cc38c26e/ListDiccIteratorObj.o \
	${OBJECTDIR}/_ext/cc38c26e/ListaDicc.o \
	${OBJECTDIR}/_ext/cc38c26e/NodoDicc.o \
	${OBJECTDIR}/_ext/cc38c26e/Par.o \
	${OBJECTDIR}/ContGrupo.o \
	${OBJECTDIR}/ContMensaje.o \
	${OBJECTDIR}/ContUsuario.o \
	${OBJECTDIR}/Contacto.o \
	${OBJECTDIR}/Conversacion.o \
	${OBJECTDIR}/DtConexion.o \
	${OBJECTDIR}/DtContacto.o \
	${OBJECTDIR}/DtConversacion.o \
	${OBJECTDIR}/DtFecha.o \
	${OBJECTDIR}/DtFechaHoraIng.o \
	${OBJECTDIR}/DtFechaHoraVisto.o \
	${OBJECTDIR}/DtGrupo.o \
	${OBJECTDIR}/DtHora.o \
	${OBJECTDIR}/DtImagen.o \
	${OBJECTDIR}/DtMensaje.o \
	${OBJECTDIR}/DtMensajeVisto.o \
	${OBJECTDIR}/DtSimple.o \
	${OBJECTDIR}/DtTipo.o \
	${OBJECTDIR}/DtUltCon.o \
	${OBJECTDIR}/EstadoConv.o \
	${OBJECTDIR}/Fabrica.o \
	${OBJECTDIR}/Fecha_Hora_sis.o \
	${OBJECTDIR}/Grupo.o \
	${OBJECTDIR}/ICollectible.o \
	${OBJECTDIR}/IDictionary.o \
	${OBJECTDIR}/IKey.o \
	${OBJECTDIR}/Imagen.o \
	${OBJECTDIR}/Lista.o \
	${OBJECTDIR}/ListaIterator.o \
	${OBJECTDIR}/Mensaje.o \
	${OBJECTDIR}/Multimedia.o \
	${OBJECTDIR}/Nodo.o \
	${OBJECTDIR}/Simple.o \
	${OBJECTDIR}/StringKey.o \
	${OBJECTDIR}/Tipo.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/Video.o \
	${OBJECTDIR}/Visto.o \
	${OBJECTDIR}/iContGrupo.o \
	${OBJECTDIR}/iContMensaje.o \
	${OBJECTDIR}/iContUsuario.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6-pa18

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6-pa18: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6-pa18 ${OBJECTFILES} ${LDLIBSOPTIONS}
<<<<<<< HEAD

${OBJECTDIR}/_ext/cc38c26e/ListDiccIterator.o: ../../Descargas/ColeccionesG/ListDiccIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cc38c26e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cc38c26e/ListDiccIterator.o ../../Descargas/ColeccionesG/ListDiccIterator.cpp

${OBJECTDIR}/_ext/cc38c26e/ListDiccIteratorKey.o: ../../Descargas/ColeccionesG/ListDiccIteratorKey.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cc38c26e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cc38c26e/ListDiccIteratorKey.o ../../Descargas/ColeccionesG/ListDiccIteratorKey.cpp

${OBJECTDIR}/_ext/cc38c26e/ListDiccIteratorObj.o: ../../Descargas/ColeccionesG/ListDiccIteratorObj.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cc38c26e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cc38c26e/ListDiccIteratorObj.o ../../Descargas/ColeccionesG/ListDiccIteratorObj.cpp

${OBJECTDIR}/_ext/cc38c26e/ListaDicc.o: ../../Descargas/ColeccionesG/ListaDicc.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cc38c26e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cc38c26e/ListaDicc.o ../../Descargas/ColeccionesG/ListaDicc.cpp

${OBJECTDIR}/_ext/cc38c26e/NodoDicc.o: ../../Descargas/ColeccionesG/NodoDicc.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cc38c26e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cc38c26e/NodoDicc.o ../../Descargas/ColeccionesG/NodoDicc.cpp

${OBJECTDIR}/_ext/cc38c26e/Par.o: ../../Descargas/ColeccionesG/Par.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/cc38c26e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/cc38c26e/Par.o ../../Descargas/ColeccionesG/Par.cpp
=======
>>>>>>> 3e52aa3745bc2fb1111846de275b14fcd00c9efa

${OBJECTDIR}/ContGrupo.o: ContGrupo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContGrupo.o ContGrupo.cpp

${OBJECTDIR}/ContMensaje.o: ContMensaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContMensaje.o ContMensaje.cpp

${OBJECTDIR}/ContUsuario.o: ContUsuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContUsuario.o ContUsuario.cpp

${OBJECTDIR}/Contacto.o: Contacto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Contacto.o Contacto.cpp

${OBJECTDIR}/Conversacion.o: Conversacion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Conversacion.o Conversacion.cpp

${OBJECTDIR}/DtConexion.o: DtConexion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtConexion.o DtConexion.cpp

${OBJECTDIR}/DtContacto.o: DtContacto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtContacto.o DtContacto.cpp

${OBJECTDIR}/DtConversacion.o: DtConversacion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtConversacion.o DtConversacion.cpp

${OBJECTDIR}/DtFecha.o: DtFecha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtFecha.o DtFecha.cpp

${OBJECTDIR}/DtFechaHoraIng.o: DtFechaHoraIng.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtFechaHoraIng.o DtFechaHoraIng.cpp

${OBJECTDIR}/DtFechaHoraVisto.o: DtFechaHoraVisto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtFechaHoraVisto.o DtFechaHoraVisto.cpp

${OBJECTDIR}/DtGrupo.o: DtGrupo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtGrupo.o DtGrupo.cpp

${OBJECTDIR}/DtHora.o: DtHora.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtHora.o DtHora.cpp

${OBJECTDIR}/DtImagen.o: DtImagen.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtImagen.o DtImagen.cpp

${OBJECTDIR}/DtMensaje.o: DtMensaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtMensaje.o DtMensaje.cpp

${OBJECTDIR}/DtMensajeVisto.o: DtMensajeVisto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtMensajeVisto.o DtMensajeVisto.cpp

${OBJECTDIR}/DtSimple.o: DtSimple.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtSimple.o DtSimple.cpp

${OBJECTDIR}/DtTipo.o: DtTipo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtTipo.o DtTipo.cpp

${OBJECTDIR}/DtUltCon.o: DtUltCon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtUltCon.o DtUltCon.cpp

${OBJECTDIR}/EstadoConv.o: EstadoConv.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EstadoConv.o EstadoConv.cpp

${OBJECTDIR}/Fabrica.o: Fabrica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fabrica.o Fabrica.cpp

${OBJECTDIR}/Fecha_Hora_sis.o: Fecha_Hora_sis.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fecha_Hora_sis.o Fecha_Hora_sis.cpp

${OBJECTDIR}/Grupo.o: Grupo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grupo.o Grupo.cpp

${OBJECTDIR}/ICollectible.o: ICollectible.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollectible.o ICollectible.cpp

${OBJECTDIR}/IDictionary.o: IDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IDictionary.o IDictionary.cpp

${OBJECTDIR}/IKey.o: IKey.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IKey.o IKey.cpp

${OBJECTDIR}/Imagen.o: Imagen.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Imagen.o Imagen.cpp

${OBJECTDIR}/Lista.o: Lista.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lista.o Lista.cpp

${OBJECTDIR}/ListaIterator.o: ListaIterator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaIterator.o ListaIterator.cpp

${OBJECTDIR}/Mensaje.o: Mensaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mensaje.o Mensaje.cpp

${OBJECTDIR}/Multimedia.o: Multimedia.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Multimedia.o Multimedia.cpp

${OBJECTDIR}/Nodo.o: Nodo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo.o Nodo.cpp

${OBJECTDIR}/Simple.o: Simple.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simple.o Simple.cpp

${OBJECTDIR}/StringKey.o: StringKey.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StringKey.o StringKey.cpp

${OBJECTDIR}/Tipo.o: Tipo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tipo.o Tipo.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/Video.o: Video.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Video.o Video.cpp

${OBJECTDIR}/Visto.o: Visto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Visto.o Visto.cpp

${OBJECTDIR}/iContGrupo.o: iContGrupo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iContGrupo.o iContGrupo.cpp

${OBJECTDIR}/iContMensaje.o: iContMensaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iContMensaje.o iContMensaje.cpp

${OBJECTDIR}/iContUsuario.o: iContUsuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iContUsuario.o iContUsuario.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
