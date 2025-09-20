# 引数がない場合はexit
if [ $# -ne 1 ]; then
  echo "Usage: $0 <testcase>"
  exit 1
fi

make clean > /dev/null
make -j CFLAGS_EXTRA=-DLOCAL_JUDGE > /dev/null

# 引数で指定されたseedを使ってテストケースを実行する
echo "run test $1"

# AtCoder
echo 01_testset/in/$1.txt | ./main > /dev/null

# TopCoder
#echo 01_testset/in/$1.in | ./main > /dev/null
