check=`python3 check_update_time.py`
# echo $check

if echo "$check" | grep -q "up to date"; then
   echo "combined.cpp is up to date"
else
   echo "combined.cpp is not up to date, run 80_Expander.ipynb"
   exit 0   
fi

echo "compile combined.cpp"
g++ -std=c++17 combined.cpp -o main

echo "run test seed=1"
java -jar tester.jar -exec "./main" -novis -seed 1

echo "copy to /mnt/c/test/mm161/tester/"
cp combined.cpp /mnt/c/test/mm161/submit/HordeChess.cpp
