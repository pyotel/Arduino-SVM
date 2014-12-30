#include <avr/pgmspace.h>
#define VEC_DIM 9

#define SVM_TYPE c_svc
#define KERNEL_TYPE linear
#define NR_CLASS 5
#define TOTAL_SV 27
const  PROGMEM float rho[] = {1.06877, 0.342367, 0.271674, 0.213677, 0.266449, 0.0492231, -0.0669559, -0.0928679, -0.121012, -0.0884864};
const int label[] = {0, 1, 2, 3, 4};
const int nr_sv[] = {4, 5, 5, 6, 7};
 const PROGMEM float yalpha1[4 * (NR_CLASS-1)] = {1, 0.4595338242000765, 0.09042252171083272, 0.1409934987286733, 0.4038454100020114, 0, 0, 0, 0.2984824651311233, 0, 0, 0.004575003591770739, 0.3953786137021565, 0, 0, 0}; 

 const PROGMEM float sv1[4 * VEC_DIM] = {0.114754, 0.583333, 0.676768, 0.676768, 0.547826, 0.622222, 0.655172, 0.666667, 0.52381, 0.0983607, 0.791667, 0.79798, 0.717172, 0.6, 0.555556, 0.741379, 0.716667, 0.790476, 0.0983607, 0.861111, 0.959596, 0.818182, 0.617391, 0.488889, 0.689655, 0.65, 0.67619, 0.0655738, 0.819444, 0.818182, 0.272727, 0.6, 0.6, 0.568966, 0.75, 0.942857}; 

 const PROGMEM float yalpha2[5 * (NR_CLASS-1)] = {0.1409934987286733, -1, -0, -0, -0, 0, 0.155522919475877, 0.495803341431051, 0.4103022248912957, 0, 0.004575003591770739, 0, 0.2535540469784882, 0.3513327743977417, 0, 0, 0.006975830730241244, 0, 0.6426082815307304, 0.09507369987874643}; 

 const PROGMEM float sv2[5 * VEC_DIM] = {0.0655738, 0.819444, 0.818182, 0.272727, 0.6, 0.6, 0.568966, 0.75, 0.942857, 0.213115, 0.194444, 0.292929, 0.515152, 0.86087, 0.688889, 0.327586, 0.55, 0.333333, 0, -0.263889, 0.636364, 0.636364, 0.756522, 0.488889, 0.310345, -0.45, 0.580952, 0.131148, 0.0555556, 0.0707071, 0.353535, 0.86087, 0.377778, 0.327586, -0.45, 0.657143, 0.262295, 0.472222, -0.232323, 0.414141, 0.86087, 0.444444, 0.293103, -0.566667, 0.809524}; 

 const PROGMEM float yalpha3[5 * (NR_CLASS-1)] = {-0, -0.6909498446395825, -0.2015992786081303, -0.202246131393881, -0, 0, 0, -0.2363907409795529, -0.8252377448186706, -0, 0, 0, 0, 0.6731601105465157, 0.2091048705441852, 0.09507369987874643, 0, 0, 0.1250702524419036, 0}; 

 const PROGMEM float sv3[5 * VEC_DIM] = {0.262295, 0.472222, -0.232323, 0.414141, 0.86087, 0.444444, 0.293103, -0.566667, 0.809524, 0.180328, 0.138889, 0.757576, 0.818182, 0.791304, 0.488889, 0.362069, -0.45, 0.638095, 0.0327869, -0.555556, -0.292929, 0.555556, 0.617391, 0.466667, -0.551724, -0.216667, -0.180952, -0.0327869, -0.569444, 0.0707071, 0.272727, 0.478261, 0.355556, -0.603448, -0.35, -0.142857, -0.114754, -0.0277778, -0.79798, 0.373737, 0.513043, -0.266667, -0.517241, -0.883333, -0.828571}; 

 const PROGMEM float yalpha4[6 * (NR_CLASS-1)] = {-0, -0, -0, -0, -0, -0.08905226987839665, -0, -0, -0, -0, -0, -0, 0.2091048705441852, 0, 0.4839038273863283, -0, -0, -0, 0, 0.6666791314585784, 0, 0.3402761989129244, 0.008464052645961149, 0}; 

 const PROGMEM float sv4[6 * VEC_DIM] = {-0.114754, -0.0277778, -0.79798, 0.373737, 0.513043, -0.266667, -0.517241, -0.883333, -0.828571, 0.147541, -0.541667, -0.717172, 0.313131, 0.46087, 0.111111, -0.482759, -0.583333, -0.638095, -0.0983607, -0.847222, -0.89899, -0.414141, 0.391304, 0.111111, -0.931034, -0.833333, -0.390476, -0.836066, -0.625, -0.272727, -0.131313, -0.00869565, -0.955556, 0, -0.2, -0.447619, -0.459016, -0.513889, -0.292929, -0.79798, -1, -0.777778, -0.448276, -0.233333, 0.0666667, -0.819672, -0.263889, -0.212121, 0.111111, -0.513043, -0.355556, -0.689655, 0.116667, -0.295238}; 

 const PROGMEM float yalpha5[7 * (NR_CLASS-1)] = {-0.08905226987839665, -0, -0, -0.2140051988444974, -0, -0.1425526046921795, -0, -0, -0, -0, -0.60488682137623, -0, -0.6805762878534299, -0.06408152428628813, -0, -0.3086904450467835, -0.5416113500373424, -0.5158670133929035, -0.4099632938523962, -0, -0, 0, 0, 0.1701505855375848, 0.162213004180823, -0.008755626905906141, -0, -0.4191847453003477}; 

 const PROGMEM float sv5[7 * VEC_DIM] = {-0.819672, -0.263889, -0.212121, 0.111111, -0.513043, -0.355556, -0.689655, 0.116667, -0.295238, -1, -1, -0.79798, -0.454545, -0.321739, -0.622222, -0.62069, -0.383333, -0.447619, -0.459016, -0.222222, 0.252525, -0.313131, -0.2, -0.422222, -0.896552, -0.65, -1, -0.557377, -0.402778, 0.373737, -0.353535, 0.0608696, -0.444444, -0.551724, -0.5, 0.466667, 0.508197, -0.583333, -0.515152, -0.636364, 0.408696, -0.0888889, 0.793103, -0.5, -0.67619, 0.57377, 0.319444, -0.252525, -0.515152, 0.373913, 0.422222, 0.603448, -0.666667, -0.447619, 0.278689, 0.180556, 0.030303, -0.373737, 0.356522, -0.577778, 0.862069, -0.7, -0.619048}; 

