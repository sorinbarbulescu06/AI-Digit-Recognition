build:
	@gcc recognition.c -o recognition -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
run:
	@./recognition
clean:
	@rm -f recognition