PROG = snake
OBJ = human.o main.o view.o tview.o gview.o
CXXFLAGS = -g -Wall

all: $(PROG)

$(PROG): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	-rm *.o

depend:
	$(CXX) -MM $(CXXFLAGS) *.cc $(OBJ:.o = .cc) > .depend
-include .depend