
dbx: dbx.o
	g++ dbx.o -o dbx

dbx.o: dbx.cpp
	g++ -c dbx.cpp

clean:
	rm *.o dbx