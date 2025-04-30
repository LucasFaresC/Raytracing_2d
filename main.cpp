#include <stdio.h>
#include <SDL2/SDL.h> // biblioteca que abre a janelinha -> Simple direct media
#include <math.h>

// https://wiki.libsdl.org/SDL2/CategoryAPI -> Link pra documentação do SDL

#define ALTURA 600 // defauta pra int se não declara
#define LARGURA 900  // define e include não precisa do ponto e virgula 
#define COR_BRANCA 0xffffff // codigo hexadecimal do branco
#define COR_PRETA  0x000000// codigo hexadecimal do preto
#define COR_CINZA 0x898989// codigo hexadecimal do cinza
#define NUMERO_DE_RAIOS 100 

const double PI = 3.14159265359;

// g++ main.cpp -o raytracing $(sdl2-config --cflags --libs) -lm COMANDO PARA COMPILAR CERTINHO
// ./nomedoarquivo

struct CIRCULO{ // struct tem que ter ponto e virgula

    double coordenada_x;
    double coordenada_y;
    double raio_do_circulo;
};

struct RAIOS{

    double x_start, y_start;
    double angulo;
    double x_final, y_final;
};

void PreencherCirculo(SDL_Surface* superficie_escolhida, struct CIRCULO circle, Uint32 cor){ // basicamente fazer um circulo usando a distancia da cordenada ao raio
    
    double raio_ao_quadrado = pow(circle.raio_do_circulo, 2);

    for( double x = circle.coordenada_x - circle.raio_do_circulo; x <= circle.coordenada_x + circle.raio_do_circulo; x++){

        for( double y = circle.coordenada_y - circle.raio_do_circulo; y <= circle.coordenada_y + circle.raio_do_circulo; y++){ // loopa cada pixel na tela

            double distancia_ao_quadrado = pow(x - circle.coordenada_x, 2.0) + pow(y - circle.coordenada_y, 2); // pega a distância do pixel em que estamos
            
            if ( distancia_ao_quadrado < raio_ao_quadrado){

                SDL_Rect pixel_da_coordenada = (SDL_Rect) {x, y, 1, 1}; // 1 pixel de altura e 1 pixel de largura
                SDL_FillRect(superficie_escolhida, &pixel_da_coordenada, cor); // não esquece de passar o endereço do pixel no SDL_FillRect
            }

        }        
    }

}

void Gerar_Raios_luz (struct CIRCULO circulo, struct RAIOS raios [NUMERO_DE_RAIOS]){

    for(int i = 0; i < NUMERO_DE_RAIOS; i++){

        double angulo_do_raio = ((double) i / NUMERO_DE_RAIOS) * 2 * PI; // gera os angulos em radiano
        struct RAIOS raio = {circulo.coordenada_x, circulo.coordenada_y, angulo_do_raio};
        raios[i] = raio; // guardar no struct as informações do raio no array;
    }

}

void PreencherRaios(SDL_Surface* superficie_escolhida, struct RAIOS raios[NUMERO_DE_RAIOS], Uint32 cor){

    for(int i = 0; i < NUMERO_DE_RAIOS; i++){
        
        struct RAIOS raio = raios[i];
        
        int final_da_tela = 0; 
        int objeto_a_frente = 0;

        double step = 1;
        double desenho_x = raio.x_start;
        double desenho_y = raio.y_start;

        while( !final_da_tela && !objeto_a_frente){

            desenho_x +=  step * cos(raio.angulo); // cosseno é a projeção da linha em x
            desenho_y +=  step * sin(raio.angulo); // Seno é a projeção da linha em y

            // dando as coordenadas dos pixels na tela

            SDL_Rect pixel_da_coordenada = (SDL_Rect) {desenho_x, desenho_y, 1, 1}; // 1 pixel de altura e 1 pixel de largura
            SDL_FillRect(superficie_escolhida, &pixel_da_coordenada, cor);
            
            if(desenho_x < 0 || desenho_x > LARGURA){
                final_da_tela = 1;
            }
            if(desenho_y < 0 || desenho_y > ALTURA){
                final_da_tela = 1;
            }
        }
    }
}

int main(){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* janela = SDL_CreateWindow( "Raytracing -> Raios de Luz", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , LARGURA, ALTURA, 0 );
    
    SDL_Surface* superficie = SDL_GetWindowSurface(janela);
    
    struct CIRCULO Circulo = {200, 200, 80};
    struct CIRCULO Sombra_Circulo = {650, 300, 140};
    SDL_Rect apagar_retangulo = {0, 0, LARGURA, ALTURA};

    struct RAIOS Raios[NUMERO_DE_RAIOS];
    
    int simulacao_ocorrendo = 1; // true por padrão
    SDL_Event evento;
    
    while(simulacao_ocorrendo){ //simulação estiver acontecendo
        
        while(SDL_PollEvent(&evento)){
            
            if (evento.type == SDL_QUIT){ // Conferindo se o X foi clicado (o do canto superior direito)
                
                simulacao_ocorrendo = 0; // se clicarem para a simulação, pra n ficar rodando no fundo
                
            }
            if(evento.type == SDL_MOUSEMOTION && evento.motion.state != 0){
                
                Circulo.coordenada_x = evento.motion.x;
                Circulo.coordenada_y = evento.motion.y;
                Gerar_Raios_luz(Circulo, Raios);
            }

        }
        
        SDL_FillRect(superficie, &apagar_retangulo, COR_PRETA); 
        PreencherCirculo(superficie, Circulo, COR_BRANCA);

        PreencherCirculo(superficie, Sombra_Circulo, COR_BRANCA); // TODO: debugar essa joça
        PreencherRaios(superficie, Raios, COR_CINZA);

        SDL_UpdateWindowSurface(janela);
        SDL_Delay(10); //argumento é quantos milisegundo de delay -> na prática são os frames
    }

    
}