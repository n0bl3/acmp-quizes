#include <fstream>
#include <vector>

#define INPUT "INPUT.TXT"
#define OUTPUT "OUTPUT.TXT"


/*
 * Домашнее задание
 * (Время: 1 сек. Память: 16 Мб Сложность: 27%)
 * Петя успевает по математике лучше всех в классе, поэтому 
 * учитель задал ему сложное домашнее задание, в котором 
 * нужно в заданном наборе целых чисел найти сумму всех 
 * положительных элементов, затем найти где в заданной 
 * последовательности находятся максимальный и минимальный 
 * элемент и вычислить произведение чисел, расположенных 
 * между ними. Так же известно, что минимальный и максимальный 
 * элемент встречаются в заданном множестве чисел только один 
 * раз. Поскольку задач такого рода учитель дал Пете около ста, 
 * то Петя как сильный программист смог написать программу, 
 * которая по заданному набору чисел самостоятельно находит 
 * решение. А Вам слабо?
 * 
 * Входные данные
 * 
 * В первой строке входного файла INPUT.TXT записано единственное 
 * число N – количество элементов массива. Вторая строка содержит 
 * N целых чисел, представляющих заданный массив. Все элементы 
 * массива разделены пробелом. Каждое из чисел во входном файле 
 * не превышает 102 по абсолютной величине.
 * 
 * Выходные данные
 * 
 * В единственную строку выходного файла OUTPUT.TXT нужно вывести 
 * два числа, разделенных пробелом: сумму положительных элементов 
 * и произведение чисел, расположенных между минимальным и максимальным 
 * элементами. Значения суммы и произведения не превышают по модулю 3*104.
 * */

void solve(const std::vector<int> &ar) 
{
    int max_val = ar[0];
    int max_pos = 0;

    int min_val = ar[0];
    int min_pos = 0;

    int sum = 0;

    for(int i = 0; i < ar.size(); i++) {
        if(ar[i] < min_val) {
            min_val = ar[i];
            min_pos = i;
        }

        if(ar[i] > max_val) {
            max_val = ar[i];
            max_pos = i;
        }

        if(ar[i] > 0) {
            sum += ar[i];
        }
    }

    int mul = 1;
    for(int i = std::min(min_pos, max_pos)+1; i < std::max(min_pos,max_pos); i++) {
        mul *= ar[i];
    }

    std::ofstream out(OUTPUT);

    if(out.is_open()) {
        out << sum << " " << mul;
        out.close();
    }
}

int main(int argc, char **argv)
{
    std::ifstream in(INPUT);

    if(in.is_open()) {
        int N = 0;
        std::vector<int> ar;

        in >> N;

        ar.resize(N, 0);
        for(int i = 0; i < N; i++) {
            in >> ar.at(i); 
        }

        in.close();

        solve(ar);
    }

    return 0;
}