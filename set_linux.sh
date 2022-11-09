sed -i 's/${LMLX_MACOS}/${LMLX_LINUX}/g' Makefile
sed -i 's/${IMLX_MACOS}/${IMLX_LINUX}/g' Makefile
sed -i 's/_KEY_MAC/_KEY_LIN/g' srcs/*.c srcs/*/*.c