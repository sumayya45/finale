 
#read -p "enter the values of num1 : " num1
#read -p  "enter the values of num2 : " num2

calc()
{
	local length=$1
	local height=$2
	sum=$((length*height))
	echo "the sum of 2 is $sum"
}
calc 2 3	
