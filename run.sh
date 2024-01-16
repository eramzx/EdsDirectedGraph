#!/bin/bash
make clean
make
echo " "
echo "---run below---"
./graph adjacency_list.txt
if [ $? -ne 0 ]; then 
	echo "Program Failure."
else
	echo "---end run---"
	echo " "
fi
make clean
