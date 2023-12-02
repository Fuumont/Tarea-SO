#include <opencv2/opencv.hpp>
#include <iostream>

void convertirEscalaDeGrisesLuminosity(cv::Mat& imagenColor, cv::Mat& imagenEscalaDeGrises) {
    // Obtener el número de filas y columnas de la imagen
    int filas = imagenColor.rows;
    int columnas = imagenColor.cols;

    // Iterar sobre cada píxel y aplicar el método de Luminosity
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // Obtener los valores de los componentes de color
            int B = imagenColor.at<cv::Vec3b>(i, j)[0];
            int G = imagenColor.at<cv::Vec3b>(i, j)[1];
            int R = imagenColor.at<cv::Vec3b>(i, j)[2];

            // Calcular el valor de escala de grises usando el método de Luminosity
            int Y = 0.299 * R + 0.587 * G + 0.114 * B;

            // Asignar el valor de escala de grises al píxel en la nueva imagen
            imagenEscalaDeGrises.at<uchar>(i, j) = Y;
        }
    }
}

int main() {
    // Crear una matriz de imagen a color (puedes cargar tu imagen desde un archivo)
    cv::Mat imagenColor(300, 400, CV_8UC3, cv::Scalar(100, 150, 200));

    // Crear una matriz para la imagen en escala de grises
    cv::Mat imagenEscalaDeGrises(imagenColor.rows, imagenColor.cols, CV_8UC1);

    // Convertir a escala de grises usando el método de Luminosity
    convertirEscalaDeGrisesLuminosity(imagenColor, imagenEscalaDeGrises);

    // Mostrar las imágenes
    cv::imshow("Imagen a Color", imagenColor);
    cv::imshow("Imagen en Escala de Grises", imagenEscalaDeGrises);

    // Esperar que se presione una tecla
    cv::waitKey(0);

    return 0;
}
