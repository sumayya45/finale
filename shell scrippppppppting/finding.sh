echo "enter something :: "
read input
if [[ $input =~ ^-?[0-9]+$ ]]; then
	echo "you have entered a integer"
elif [[ $input =~ ^-?[0-9]*\.[0-9]+$ ]]; then
	echo "you have entered a float or a double"
else
	echo "you have entered a string"
fi

