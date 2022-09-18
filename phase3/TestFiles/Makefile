# Project Utilities
DEV				= SourceCode/CompilerUtilities/Development/
ERROR_HANDLER	= SourceCode/CompilerUtilities/ErrorHandler/

# Project Code
LEX_ANAL	= SourceCode/LexicalAnalysis/

# Destination Directory
DEST		= GeneratedFiles/

# Flags
F_FLAGS = --outfile=$(LEX_ANAL)lexical_anal.cpp

# Clear command line command
CLEAR = clear


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


remake: clean all

all: CompilerUtilities LexicalAnalysis
	$(CLEAR)
	g++ $(DEST)Development.o $(DEST)ErrorHandler.o \
	$(DEST)LexicalAnalysis.o \
	-o ac.exe

clean:
	rm -f $(LEX_ANAL)lexical_anal.hpp $(LEX_ANAL)lexical_anal.cpp \
	$(SYN_ANAL)syntax_anal.hpp $(SYN_ANAL)syntax_anal.cpp $(SYN_ANAL)syntax_anal.output \
	$(DEST)*.o \
	IntermediateCode.quad FinalCode.bin FinalCode.txt *.exe *.stackdump

rerun: remake
	./ac.exe $(file)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


CompilerUtilities: $(DEV)*.cpp $(DEV)*.h $(ERROR_HANDLER)*.cpp $(ERROR_HANDLER)*.h
	g++ -c $(DEV)DevelopmentTools.cpp -o $(DEST)Development.o
	g++ -c $(ERROR_HANDLER)ErrorHandler.cpp -o $(DEST)ErrorHandler.o

LexicalAnalysis: $(LEX_ANAL)lexical_anal.l
	flex $(F_FLAGS) $(LEX_ANAL)lexical_anal.l
	g++ -c $(LEX_ANAL)lexical_anal.cpp -o $(DEST)LexicalAnalysis.o
