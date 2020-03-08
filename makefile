server:
	gcc server.c game_logic.c -o server.out
client:
	gcc client.c -o client.out -lglut -lGL
clean:
	rm *.out
