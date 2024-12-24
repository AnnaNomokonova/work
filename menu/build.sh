MAIN="menu_functions.cpp menu_items.cpp main.cpp "
APP=example

if [ ! -f $APP ]; then rm $APP
fi

g++ $MAIN -o $APP

./$APP
