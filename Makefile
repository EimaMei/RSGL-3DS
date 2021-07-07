PATH = /opt/devkitpro/devkitARM
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


install:
	mv ../RSGL-for-3DS-$(VERSION)/RSGL3DS/ $(PATH)/arm-none-eabi/include/RSGL3DS
update:
	rm -r $(PATH)/arm-none-eabi/include/RSGL3DS
	mv ../RSGL-for-3DS-$(VERSION)/RSGL3DS/ $(PATH)/arm-none-eabi/include/RSGL3DS
remove:
	rm -r $(PATH)/arm-none-eabi/include/RSGL3DS
credits:
	@echo "F"