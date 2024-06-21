totalsum=0
allitems=""
while true; do
    echo "*****Dhaba Menu******:"
    echo "1. Meals."
    echo "2. Breakfast."
    echo "3. Rotis."
    echo "4. Desserts."
    echo "5. Drinkkkks"
    echo "6.Exit."
    read -p "Enter your choice [1-6]: " choice
case $choice in
	1) 
		echo "in meals you have "
		echo "1.veg"	
		echo "2.nonveg"
		read -p "enter meals choice" mealschoice
		case $mealschoice in
			1)
				echo "1.baingain ka bhadta"
				echo "2.bhindi masala"
				echo "3.paneer butter masala"
				echo "4.shahee panner"
				read -p "enter your veg selection" vegchoice
				case $vegchoice in
					1)
						totalsum=$((totalsum + 100))
						allitems="$allitems,$vegchoice"
						echo "item added is baingan ka bhadta(100rs)"
						;;
					2)
						totalsum=$((totalsum + 120))
						allitems="$allitems,$vegchoice"
						echo "item added is bhindi masala(120rs)"
						;;
					3)
						totalsum=$((totalsum + 150))
						allitems="$allitems,$vegchoice"
						echo "item added is paneer butter masala(150rs)"
						;;
					4)
						totalsum=$((totalsum + 130))
						allitems="$allitems,$vegchoice"
						echo "item added is shahee paneer(130rs)"
						;;
					*)
						echo "invalid number"
						;;
						
				esac
				;;
			2)
				echo "1.mutton labaabdaar"
				echo "2.chicken kormaa" 
				echo "3.prawns churry"
				echo "4.fish pulusu"
				read -p "enter one non veg item" nonvegchoice
				case $nonvegchoice in 
					1)
						totalsum=$((totalsum + 300))
						allitems="$allitems,$nonvegchoice"
						echo "item added is mutton labaabdaar(300rs)"
						;;		
					2)
						totalsum=$((totalsum + 200))
						allitems="$allitems,$nonvegchoice"
						echo "item added is chicken kormaa(200rs)"
						;;		
					3)
						totalsum=$((totalsum + 250))
						allitems="$allitems,$nonvegchoice"
						echo "item added is prawns churry(250rs)"
						;;		
					4)
						totalsum=$((totalsum + 400))
						allitems="$allitems,$nonvegchoice"
						echo "item added is fish pulusu(400rs)"
						;;		
					*)
						echo "invalid item"
						;;
				esac
				;;
		esac
		;;
	2)
		echo "breakfast is ready"		
		;;
	3)
		echo "rotis are ready"
		;;
	4)
		echo "drinks are ready"
		;;
	5)
		echo "desserts are ready"
		;;
	6)
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
    echo
done
if [[ $allitems ]]; then
	echo "ur selected items are"
	echo "${allitems#?}"	
	echo "total bill is Rs. $totalsum"
else
	echo "no items selcted"
fi
		
		
	
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
					
