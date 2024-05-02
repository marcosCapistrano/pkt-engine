build:
	cc main.c world/world.c game/game.c player/player.c render/camera.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	make build && ./a.out