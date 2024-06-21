arithmatioperation()
{
	local operations=$1
	local num1=${2:-0}
	local num2=${3:-1}
	case $operations in
		add)
			result=$((num1+num2))
			echo "the sum of 2 is : $result"
			;;
		sub)
			result=$((num1-num2))
			echo "sub of 2 is : $result"
			;;
		mul)
			result=$((num1*num2))
			echo "mul of 2 is : $result"
			;;
		div)
			if [$num2 -ne 0]; then
				result=$((num1/num2))
				echo "the mul of 2 is : $result"
			else
				echo "the given number is 0"
			fi
			;;
		*)
			echo "invalid entry"
			;;
	esac
}
echo "select any add/sub/mul/div"
read -r operations
echo "enter num1 valu : "
read -r num1
echo "enter num2 valu : "
read -r num2
arithmatioperation "$operations" "$num1" "$num2"
