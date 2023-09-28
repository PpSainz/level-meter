// Configuramos los pines del sensor Trigger y Echo
const int PinTrig = 5;
const int PinEcho = 4;
// Constante velocidad sonido en cm/s
const float VelSon = 34000.0;
float distancia;
int porcentaje;

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);

  // Ponemos el pin Trig en modo salida
  pinMode(PinTrig, OUTPUT);

  // Ponemos el pin Echo en modo entrada
  pinMode(PinEcho, INPUT);
}

void loop() {
  iniciarTrigger();

  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(PinEcho, HIGH);

  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  distancia = tiempo * 0.000001 * VelSon / 2.0;
  porcentaje = (1 - (distancia / 15)) * 100;
  Serial.print(porcentaje);
  Serial.print("%   ");
  Serial.println(distancia);
  delay(500);
}
// Método que inicia la secuencia del Trigger para comenzar a medir
void iniciarTrigger() {
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);

  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);

  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(PinTrig, LOW);
}