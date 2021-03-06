/*
 * Лесенка
 * 
 * (Время: 1 сек. Память: 16 Мб Сложность: 55%)
 * 
 * Лесенкой называется набор кубиков, в котором каждый более верхний слой
 * содержит кубиков меньше, чем предыдущий. Требуется написать программу,
 * вычисляющую число лесенок, которое можно построить из N кубиков.
 * 
 * Входные данные
 * 
 * Во входном файле INPUT.TXT записано натуральное число N (1 <= N <= 100) –
 * количество кубиков в лесенке.
 * 
 * Выходные данные
 * 
 * В выходной файл OUTPUT.TXT необходимо вывести число лесенок, которые можно
 * построить из N кубиков.
 * 
 * РЕШЕНИЕ
 *
 * Переформулируем нашу задачу на язык математики. В каждом следующем слое
 * (считая сверху вниз) кубиков больше, чем в предыдущем, а в сумме их n.
 * Значит, нам требуется представить n в виде суммы возрастающих натуральных
 * слагаемых.
 * 
 *     ---
 *   1 | |
 *     ---------
 *   4 | | | | |
 *     -----------
 *   5 | | | | | |
 *     -----------------
 *   8 | | | | | | | | |
 *     -----------------
 *
 * n=1+4+5+8
 *
 * Пусть в качестве первого слагаемого мы взяли L, тогда нам требуется n-L
 * разбить на слагаемые. Но теперь добавляется дополнительное условие -
 * слагаемые должны быть больше либо равны L+1. Значит, нам достаточно
 * научиться считать число разбиений числа n на слагаемые не меньшие k
 * (обозначим a(n,k)). 
 *
 * Есть два случая: слагаемое k 
 *     - либо входит в разбиение (таких способов a(n-k,k+1)), 
 *     - либо нет (таких способов a(n,k+1)). 
 * 
 * Так как никакое разбиение не подходит одновременно под оба эти случая, то
 *      a(n,k) = a(n-k,k+1) + a(n,k+1). 
 * Заметим, что для единицы существует единственное
 * разбиение: 1 = 1. Значит a(1,0) = a(1,1) = 1, a(1,f) = 0, где f >= 2. a(n,k)
 * удобно вычислять в порядке невозрастания k. При равных k - в произвольном порядке.
 * 
 * Данный алгоритм выполняет порядка N^2 действий.
 */


#include <stdio.h>

int a(int n, int k)
{
    if(n == k) return 1;
    if(n < k) return 0;

    if(n == 3) {
        return 2;
    } else if(n == 1 || n == 2) {
        return 1;
    } else if(n == 0) {
        return 0;
    }

    return a(n-k, k+1) + a(n, k+1);
}

int main(int argc, char **argv)
{
    int n = 0;

    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);

    scanf("%d", &n);
    printf("%d", a(n,1));    

    return 0;
}