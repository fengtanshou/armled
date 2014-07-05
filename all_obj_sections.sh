arm-none-eabi-objdump -h obj/* | awk '{print $2}' | grep '^\..*' | sort -u
