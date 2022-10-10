run: HeapMerging
	./HeapMerging

HeapMerging.o: HeapMerging.cpp
	g++ -c HeapMerging.cpp

HeapMerging: HeapMerging.o
	g++ HeapMerging.o -o HeapMerging

clean:
	rm -f *.o
	rm HeapMerging
