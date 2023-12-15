cmd_/home/raspi/C_DS_OS_Cpp/iic/driver.mod := printf '%s\n'   driver.o | awk '!x[$$0]++ { print("/home/raspi/C_DS_OS_Cpp/iic/"$$0) }' > /home/raspi/C_DS_OS_Cpp/iic/driver.mod
