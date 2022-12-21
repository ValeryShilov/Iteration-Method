#include <iostream>
#include <cmath>
using namespace std;
double f(double n) {
    return pow(n, 3) + 47 * n - 15; //уравнение
}
double fh(double n) {
    return (15 - pow(n, 3)) / 47; //преобразованное уравнение
}
double fp(double n) {
    return 3 * pow(n, 2) + 47;   //производная
}
int main() {
    setlocale(LC_ALL, "RUS");
    double r = 1, a, b, x0, e = pow(10,-6);
    bool flag = 1;
    int cnt = 0;
    
    cin >> a >> b >> x0;
    if (f(a) * f(b) <= 0) {
        do {
            double x1 = fh(x0);
            r = abs(x1 - x0);
            x0 = x1;
            if (abs(fh(x1)) >= 1) {
                flag = 0;
            }
            cnt++;
        } while (r > e && flag);
        if (flag == 0) cout << "Промежуток не удовлетворяет условиям метода" << endl;
        else {
            cout << "x = " << x0 << endl;
            cout << "Количество итераций = " << cnt << endl;
        }
    }
    else cout << "На заданном отрезке корней нет2" << endl;
    return 0;
}