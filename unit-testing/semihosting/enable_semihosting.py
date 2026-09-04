Import("env")

env.Append(
    # Remove stub implementations
    BUILD_UNFLAGS=[
        "-lnosys",
        "--specs=nosys.specs",
    ],

    # Use the semihosted version of the syscalls
    LINKFLAGS=[
        "--specs=rdimon.specs",
    ],
    LIBS=[
        "rdimon",
    ],
)
