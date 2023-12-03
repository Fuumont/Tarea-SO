#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono; 

int main(int argc, char** argv) {
    // Lee la imagen a color
    Mat image = imread(argv[1]);

    // Muestra la imagen original
    imshow("Imagen original", image);

    // Obtiene las dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;
        // Iniciamos el cronómetro
    auto start_time = high_resolution_clock::now();

    // Itera sobre cada píxel de la imagen y aplica el método de luminosidad
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Obtiene los valores BGR del píxel actual
            Vec3b pixel = image.at<Vec3b>(i, j);
            
            // Calcula el valor de luminosidad utilizando el método de luminosidad
            uchar luminosity = static_cast<uchar>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);

            // Asigna el nuevo valor de luminosidad a cada canal (escala de grises)
            pixel[0] = luminosity;
            pixel[1] = luminosity;
            pixel[2] = luminosity;

            // Asigna los nuevos valores al píxel en la imagen
            image.at<Vec3b>(i, j) = pixel;
        }
    }
    // Paramos el cronómetro
    auto end_time = high_resolution_clock::now();
    // Calculamos el tiempo transcurrido
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    // Mostramos el tiempo transcurrido
    cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << endl;
    // Muestra la imagen en escala de grises
    imshow("Imagen en escala de grises", image);
    // Guarda la imagen en escala de grises
    imwrite(argv[2], image);
    
    waitKey(0);

    return 0;
}
