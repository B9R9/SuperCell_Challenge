
#Couleur
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

#CLEAN & FCLEAN
RM := rm -f
RM_DIR := rm -rf

all: clear
	@echo "$(GREEN)Building Project$(RESET)"
	@make -sC ./build/

clean:
	@echo "$(RED)Removing executable: /build/bin/LittleCloud$(RESET)"
	@echo "$(RED)Removing SMLF Libs:"
	@echo "\t- libsfml-audio-s.a"
	@echo "\t- libsfml-graphics-s.a"
	@echo "\t- libsfml-network-s.a"
	@echo "\t- libsfml-system-s.a"
	@echo "\t- libsfml-window-s.a$(RESET)"
	@make -sC ./build/ clean

re: fclean all

clear:
	@clear

run: clear
	@./build/bin/LittleCloud

build:
	@echo "$(GREEN)Building $(NAME) $(RESET)"
	@cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	@cmake --build build

buildrun:
	@./build/bin/LittleCloud

destroy:
	@echo "$(RED)Removing Folder: Build$(RESET)"
	@rm -rf build

XcodeProjet:
	@echo "$(GREEN)Creating Xcode Project$(RESET)"
	@./generatex_xcode_project.sh

delete_sfml:
	@echo "$(RED)Removing Folder: SFML DIRECTORY$(RESET)"
	@rm -rf $(SFML_DIR)

download_sfml:
	@if [ ! -d "$(SFML_DIR)" ]; then \
		@echo "$(GREEN)Downloading SFML$(RESET)"; \
		mkdir -p $(SFML_DIR); \
		cd $(SFML_DIR) && git clone --branch 2.6.x https://github.com/SFML/SFML.git; \
		cd $(SFML_DIR)/SFML && cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF; \
		cd $(SFML_DIR)/SFML && cmake --build build; \
	else \
		@echo "$(GREEN)SFML directory already exists. Skipping download.$(RESET)"; \
	fi

reset: Delete_sfml fclean destroy

.PHONY: clean fclean all re clear run download_sfml


