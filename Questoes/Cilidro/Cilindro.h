typedef struct cilindro Cilindro;

Cilindro* novoCilindro(float raio, float altura);

float buscaAltura(Cilindro *cilindro);

float buscaRaio(Cilindro *cilindro);

float buscaAreaTotal(Cilindro * cilindro);

float buscaVolume(Cilindro * cilindro);

void liberaCilindro(Cilindro *cilindro);