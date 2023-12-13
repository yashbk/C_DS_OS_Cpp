cmd_/home/bk/C_DS_OS_Cpp/i2c_dynamic/dynamic.mod := printf '%s\n'   dynamic.o | awk '!x[$$0]++ { print("/home/bk/C_DS_OS_Cpp/i2c_dynamic/"$$0) }' > /home/bk/C_DS_OS_Cpp/i2c_dynamic/dynamic.mod
