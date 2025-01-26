#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Data nilai dari tabel
    vector<int> nilai = {92, 65, 74, 80, 80, 70, 78};
    int n = nilai.size();

    // Menghitung Mean
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nilai[i];
    }
    double mean = sum / n;

    // Menghitung Median
    sort(nilai.begin(), nilai.end()); // Mengurutkan data
    double median;
    if (n % 2 == 0) {
        median = (nilai[n / 2 - 1] + nilai[n / 2]) / 2.0;
    } else {
        median = nilai[n / 2];
    }

    // Menghitung Standar Deviasi
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow(nilai[i] - mean, 2);
    }
    variance /= n; // Variansi
    double std_dev = sqrt(variance); // Standar Deviasi

    // Menampilkan hasil
    cout << "Mean (Rata-rata): " << mean << endl;
    cout << "Median (Nilai Tengah): " << median << endl;
    cout << "Standar Deviasi: " << std_dev << endl;

    return 0;
}