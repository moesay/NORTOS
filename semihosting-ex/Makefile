#*****************************************************************************#
#                              ╔═╦═╗═══╔══╗═════                              #
#                              ║║║║╠═╦═╣══╬═╗╔╦╗                              #
#                              ║║║║║╬║╩╬══║╬╚╣║║                              #
#                              ╚╩═╩╩═╩═╩══╩══╬╗║                              #
#                              ══════════════╚═╝                              #
#                  Moesay GNU Arm Tool Chain Generic Makefile                 #
#                                                                             #
#    Author: Mohamed ElSayed                                                  #
#    email : m.elsayed4420@gmail.com	                                      #
#                                                                             #
#    USAGE NOTES:                                                             #
#      - This script uses OpenOCD for flashing and debugging purposes,        #
#         consider installing it from https://openocd.org                     #
#      - This script creates a .gdbinit file to auto-start                    #
#         your debugging session right after running gdb.                     #
#         Enable access to this file by adding this line to ~/.gdbinit        #
#         add-auto-load-safe-path {absolute project path}.gdbinit             #
#         or use                                                              #
#         set auto-load safe-path /                                           #
#         to enable access to all local .gdbinit files created by this scrip. #
#                                                                             #
#    Commands:                                                                #
#        make          Build in the current mode (stored at MODE variable)    #
#        make -r       Build in release mode.                                 #
#        make flash    Build and flash the code to the target.                #
#        make erase    Erase the target flash memory.                         #
#        make debug    Starts a debugging session.                            #
#                                                                             #
#*****************************************************************************#

#-------------------------CONFIGURATION VARIABLES-------------------------#

#-----------------------------PROJECT & FILES-----------------------------#
PROJECT 		:= NoRTOS-SH
INCLUDES  		:= ../../../CMSIS/CMSIS/Core/Include/ \
				   ../../../TM4C123/ \
				   ../NORTOS/

LD_SCRIPT 		:= linker.ld
VPATH 			:= .
LIB_DIRS  		:=

#Prefix the lib name with -l flag and adhere to GCC libs naming conventions
#Ex:
#-l:libdriver.a      The library file name -> libdriver.a
#-ldriverlib         The library file name -> libdriverlib.a
LIBS      		:= -lrdimon
MODE 			:= debug 		#[debug | release]

#The script will auto-include all the source files in the current working dir
#If your project spans over more folders, include them here.
C_SRC_DIRS		:= ../NORTOS
CPP_SRCS_DIRS 	:=
ASM_SRC_DIRS	:=
#-------------------------------------------------------------------------#

#----------------------------COMPILER & LINKER----------------------------#
OPT_LEVEL 		:= -O1     		#Optimization level flag for release mode
EXT_C_FLAGS		:=
EXT_CPP_FLAGS	:=
SPECS 			:= --specs rdimon.specs
DEFINES   		:= -DTM4C123GH6PM
#-------------------------------------------------------------------------#

#----------------------------------TARGET---------------------------------#
ARM_CPU   		:= -mcpu=cortex-m4
ARM_ARCH  		:=  armv7
ARM_FPU   		:= -mfpu=vfp
FLOAT_ABI 		:= -mfloat-abi=softfp

OOCD_CFG_FILE	:= ti_ek-tm4c123gxl.cfg
#-------------------------------------------------------------------------#

#------------------------CONFIGURATION SECTION END------------------------#

ifneq (, $(findstring r, $(MAKEFLAGS)))
MODE = release
else
MODE = debug
endif

INCLUDES := $(addprefix -I, $(INCLUDES))
LIB_DIRS := $(addprefix -L, $(LIB_DIRS))

