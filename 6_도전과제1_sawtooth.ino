unsigned int period = 1000; // in ms
unsigned int samplingPeriod = 5; // print something every 5ms

double minValue = -1;
double maxValue = 1;

// precalculate some values
double halfPeriod = period / 2.0;
double a1 = (maxValue - minValue) / halfPeriod;
double b1 = 2.0 * maxValue - minValue;

// time management
unsigned long currentTime, relativeTime, previousTime, lastFullPeriod;


void setup() {
  Serial.begin(9600);
  while (!Serial);
  lastFullPeriod = 0;
}

void loop() {
  double y;
  // check if it is time to display a new value
  if (((currentTime = millis()) - previousTime) >= samplingPeriod) {
    if ((relativeTime = currentTime - lastFullPeriod) >= period) {
      relativeTime = 0 ;
      lastFullPeriod = currentTime;
    }

    if (relativeTime < halfPeriod) {
      y = a1 * (double) relativeTime  + minValue;
    } else {
      y = -a1 * (double) relativeTime + b1 ;
    }

    //Serial.print(currentTime);
    Serial.print("\t");
    Serial.println(y, 6);

    previousTime = millis();
  }
}
