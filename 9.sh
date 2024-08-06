while read line
do
        echo $line > tempo
        v=$(cut -d ' ' -f 5 tempo)
        emp=$(cut -d ' ' -f 1 tempo)
echo $v
if echo $v | egrep -q '^[0-9]+$'
then
        if [ $v -gt 60000 ]; then
                da=$((v *25/100))
        else
                da=$((v *30/100))
        fi
        hra=$((v * 10/100))
        gs=$((v+da+hra))
        echo "$line"
        echo "basic salary:$v"
        echo "DA : $da"
        echo "HRA : $hra"
        echo "gross salary : $gs \n"

fi
done < empn.txt