const int scalePar[] = {-1,1};
const int low[] = {517,544,543,546,733,576,552,526,552};
const int high[] = {639,688,642,645,848,666,668,646,657};  
int result[NR_CLASS]={0};

 float const* const supportVectors[NR_CLASS] PROGMEM = {
sv1, sv2, sv3, sv4, sv5, };
 const float* const valuesForSupport[NR_CLASS] PROGMEM = {
yalpha1, yalpha2, yalpha3, yalpha4, yalpha5, };

void scale(const int* sensor, float* scaledSensor){
  for(int p=0; p<VEC_DIM;p++){
    scaledSensor[p] = (float)scalePar[0] +((float)scalePar[1] -((float)scalePar[0]))*((float)sensor[p]-(float)low[p])/((float)high[p]-(float)low[p]);
  }
}

inline void svm_predict(int sensor[]){
  int recognizedClass = 1;
  float scaledSensor[VEC_DIM];
  scale(sensor,scaledSensor);
  int rhoCounter = 0;


  for(int i=0; i<NR_CLASS; i++){
    for(int j=i+1; j<NR_CLASS; j++){
      float accumulator = 0;


      float* sv_class1 = (float*) pgm_read_word(supportVectors + i);
      float* sv_class2 = (float*) pgm_read_word(supportVectors + j);
      float* coeffs1   = (float*) pgm_read_word(valuesForSupport + i) + nr_sv[i] * (j-1);
     float* coeffs2   = (float*) pgm_read_word(valuesForSupport + j) + nr_sv[j] * i;


      accumulator += svm_evaluate(nr_sv[i], coeffs1, sv_class1, scaledSensor);
      accumulator += svm_evaluate(nr_sv[j], coeffs2, sv_class2, scaledSensor);


      float rhoNr = pgm_read_float(rho + rhoCounter);
      accumulator -= rhoNr;


      if (accumulator > 0) {
        result[i]++;
      } else {
        result[j]++;
      }
      rhoCounter++;
    }
  }


  int temp = 0;
  for(int t = 0; t < NR_CLASS; t++){
    if(result[temp] <= result[t]){
      recognizedClass = t;
      temp = t;
    }
  }


  Serial.println(recognizedClass, DEC);
  delay(500);
  for(int q = 0; q < NR_CLASS; q++){
    result[q]=0;
  }
}