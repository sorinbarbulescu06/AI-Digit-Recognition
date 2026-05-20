build:
	@gcc recognition.c learning_dir/auxiliar.c learning_dir/invatare.c learning_dir/guess.c learning_dir/try.c -o recognition -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
run:
	@./recognition
clean:
	@rm -f recognition