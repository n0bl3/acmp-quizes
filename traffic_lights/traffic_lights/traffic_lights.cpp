#include <fstream>
#include <map>

/*
 *  Светофорчики
 * (Время: 1 сек. Память: 16 Мб Сложность: 25%)
 * В подземелье M тоннелей и N перекрестков, каждый тоннель 
 * соединяет какие-то два перекрестка. Мышиный король решил 
 * поставить по светофору в каждом тоннеле перед каждым перекрестком. 
 * Напишите программу, которая посчитает, сколько светофоров должно 
 * быть установлено на каждом из перекрестков. Перекрестки 
 * пронумерованы числами от 1 до N.
 * 
 * Входные данные
 * 
 * Во входном файле INPUT.TXT записано два числа N и M 
 * (0 < N <= 100, 0 <= M <= N*(N-1)/2). В следующих M строках 
 * записаны по два числа i и j (1 <= i,j <= N), которые означают, 
 * что перекрестки i и j соединены тоннелем. Можно считать, что 
 * любые два перекрестка соединены не более, чем одним тоннелем. 
 * Нет тоннелей от перекрестка i до него самого.
 * 
 * Выходные данные
 * 
 * В выходной файл OUTPUT.TXT вывести N чисел: k-ое число означает 
 * количество светофоров на k-ом перекрестке.
 * */

#define INPUT "INPUT.TXT"
#define OUTPUT "OUTPUT.TXT"

int main(int argc, char **argv)
{
    std::ifstream in(INPUT);

    if(in.is_open()) {
        int N = 0;
        int M = 0;

        std::map<int, int> num_lights;

        in >> N >> M;

        for(int i = 0; i < M; i++) {
            int val1 = 0;
            int val2 = 0;

            in >> val1 >> val2;

            num_lights[val1]++;
            num_lights[val2]++;
        }
        in.close();

        std::ofstream out (OUTPUT);

        if(out.is_open()) {

            for(std::map<int,int>::const_iterator i = num_lights.begin();
                i != num_lights.end(); ++i) {

                    out << (*i).second << " ";

            }

            if(num_lights.size() == 0) {
                out << 0;
            }

            out.close();
        }
    }

    return 0;
}