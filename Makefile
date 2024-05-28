all:
	@cc main.c utils.c map_file_check.c errors.c
	@echo
	./a.out
	@echo
	./a.out .ber
	@echo
	./a.out valid1.ber
	@echo
	./a.out maps/valid1.ber
