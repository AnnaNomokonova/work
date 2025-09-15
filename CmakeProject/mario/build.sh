CPP="./src/main.cpp"
EXE="super_mario" 
INCLUDE="-I./lib/PDCurses"
BINARY="-L./lib//PDCurses/build -lpdcurses"
X11_LIBS="-lXaw -lXt -lX11 -lXmu -lXext -lXpm -lm"

if [ -f "$EXE" ]; then
    rm "$EXE"
fi

# sudo chmod +x ./lib/lib_builder.sh
# ./lib/lib_builder.sh

g++ $INCLUDE "$CPP" -o "$EXE" $BINARY $X11_LIBS

if [ -f "$EXE" ]; then
    ./"$EXE"
fi