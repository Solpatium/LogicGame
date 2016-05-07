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
	${OBJECTDIR}/LogicGame/Level.o \
	${OBJECTDIR}/LogicGame/LogicGame.o \
	${OBJECTDIR}/LogicGame/LogicPlaything.o \
	${OBJECTDIR}/LogicGame/LogicalNodes.o \
	${OBJECTDIR}/LogicGame/RandomLineTaker.o \
	${OBJECTDIR}/LogicGame/RandomLines.o \
	${OBJECTDIR}/LogicalSentence.o \
	${OBJECTDIR}/Parser.o \
	${OBJECTDIR}/Random.o \
	${OBJECTDIR}/TrinaryLogic.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/polscy_logicy

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/polscy_logicy: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/polscy_logicy ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/LogicGame/Level.o: LogicGame/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicGame
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicGame/Level.o LogicGame/Level.cpp

${OBJECTDIR}/LogicGame/LogicGame.o: LogicGame/LogicGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicGame
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicGame/LogicGame.o LogicGame/LogicGame.cpp

${OBJECTDIR}/LogicGame/LogicPlaything.o: LogicGame/LogicPlaything.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicGame
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicGame/LogicPlaything.o LogicGame/LogicPlaything.cpp

${OBJECTDIR}/LogicGame/LogicalNodes.o: LogicGame/LogicalNodes.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicGame
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicGame/LogicalNodes.o LogicGame/LogicalNodes.cpp

${OBJECTDIR}/LogicGame/RandomLineTaker.o: LogicGame/RandomLineTaker.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicGame
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicGame/RandomLineTaker.o LogicGame/RandomLineTaker.cpp

${OBJECTDIR}/LogicGame/RandomLines.o: LogicGame/RandomLines.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicGame
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicGame/RandomLines.o LogicGame/RandomLines.cpp

${OBJECTDIR}/LogicalSentence.o: LogicalSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogicalSentence.o LogicalSentence.cpp

${OBJECTDIR}/Parser.o: Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser.o Parser.cpp

${OBJECTDIR}/Random.o: Random.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Random.o Random.cpp

${OBJECTDIR}/TrinaryLogic.o: TrinaryLogic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TrinaryLogic.o TrinaryLogic.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/polscy_logicy

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
