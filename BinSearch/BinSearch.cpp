/*Когда Петя учился в школе, он часто участвовал в олимпиадах по информатике, математике и физике.
Так как он был достаточно способным мальчиком и усердно учился, то на многих из этих олимпиад он получал дипломы.
К окончанию школы у него накопилось n дипломов, причём, как оказалось, все они имели одинаковые размеры: w — в ширину и h — в высоту.
Сейчас Петя учится в одном из лучших российских университетов и живёт в общежитии со своими одногруппниками.
Он решил украсить свою комнату, повесив на одну из стен свои дипломы за школьные олимпиады.
Так как к бетонной стене прикрепить дипломы достаточно трудно, то он решил купить специальную доску из пробкового дерева,
чтобы прикрепить её к стене, а к ней — дипломы. Для того чтобы эта конструкция выглядела более красиво,
Петя хочет, чтобы доска была квадратной и занимала как можно меньше места на стене.
Каждый диплом должен быть размещён строго в прямоугольнике размером w на h.
Дипломы запрещается поворачивать на 90 градусов. Прямоугольники, соответствующие различным дипломам, не должны иметь общих внутренних
точек. Требуется написать программу, которая вычислит минимальный размер стороны доски, которая потребуется Пете для размещения всех
своих дипломов.
Входной файл содержит три целых числа: w, h, n (1≤w,h,n≤10pow9).
*/

/*
When Petya was at school, he often participated in olympiads in computer science, mathematics and physics.
Since he was a fairly capable boy and studied hard, he received diplomas at many of these Olympiads. By the end of the school,
he had accumulated n diplomas, and, as it turned out, they all had the same dimensions: w - wide and h - high.
Now Petya is studying at one of the best Russian universities and lives in a hostel with his classmates.
He decided to decorate his room by hanging his diplomas for school olympiads on one of the walls.
Since it is rather difficult to attach diplomas to a concrete wall, he decided to buy a special cork board,
to attach it to the wall, and diplomas to it. To make this design look more beautiful,
Petya wants the board to be square and take up as little wall space as possible.
Each diploma must be placed strictly in a rectangle measuring w by h.
Diplomas must not be rotated 90 degrees. Rectangles corresponding to different diplomas should not have common internal
points. It is required to write a program that will calculate the minimum size of the side of the board that Petya needs to accommodate all
their diplomas.
The input file contains three integers: w, h, n (1≤w,h,n≤10pow9).
*/

#include <iostream>
using namespace std;

double countSqSize(int w, int h, int n);
double countSqSizeTwo(int w, int h, int n);

int main()
{
    double result; // сюда будем получать результат

    result = countSqSize(2, 3, 25);

    cout << "The answer 1 (Binary search) is: " << result; 

    result = countSqSizeTwo(2, 3, 25);

    cout << "The answer 2 (Find of extremum of func) is: " << result;
}
double countSqSize(int w, int h, int n)
{
    // суммарная площадь:
    int actualSquare = w * h * n;

    double m;
    double r = sqrt((w * n) * (h * n));
    double l = 0;

    while ((r - l) > 0.001)
    {
        m = (r + l) / 2;
        if (actualSquare <= pow(m, 2) && (int(m / w) * int(m / h)) >= n)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return r;
}
double countSqSizeTwo(int w, int h, int n)
{
    // суммарная площадь:
    int actualSquare = w * h * n;

    double r = sqrt((w * n) * (h * n));
    double l = 0;

    int nR = 0;
    double a0 = n * min(w, h);
    double a;

    for (int nC = n; nC > 0; nC--)
    {
        nR = ceil(double(n) / double(nC));
        a = max(nR * h, nC * w);
        if (a < a0)
        {
            a0 = a;
        }
    }
    return a0;
}