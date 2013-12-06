gcc -c "C Files\ArrayList.c" -o "Object Files\ArrayList.o"
gcc -c "C Files\LinkedList.c" -o "Object Files\LinkedList.o"
gcc -c "C Files\List.c" -o "Object Files\ListTemp.o"

ld -r "Object Files\ArrayList.o" "Object Files\LinkedList.o" "Object Files\ListTemp.o" -o "Object Files\List.o"

del "Object Files\ListTemp.o"