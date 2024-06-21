while true; do
    echo "Menu:"
    echo "1. Display the current date and time."
    echo "2. List the files in the current directory."
    echo "3. Show the current user."
    echo "4. Exit."
    read -p "Enter your choice [1-4]: " choice

    case $choice in
        1)
            echo "Current date and time: $(date)"
            ;;
        2)
            echo "Files in the current directory:"
            ls
            ;;
        3)
            echo "Current user: $USER"
            ;;
        4)
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
