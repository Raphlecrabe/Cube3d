sed -i '' 's/${LMLX_LINUX}/${LMLX_MACOS}/g' Makefile
sed -i '' 's/${IMLX_LINUX}/${IMLX_MACOS}/g' Makefile
sed -i '' 's/_KEY_LIN/_KEY_MAC/g' srcs/*.c srcs/*/*.c
sed -i '' 's+mlx_linux/+mlx/+g' Makefile