#include <iostream>
#include <string>
#include <string.h>

/*
What We Learn

1. Determinan - selisih antara perkalian elemen-elemen pada diagonal utama dengan perkalian elemen-elemen pada diagonal sekunder
2. Kofaktor - Kofaktor suatu elemen matriks adalah determinan matriks yang diperoleh dengan mengeliminasi baris dan kolom dalam matriks yang memuat elemen tersebut,
3. Adjoin - transpose (ranspose adalah mengubah urutan, posisi, atau sekuens), dari suatu matriks yang elemen-elemennya merupakan kofaktor dari elemen-elemen matriks tersebut.
4. Invers - Invers matriks adalah sebuah kebalikan (invers) dari kedua matriks.
*/

int main()
{
    // => Matrix Code
    float setMatrix[3][3] = {
        {4, 2, 8},
        {2, 1, 5},
        {3, 2, 4}};

    // => getMatrixA Supaya Data Matrix tidak di ubah secara langsung
    float getMatrix[3][3]; // deklarasi tujuan matrix A

    memcpy(getMatrix, setMatrix, sizeof(setMatrix)); // mengcopy setMatrix ke getMatrix

    // => Menghitung Determinan

    /*
        Menghitung determinan adalah syarat wajib untuk memiliki invers
    */
    float determinant =
        getMatrix[0][0] * ((getMatrix[1][1] * getMatrix[2][2]) - (getMatrix[1][2] * getMatrix[2][1])) - // 4 * ((1 * 4) - (5 * 2)) = -24
        getMatrix[0][1] * ((getMatrix[1][0] * getMatrix[2][2]) - (getMatrix[1][2] * getMatrix[2][0])) + // 2 * ((2 * 4) - (5 * 3)) = -14
        getMatrix[0][2] * ((getMatrix[1][0] * getMatrix[2][1]) - (getMatrix[1][1] * getMatrix[2][0]));  // 8 * ((2 * 2) - (1 * 3)) = 8
    /*
        -24 - (-14) + 8 = -2
    */

    if (determinant == 0) // jika determinasi matrix = 0 maka tidak bisa invers
    {
        std::cout << "Matrix Tidak Bisa Invers Karena Determinan = 0" << std::endl;
        return 0;
    }

    // => Menghitung Kofaktornya
    float kofaktor[3][3]; // buat variable sebagai wadah matriks 3 x 3

    kofaktor[0][0] = (getMatrix[1][1] * getMatrix[2][2] - getMatrix[1][2] * getMatrix[2][1]);  // (1 * 4 - 5 * 2) = 4 - 10 = -6
    kofaktor[0][1] = -(getMatrix[1][0] * getMatrix[2][2] - getMatrix[1][2] * getMatrix[2][0]); // -(2 * 4 - 5 * 3) = -(8 - 15) = -(−7) = 7
    kofaktor[0][2] = (getMatrix[1][0] * getMatrix[2][1] - getMatrix[1][1] * getMatrix[2][0]);  // (2 * 2 - 1 * 3) = 4 - 3 = 1

    kofaktor[1][0] = -(getMatrix[0][1] * getMatrix[2][2] - getMatrix[0][2] * getMatrix[2][1]); // -(2 * 4 - 8 * 2) = -(8 - 16) = -(−8) = 8
    kofaktor[1][1] = (getMatrix[0][0] * getMatrix[2][2] - getMatrix[0][2] * getMatrix[2][0]);  // (4 * 4 - 8 * 3) = 16 - 24 = -8
    kofaktor[1][2] = -(getMatrix[0][0] * getMatrix[2][1] - getMatrix[0][1] * getMatrix[2][0]); // -(4 * 2 - 2 * 3) = -(8 - 6) = -(2) = -2

    kofaktor[2][0] = (getMatrix[0][1] * getMatrix[1][2] - getMatrix[0][2] * getMatrix[1][1]);  // (2 * 5 - 8 * 1) = 10 - 8 = 2
    kofaktor[2][1] = -(getMatrix[0][0] * getMatrix[1][2] - getMatrix[0][2] * getMatrix[1][0]); // -(4 * 5 - 8 * 2) = -(20 - 16) = -(4) = -4
    kofaktor[2][2] = (getMatrix[0][0] * getMatrix[1][1] - getMatrix[0][1] * getMatrix[1][0]);  // (4 * 1 - 2 * 2) = 4 - 4 = 0

    float setAdjoin[3][3] = {
        {kofaktor[0][0], kofaktor[1][0], kofaktor[2][0]},  // {-6, 8, 2}
        {kofaktor[0][1], kofaktor[1][1], kofaktor[2][1]},  // {7, -8, -4}
        {kofaktor[0][2], kofaktor[1][2], kofaktor[2][2]}}; // {1, -2, 0}

    float getAdjoin[3][3];

    memcpy(getAdjoin, setAdjoin, sizeof(setAdjoin));

    // Hitung Invers
    float setInvers[3][3] = {
        {getAdjoin[0][0] / -2, getAdjoin[0][1] / -2, getAdjoin[0][2] / -2},  // {3, -3.5, -0.5}
        {getAdjoin[1][0] / -2, getAdjoin[1][1] / -2, getAdjoin[1][2] / -2},  // {-4, 4, 1}
        {getAdjoin[2][0] / -2, getAdjoin[2][1] / -2, getAdjoin[2][2] / -2}}; // {-1, 2, 0}

    float getInvers[3][3];

    memcpy(getInvers, setInvers, sizeof(setInvers));

    // Print Invers
    std::cout << "===== MATRIKS INVERS =====" << std::endl;
    std::cout << getInvers[0][0] << " " << getInvers[0][1] << " " << getInvers[0][2] << std::endl;
    std::cout << getInvers[1][0] << " " << getInvers[1][1] << " " << getInvers[1][2] << std::endl;
    std::cout << getInvers[2][0] << " " << getInvers[2][1] << " " << getInvers[2][2] << std::endl;

    return 0;
}