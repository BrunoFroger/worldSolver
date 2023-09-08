#############################################################
#                   M a k e f i l e 
# 
#     généré automatiquement le 08/09/2023 à 14:20:04
#         avec buildMakefile (version du 23 Aug 2023)
#                 (c) B. Froger 
# 
#############################################################

#------------------------------------------------------------
# Définition des variables
#------------------------------------------------------------
# de compilation
CC=g++
CCFLAGS=-Wall 
LDFLAGS=

# de definition des répertoires
SRCDIR=src
INCDIR=inc
OBJDIR=obj
BINDIR=bin
INSTALLDIR=~/bin

# de definition des listes de fichiers a traiter
SRCCPP=$(wildcard $(SRCDIR)/*.cpp)
SRCC=$(wildcard $(SRCDIR)/*.c)
TMPCPP=$(patsubst %.cpp, %.o, $(SRCCPP))
TMPC=$(patsubst %.c, %.o, $(SRCC))
TMP=$(TMPCPP) $(TMPC)
OBJ=$(patsubst $(SRCDIR)/%.o, $(OBJDIR)/%.o, $(TMP))
EXEC = $(BINDIR)/worldSolver

# des autres variables
ENTETE = $(info ******************************) $(info *) $(info *   M A K E (worldSolver)) $(info *) $(info ******************************)

#------------------------------------------------------------
# Définition des règles génériques
#------------------------------------------------------------
ALL : $(info $(ENTETE)) $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "Edition de lien de $@ OK"

#------------------------------------------------------------
# Définition des règles pour chaque fichier source
#------------------------------------------------------------
$(OBJDIR)/aide.o: $(SRCDIR)/aide.cpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/analyseParametres.o: $(SRCDIR)/analyseParametres.cpp \
	$(INCDIR)/variables.hpp \
	$(INCDIR)/aide.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp \
	$(INCDIR)/#include  \
	$(INCDIR)/analyseParametres.hpp \
	$(INCDIR)/saisieParametres.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/saisieParametres.o: $(SRCDIR)/saisieParametres.cpp \
	$(INCDIR)/variables.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

#------------------------------------------------------------
# Définition des règles utilitaires
#------------------------------------------------------------
clean: 
	@rm -f $(OBJDIR)/* $(BINDIR)/*
	@echo "Clean OK"

info: 
	@echo "Liste des variables du makefile"
	@echo "CC         = " $(CC)
	@echo "CCFLAGS    = " $(CCFLAGS)
	@echo "LDFLAGS    = " $(LDFLAGS)
	@echo "SRCDIR     = " $(SRCDIR)
	@echo "INCDIR     = " $(INCDIR)
	@echo "OBJDIR     = " $(OBJDIR)
	@echo "BINDIR     = " $(BINDIR)
	@echo "INSTALLDIR = " $(INSTALLDIR)
	@echo "SRCCPP     = " $(SRCCPP)
	@echo "SRCC       = " $(SRCC)
	@echo "TMPCPP     = " $(TMPCPP)
	@echo "TMPC       = " $(TMPC)
	@echo "TMP        = " $(TMP)
	@echo "OBJ        = " $(OBJ)
	@echo "EXEC       = " $(EXEC)

install: 
	@make
	@rm -f $(INSTALLDIR)/worldSolver
	@cp -f $(BINDIR)/worldSolver ~/bin
	@chmod +x $(INSTALLDIR)/worldSolver
	@echo "installation de worldSolver dans ~/bin OK"
