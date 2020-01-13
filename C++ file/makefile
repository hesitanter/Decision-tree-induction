make:main.o hanshu.o tree.o
	g++ main.o hanshu.o tree.o -o a
main.o:main.cpp hanshu.h tree.h
	g++ -c main.cpp hanshu.h tree.h
hanshu.o:hanshu.cpp hanshu.h tree.h
	g++ -c hanshu.cpp hanshu.h tree.h
tree.o:tree.h tree.cpp hanshu.h
	g++ -c hanshu.h tree.h tree.cpp
clean:
	rm -f *.o *.h.gch
