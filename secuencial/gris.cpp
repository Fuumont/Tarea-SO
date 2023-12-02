#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Lee la imagen a color
    Mat image = imread("peak.jpeg");

    // Muestra la imagen original
    imshow("Imagen original", image);

    // Obtiene las dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;

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
    // Muestra la imagen en escala de grises
    imshow("Imagen en escala de grises", image);
    // Guarda la imagen en escala de grises
    imwrite("imagengris.jpg", image);
    
    waitKey(0);

    return 0;
}
