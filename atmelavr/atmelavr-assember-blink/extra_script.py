Import("env")
env.Replace(LINKFLAGS=["-mmcu=$BOARD_MCU", "-nostartfiles"])
