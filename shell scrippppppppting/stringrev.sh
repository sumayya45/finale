read -p "enter a string" name 
revsrs(){
	newstr=$(echo $name | rev)
	echo "reersed string is : $newstr"
}
revsrs
