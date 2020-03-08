server:
	gcc server.c game_logic.c -o server.out
client:
	gcc client.c game_logic.c -o client.out -lglut -lGL
clean:
	rm *.out
