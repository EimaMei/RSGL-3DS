PATH = AddPathHere
VERSION = main

all:
	@echo ""
	@echo "2 Warnings:"
	@echo ""
	@echo "1. You must have devkitPro 3DS-development installed into your machine."
	@echo "!! 2. You need to edit this Makefile's PATH variable to include the path of devkitARM (for example, if the devkitARM's path is C:\devkitPro\devkitARM, you'll need to copy that path and paste it in the PATH variable's 'AddPathHere'). If ignored, it wont work !!"
	@echo ""
	@echo ""
	@echo "COMMANDS: make install, update, remove, credits"
	@echo ""


install:
	mv ../RSGL-for-3DS-$(VERSION)/RSGL3DS/ $(PATH)/arm-none-eabi/include/RSGL3DS
update:
	rm -r $(PATH)/arm-none-eabi/include/RSGL3DS
	mv ../RSGL-for-3DS-$(VERSION)/RSGL3DS/ $(PATH)/arm-none-eabi/include/RSGL3DS
remove:
	rm -r $(PATH)/arm-none-eabi/include/RSGL3DS
credits:
	@echo "ColleagueRiley - Creator and Author of RSGL as well as RSGL Wii"
	@echo "EimaMei (me!) - Creator of RSGL 3DS 1.0 and 2.0"
	@echo "Linux - for being a pog OS"
	@echo "Homebrew community - for making this possible in the first place, and giving hacked consoles great games/emulators/apps etc. for years!"
	@echo ""