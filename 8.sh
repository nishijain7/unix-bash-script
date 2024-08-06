#!/bin/sh
y=1
while [ $y -eq 1 ]
do
        echo "enter item code"
        read itemcode
        echo "enter item"
        read item
        echo $itemcode $item >> item.txt
       echo "enter 1 to contine or 0 to discontinue"
       read y
done
cat item.txt
