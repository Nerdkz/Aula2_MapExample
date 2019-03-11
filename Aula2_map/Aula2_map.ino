#define LED 3
#define POT A0

void setup() {

  Serial.begin(9600); //configurando a taxa de comunicação (Bound Rate)

  pinMode(LED, OUTPUT); // Declarando a porta LED(digital 3) como saída
  pinMode(POT, INPUT);  // Declarando a porta POT(analógica A0) como entrada
}

void loop() {
  float porcentagem; // para calcular a porcentagem em ponto flutuante
  int potenciometro = analogRead(POT); // fazendo a leitura do potenciometro na porta analógica A0

  int valor_lido = map( potenciometro, 0, 1023, 0, 255 );
  valor_lido = map( valor_lido, 0, 255, 0, 100 );
  porcentagem = ( potenciometro * 100.0 ) / 1023.0;
  
  analogWrite(LED, valor_lido);

  Serial.print( "Intensidade do Led: " );
  Serial.print( valor_lido );
  Serial.println( '%' );
  Serial.print( "Intensidade do Led: " );
  Serial.print( porcentagem );
  Serial.println( '%' );
  delay(500);

}
