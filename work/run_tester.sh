# 引数がない場合はexit
if [ $# -ne 1 ]; then
  echo "Usage: $0 <testcase>"
  exit 1
fi

make clean > /dev/null
make -j > /dev/null

# 引数で指定されたseedを使ってテストケースを実行する
echo "run test $1"
java -jar tester.jar -exec "./main" -novis -seed $1 -saveSolOutput # -saveSolError
cp $1.out /mnt/c/test/mm161/tester/
