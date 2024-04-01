
g++ -std=c++11 -Ofast main_experiment.cpp 
for algorithm in 6
do
    for n in 100 1000 10000 100000 1000000 10000000 100000000
    do
        for seed in 0 1 2 3 4
        do
            ./a.out $algorithm $n $seed >> result_fast.txt
        done
    done
done