echo "test {2, 1, 0}:"
./push_swap "2 1 0" | ./checker "2 1 0"
./push_swap "2 1 0" | wc -l

echo "test 5:"
ruby -e "puts (1..5).to_a.shuffle.join(' ')" > test5
./push_swap `cat test5` | ./checker `cat test5`
./push_swap `cat test5` | wc -l
rm test5

echo "test 10:"
ruby -e "puts (1..10).to_a.shuffle.join(' ')" > test10
./push_swap `cat test10` | ./checker `cat test10`
./push_swap `cat test10` | wc -l
rm test10

echo "test 50:"
ruby -e "puts (1..50).to_a.shuffle.join(' ')" > test50
./push_swap `cat test50` | ./checker `cat test50`
./push_swap `cat test50` | wc -l
rm test50

echo "test 100:"
ruby -e "puts (1..100).to_a.shuffle.join(' ')" > test100
./push_swap `cat test100` | ./checker `cat test100`
./push_swap `cat test100` | wc -l
rm test100

echo "test 500:"
ruby -e "puts (1..500).to_a.shuffle.join(' ')" > test500
./push_swap `cat test500` | ./checker `cat test500`
./push_swap `cat test500` | wc -l
rm test500