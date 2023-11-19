# Create target directory if does not exist
if [ ! -d ./target ]; then
    mkdir ./target
fi

# Clear target directory
rm -rf ./target/*

# Compile app into .exe
gcc ./src/*.c ./src/bmi/*.c ./src/converter/*.c ./src/employee/*.c ./src/fibonacci/*.c -o ./target/app.exe

# Run app
./target/app.exe