#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

// Función que procesa una parte de la imagen
void processImagePart(Mat& image, int startRow, int endRow) {
    int cols = image.cols;
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            uchar luminosity = static_cast<uchar>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);
            pixel[0] = luminosity;
            pixel[1] = luminosity;
            pixel[2] = luminosity;
            image.at<Vec3b>(i, j) = pixel;
        }
    }
}

// Función principal

int main(int argc, char** argv) {
    // Comprobamos el número de argumentos (3)
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagen_original> <imagen_en_escala_de_grises> <num_hebras>" << endl;
        return -1;
    }
    // Cargamos la imagen
    Mat image = imread(argv[1]);
    // Comprobamos que la imagen se ha cargado correctamente
    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }
    // Mostramos la imagen original
    imshow("Imagen original", image);

    // Procesamos la imagen
    int rows = image.rows;
    // Obtenemos el número de hebras
    int numThreads = stoi(argv[3]);

    // Creamos los threads
    vector<thread> threads;
    int blockSize = rows / numThreads;

    // Iniciamos el cronómetro
    auto start_time = high_resolution_clock::now();

    // Lanzamos los threads
    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * blockSize;
        int endRow = (i == numThreads - 1) ? rows : (i + 1) * blockSize;
        threads.emplace_back(processImagePart, ref(image), startRow, endRow);
    }
    // Esperamos a que terminen los threads
    for (auto& thread : threads) {
        thread.join();
    }
    // Paramos el cronómetro
    auto end_time = high_resolution_clock::now();
    // Calculamos el tiempo transcurrido
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    // Mostramos la imagen en escala de grises
    imshow("Imagen en escala de grises", image);
    // Mostramos el tiempo transcurrido
    cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << endl;
    // Guardamos la imagen en escala de grises
    imwrite(argv[2], image);

    waitKey(0);

    return 0;
}