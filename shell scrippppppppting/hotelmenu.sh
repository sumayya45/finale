
totalbill=0
declare -a orders
while true; do
	echo "welcome to the HOTEL"
	echo "********* MENU *************"
	echo "1.roti -30rs"
	echo "2.chawal -70rs"
	echo "3.sambar -20rs"
	echo "4.curry -50rs"
	echo "5.beverages -40rs"
	echo "6.none"
	read -p "enter your choice as 1,2,3,4,5 or menu names " userinpt
case $userinpt in
	1 | roti)
		echo "you have ordered roti -30rs"
		read -p "how many do u want" quant
		sum=$(( quant * 30 ))
		totalbill=$(( totalbill + sum ))
		orders+=("$quant roti -30rs each")
		;;
	2 | chawal)
		echo "you have ordered chawal -70rs"
		read -p "how many do u want : " quant
		sum=$(( quant * 70 ))
		totalbill=$(( totalbill + sum ))
		orders+=("$quant chawal -70rs each")
		;;
	3 | sambar)
		echo "you have ordered sambar -20rs"
		read -p "how many do u want : " quant
		sum=$(( quant * 20 ))
		totalbill=$(( totalbill + sum ))
		orders+=("$quant sambar -20rs each")
		;;
	4 | curry)
		echo "you have ordered curry -50rs"
		read -p "how many do u want : " quant
		sum=$(( quant * 50 ))
		totalbill=$(( totalbill + sum ))
		orders+=("$quant curry -50rs each")
		;;
	5 | beverage)
		echo "you have ordered beverage -40rs"
		read -p "how many do u want : " quant
		sum=$(( quant * 40 ))
		totalbill=$(( totalbill + sum ))
		orders+=("$quant beverage -40rs each")
		;;
	6 | none)
		echo "Are you sure you want to exit? (y/n)"
            read confirm
            case $confirm in
                y|Y)
                    echo "Exiting..."
                    break
                    ;;
                n|N)
                    echo "Returning to the main menu..."
                    ;;
                *)
                    echo "Invalid input, returning to the main menu..."
                    ;;
            esac
            ;;
        *)
            echo "Invalid choice, please try again."
            ;;
esac
done
echo "your total bill is : $totalbill"
echo "you have ordered : "
for order in "${orders[@]}"; do
	echo "$order"
done
		


