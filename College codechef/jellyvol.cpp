#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double Volcal(double volba, double taapmaan) {
    return pow(volba + taapmaan, 3);
}

bool iPT(vector<double>& volbas, double taapmaan, double volTar) {
    double totalVolume = 0;
    for (double volba : volbas) {
        totalVolume += Volcal(volba, taapmaan);
        if (totalVolume >= volTar)
            break;
    }
    return totalVolume >= volTar;
}

double findtaapmaan(vector<double>& volbas, double volTar) {
    double ulta = 0.0, sidha = volTar;
    double taapmaan = 0.0;

    while (sidha - ulta > 1e-7) {
        double beechka = (ulta + sidha) / 2.0;
        if (iPT(volbas, beechka, volTar)) {
            taapmaan = beechka;
            sidha = beechka;
        } else {
            ulta = beechka;
        }
    }

    return taapmaan;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Qope;
    cin >> Qope;

    for (int q = 0; q < Qope; q++) {
        int Nope;
        double Uope;
        cin >> Nope >> Uope;

        vector<double> volbas(Nope);
        for (int i = 0; i < Nope; i++) {
            cin >> volbas[i];
        }

        double taapmaan = findtaapmaan(volbas, Uope);
        cout.precision(2);
        cout << fixed << taapmaan << endl;
    }

    return 0;
}