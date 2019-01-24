OBJS = Main.o Door.o Wall.o Room.o Maze.o MazeGame.o MazeFactory.o


main: $(OBJS)
	g++ $(OBJS) -o main
Main.o: ./source/Main.cpp
	g++ -c $<
%.o: ./source/%.cpp ./include/%.h
	g++ -c $<

# %.o: %.asm
# 	$(ASM) $(ASM_KERNEL_FLAGS) -o $@ $<

clean:
	rm ./*.o main