VPATH += $(C_SRC_DIRS) $(CPP_SRC_DIRS) $(ASM_SRC_DIRS)
ASM_SRCS	:= $(wildcard *.s) $(wildcard $(ASM_SRC_DIRS)/*.s)
C_SRCS		:= $(wildcard *.c) $(wildcard $(C_SRC_DIRS)/*.c)
CPP_SRCS 	:= $(wildcard *.cpp) $(wildcard $(CPP_SRC_DIRS)/*.cpp)

ifeq ($(shell which arm-none-eabi-gcc), "")
$(error GNU Arm Toolchain is not found)
endif

CC    := arm-none-eabi-gcc
CPP   := arm-none-eabi-g++
AS    := arm-none-eabi-as
LINK  := arm-none-eabi-gcc
BIN   := arm-none-eabi-objcopy

ifeq (release, $(MODE))

BIN_DIR  := release

ASFLAGS  = $(ARM_CPU) $(ARM_FPU)

CFLAGS   = -c $(ARM_CPU) $(ARM_FPU) $(FLOAT_ABI) -mthumb -Wall \
		   -ffunction-sections -fdata-sections $(EXT_C_FLAGS)\
		   $(OPT_LEVEL) $(INCLUDES) $(DEFINES) -DNDEBUG

CPPFLAGS = -c $(ARM_CPU) $(ARM_FPU) $(FLOAT_ABI) -mthumb -Wall \
		   -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions $(EXT_CPP_CLAGS)\
		   $(OPT_LEVEL) $(INCLUDES) $(DEFINES) -DNDEBUG
else

BIN_DIR  := debug

ASFLAGS  = -g $(ARM_CPU) $(ARM_FPU)

CFLAGS   = -c -g $(ARM_CPU) $(ARM_FPU) $(FLOAT_ABI) -mthumb -Wall \
		   -ffunction-sections -fdata-sections $(EXT_C_FLAGS)\
		   -O0 -g3 $(INCLUDES) $(DEFINES)

CPPFLAGS = -c -g $(ARM_CPU) $(ARM_FPU) $(FLOAT_ABI) -mthumb -Wall \
		   -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions $(EXT_CPP_CLAGS)\
		   -O0 -g3 $(INCLUDES) $(DEFINES)
endif

OUTPUT    := $(PROJECT)
LINKFLAGS := -T$(LD_SCRIPT) $(ARM_CPU) $(ARM_FPU) $(FLOAT_ABI) -mthumb $(SPECS)\
			 -Wl,-Map,$(BIN_DIR)/$(OUTPUT).map,--cref,--gc-sections $(LIB_DIRS)

ASM_OBJS   := $(patsubst %.s,%.o,  $(notdir $(ASM_SRCS)))
C_OBJS     := $(patsubst %.c,%.o,  $(notdir $(C_SRCS)))
CPP_OBJS   := $(patsubst %.cpp,%.o,$(notdir $(CPP_SRCS)))

TARGET_BIN   	:= $(BIN_DIR)/$(OUTPUT).bin
TARGET_ELF   	:= $(BIN_DIR)/$(OUTPUT).elf
ASM_OBJS_EXT 	:= $(addprefix $(BIN_DIR)/, $(ASM_OBJS))
C_OBJS_EXT   	:= $(addprefix $(BIN_DIR)/, $(C_OBJS))
CPP_OBJS_EXT 	:= $(addprefix $(BIN_DIR)/, $(CPP_OBJS))

ifeq ("$(wildcard $(BIN_DIR))","")
$(shell mkdir $(BIN_DIR))
endif

all: $(TARGET_BIN)

$(TARGET_BIN): $(TARGET_ELF) $(LD_SCRIPT) Makefile
	@$(BIN) -O binary $< $@
	@echo "\e[32mGenerating\e[0m " $@

$(TARGET_ELF) : $(ASM_OBJS_EXT) $(C_OBJS_EXT) $(CPP_OBJS_EXT)
	@$(LINK) $(LINKFLAGS) -o $@ $^ $(LIBS)
	@echo "\e[32mLinking\e[0m " $^

$(BIN_DIR)/%.o : %.s
	@$(AS) $(ASFLAGS) $< -o $@
	@echo "\e[32mCompiling\e[0m " $<

$(BIN_DIR)/%.o : %.c
	@$(CC) $(CFLAGS) $< -o $@
	@echo "\e[32mCompiling\e[0m " $<

$(BIN_DIR)/%.o : %.cpp
	@$(CPP) $(CPPFLAGS) $< -o $@
	@echo "\e[32mCompiling\e[0m " $<

.PHONY : clean flash erase show
clean:
	-rm $(BIN_DIR)/*.o   \
		$(BIN_DIR)/*.bin \
		$(BIN_DIR)/*.elf \
		$(BIN_DIR)/*.map
variables:
	@echo PROJECT 		= $(PROJECT)
	@echo MODE 			= $(MODE)
	@echo DEFINES 		= $(DEFINES)
	@echo INCLUDES 		= $(INCLUDES)
	@echo ASM_SRCS 		= $(ASM_SRCS)
	@echo C_SRCS 		= $(C_SRCS)
	@echo CPP_SRCS 		= $(CPP_SRCS)
	@echo TARGET_ELF 	= $(TARGET_ELF)
	@echo C_FLAGS		= $(CFLAGS) $(EXT_C_FLAGS)
	@echo CPP_FLAGS		= $(CPPFLAGS) $(EXT_CPP_FLAGS)
	@echo LINK_FLAGS	= $(LINKFLAGS)
	@echo VPATH			= $(VPATH)

flash: all
	@if which openocd >/dev/null; then\
		openocd -f board/$(OOCD_CFG_FILE) -c "program $(TARGET_ELF) verify reset exit";\
		else\
		echo "OpenOCD is not found. Download it from https://openocd.org";\
		echo "Flashing process terminated.";\
		exit 0;\
		fi;

erase:
	@if which openocd >/dev/null; then\
		openocd -f board/$(OOCD_CFG_FILE) -c "flash init; init; reset halt; flash erase_sector 0 1 last; exit";\
		else\
		echo "OpenOCD is not found. Download it from https://openocd.org";\
		echo "Erasing process terminated.";\
		exit 0;\
		fi;

debug: all
	@echo "tui enable\ntarget extended-remote :3333\nfile ${TARGET_ELF}\nmonitor arm semihosting enable" > .gdbinit
	@if which openocd >/dev/null; then\
		openocd -f board/$(OOCD_CFG_FILE) -c "flash init; init";\
		else\
		echo "OpenOCD is not found. Download it from https://openocd.org";\
		echo "Erasing process terminated.";\
		exit 0;\
		fi;
