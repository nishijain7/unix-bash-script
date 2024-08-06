echo "enter the designation code"
read code
echo "enter the designation"
read des
if [[ $code =~ ^[0-9]+$ ]]
then
        echo "valid designation code"
else
        echo "Invalid code, code ,must be numerical"
        exit
fi
if [[ $des =~ ^[A-Za-z]+$ ]]
then
        echo "valid designation code"
else
        echo "invalid"
        exit
fi
echo $code $des >> desg.txt
