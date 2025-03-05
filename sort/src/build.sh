MAIN="main.cpp print_array.cpp insert_sort.cpp randArray.cpp"
APP=example

if [ ! -f $APP ]; then rm $APP
fi

g++ $MAIN -o $APP

./$APP
