read -p "enter the name to convert : " name
cases(){
	convert=$(echo "$name" |tr '[:lower:]' '[:upper:]')
	echo " after converting : $convert"
}
cases

