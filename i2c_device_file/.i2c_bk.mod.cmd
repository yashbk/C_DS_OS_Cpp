cmd_/home/raspi/C_DS_OS_Cpp/i2c_device_file/i2c_bk.mod := printf '%s\n'   i2c_bk.o | awk '!x[$$0]++ { print("/home/raspi/C_DS_OS_Cpp/i2c_device_file/"$$0) }' > /home/raspi/C_DS_OS_Cpp/i2c_device_file/i2c_bk.mod