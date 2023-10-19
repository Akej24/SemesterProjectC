# Clear target directory
rm -rf ./target/*

# Compile app into .exe
gcc ./src/*.c -o ./target/app.exe

# Run app
./target/app.exe