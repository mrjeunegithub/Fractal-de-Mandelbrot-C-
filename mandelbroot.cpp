#include<iostream>

int main() {
    unsigned int max_iteration = 50;
    const float x_min  = -2.0f;
    const float y_min = -1.25f ; 
    const float x_max = 0.5f ;
    const float y_max = 1.25f ; 
    const int largeur = 100;
    const int hauteur = 50;

    for (int y = 0; y < hauteur; y++){
        for (int x= 0; x < largeur;x++){

            float cx = (x * (x_max - x_min) / largeur +x_min);
            float cy = (y * (y_min - y_max) /hauteur + y_max); 

            float xn = 0.0f;
            float yn = 0.0f;
            int n = 0;

            while ((xn * xn + yn*yn) < 4.0f &&  n < max_iteration) {
                float tmp_x = xn;
                float tmp_y = yn;
                xn = tmp_x * tmp_x - tmp_y * tmp_y + cx;
                yn = 2 * tmp_x *tmp_y +cy;
                n = n+1;
            }    

            if (n == max_iteration) {
                std::cout << ".";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl; 

        
    }
    return 0;
}