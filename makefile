all: BobRossRobot

BobRossRobot: Main.o Shape.o Canvas.o CommandHandler.o Rules.o BadException.o Circle.o Rectangle.o Line.o Text.o Group.o SVGCreator.o
		g++ Main.o Shape.o Canvas.o CommandHandler.o Rules.o BadException.o Circle.o Rectangle.o Line.o Text.o Group.o SVGCreator.o -o BobRossRobot

Main.o: Main.cpp Bob.h
		g++ -c Main.cpp

BadException.o: BadException.cpp BadException.h
		g++ -c BadException.cpp

CommandHandler.o: CommandHandler.cpp CommandHandler.h
		g++ -c CommandHandler.cpp

Shape.o: Shape.cpp Shape.h
		g++ -c Shape.cpp

Canvas.o: Canvas.cpp Canvas.h
		g++ -c Canvas.cpp

Rules.o: Rules.cpp Rules.h
		g++ -c Rules.cpp

Circle.o: Circle.cpp Circle.h
		g++ -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
		g++ -c Rectangle.cpp

Line.o: Line.cpp Line.h
		g++ -c Line.cpp

Text.o: Text.cpp Text.h
		g++ -c Text.cpp

Group.o: Group.cpp Group.h
		g++ -c Group.cpp

SVGCreator.o: SVGCreator.cpp SVGCreator.h
		g++ -c SVGCreator.cpp


clean:
		rm *.o BobRossRobot
