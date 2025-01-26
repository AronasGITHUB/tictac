.PHONY: all install uninstall uncompile run
# script should be run with sudo.

SUDO = sudo

all:
	@gcc ticta.c -o tictac
	@chmod +x tictac-clear.sh
	@echo "Compilation done!"

install:
	@mkdir -p /bin /usr/bin /usr/local/bin /usr/share/man/man1
	@cp tictac /bin /usr/bin /usr/local/bin
	@cp tictac.1 /usr/share/man/man1
	@cp tictac-clear.sh /bin/tictac-clear
	@echo "tictac" >> /bin/tictac-clear
	@cp tictac-clear /bin /usr/bin /usr/local/bin
	@echo "Installation done!"

uninstall:
	$(SUDO) rm -rf /bin/tictac /usr/bin/tictac /usr/local/bin/tictac /usr/share/man/man1/tictac.1
	$(SUDO) rm -rf /bin/tictac-clear /usr/bin/tictac-clear /usr/local/bin/tictac-clear
	@echo "Removal done!"

uncompile:
	@rm tictac
	@chmod -x tictac-clear
	@echo "Uncompilation done!"

run:
	@./tictac-clear.sh

