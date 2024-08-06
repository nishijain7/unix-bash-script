echo "1.whoami 2.who 3.date 4.ls -l 5.exit"
while [ true ]
do
        echo "enter the choice"
        read choice
        case $choice in
                1)whoami;;
                2)who;;
                3)date;;
                4)ls -l;;
                5)exit;;
                *) echo "invalid choice"
        esac
done
