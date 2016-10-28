//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: hoffmannFollower.cpp
//
// Code generated for Simulink model 'hoffmannFollower'.
//
// Model version                  : 1.61
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Tue May 24 16:45:59 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "hoffmannFollower.h"
#include "hoffmannFollower_private.h"
#define hoffmannFollowe_MessageQueueLen (1)

// Block signals (auto storage)
B_hoffmannFollower_T hoffmannFollower_B;

// Block states (auto storage)
DW_hoffmannFollower_T hoffmannFollower_DW;

// Real-time model
RT_MODEL_hoffmannFollower_T hoffmannFollower_M_;
RT_MODEL_hoffmannFollower_T *const hoffmannFollower_M = &hoffmannFollower_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void hoffmannFollower_step(void)
{
  static const creal_T b[301] = { { -1.0, -1.2246467991473532E-16 }, { -
      0.9997806834748455, -0.02094241988335711 }, { -0.99912283009885838,
      -0.04187565372919981 }, { -0.99802672842827156, -0.062790519529313582 }, {
      -0.99649285924950437, -0.083677843332315732 }, { -0.99452189536827329,
      -0.10452846326765373 }, { -0.99211470131447776, -0.12533323356430454 }, {
      -0.98927233296298833, -0.14608302856241151 }, { -0.985996037070505,
      -0.16676874671610217 }, { -0.98228725072868872, -0.18738131458572457 }, {
      -0.97814760073380569, -0.20791169081775931 }, { -0.97357890287316029,
      -0.22835087011065575 }, { -0.96858316112863108, -0.24868988716485482 }, {
      -0.9631625667976581, -0.26891982061526576 }, { -0.95731949753206724,
      -0.28903179694447168 }, { -0.95105651629515353, -0.30901699437494751 }, {
      -0.944376370237481, -0.3288666467385834 }, { -0.93728198949189145,
      -0.34857204732181535 }, { -0.92977648588825135, -0.36812455268467814 }, {
      -0.92186315158850041, -0.38751558645210316 }, { -0.91354545764260076,
      -0.40673664307580043 }, { -0.90482705246601935, -0.42577929156507288 }, {
      -0.8957117602394129, -0.44463517918492734 }, { -0.88620357923121473,
      -0.46329603511986162 }, { -0.87630668004386358, -0.48175367410171521 }, {
      -0.86602540378443871, -0.49999999999999994 }, { -0.8553642601605066,
      -0.51802700937313018 }, { -0.84432792550201508, -0.53582679497899666 }, {
      -0.83292124071009943, -0.55339154924334411 }, { -0.821149209133704,
      -0.57071356768443171 }, { -0.80901699437494734, -0.58778525229247325 }, {
      -0.79652991802419615, -0.60459911486237494 }, { -0.78369345732583973,
      -0.62114778027831052 }, { -0.77051324277578914, -0.63742398974868986 }, {
      -0.75699505565175629, -0.6534206039901056 }, { -0.74314482547739436,
      -0.669130606358858 }, { -0.72896862742141133, -0.68454710592868884 }, { -
      0.71447267963280348, -0.69966334051336532 }, { -0.69966334051336543,
      -0.71447267963280336 }, { -0.68454710592868873, -0.72896862742141144 }, {
      -0.66913060635885824, -0.74314482547739424 }, { -0.65342060399010549,
      -0.7569950556517564 }, { -0.63742398974868975, -0.77051324277578925 }, { -
      0.6211477802783103, -0.78369345732583984 }, { -0.60459911486237483,
      -0.79652991802419637 }, { -0.587785252292473, -0.80901699437494745 }, { -
      0.5707135676844316, -0.821149209133704 }, { -0.553391549243344,
      -0.83292124071009954 }, { -0.53582679497899688, -0.844327925502015 }, { -
      0.51802700937313007, -0.85536426016050671 }, { -0.50000000000000022,
      -0.8660254037844386 }, { -0.48175367410171505, -0.87630668004386369 }, { -
      0.46329603511986189, -0.88620357923121462 }, { -0.44463517918492723,
      -0.895711760239413 }, { -0.42577929156507272, -0.90482705246601947 }, { -
      0.40673664307580026, -0.91354545764260087 }, { -0.387515586452103,
      -0.92186315158850052 }, { -0.368124552684678, -0.92977648588825146 }, { -
      0.34857204732181518, -0.93728198949189157 }, { -0.32886664673858318,
      -0.94437637023748111 }, { -0.30901699437494734, -0.95105651629515364 }, {
      -0.28903179694447173, -0.95731949753206724 }, { -0.26891982061526581,
      -0.9631625667976581 }, { -0.24868988716485485, -0.96858316112863108 }, { -
      0.22835087011065577, -0.97357890287316029 }, { -0.20791169081775934,
      -0.97814760073380569 }, { -0.1873813145857246, -0.98228725072868872 }, { -
      0.16676874671610223, -0.985996037070505 }, { -0.14608302856241176,
      -0.98927233296298833 }, { -0.12533323356430437, -0.99211470131447776 }, {
      -0.10452846326765355, -0.99452189536827329 }, { -0.083677843332315552,
      -0.99649285924950437 }, { -0.0627905195293134, -0.99802672842827156 }, { -
      0.041875653729199623, -0.99912283009885838 }, { -0.020942419883356926,
      -0.9997806834748455 }, { -1.6081226496766366E-16, -1.0 }, {
      0.020942419883356829, -0.9997806834748455 }, { 0.041875653729199526,
      -0.99912283009885838 }, { 0.0627905195293133, -0.99802672842827156 }, {
      0.083677843332315441, -0.99649285924950437 }, { 0.10452846326765346,
      -0.99452189536827329 }, { 0.12533323356430426, -0.99211470131447788 }, {
      0.14608302856241143, -0.98927233296298833 }, { 0.16676874671610212,
      -0.985996037070505 }, { 0.18738131458572452, -0.98228725072868872 }, {
      0.20791169081775923, -0.97814760073380569 }, { 0.22835087011065569,
      -0.97357890287316029 }, { 0.24868988716485474, -0.96858316112863108 }, {
      0.2689198206152657, -0.96316256679765822 }, { 0.2890317969444714,
      -0.95731949753206735 }, { 0.30901699437494728, -0.95105651629515364 }, {
      0.32886664673858312, -0.94437637023748111 }, { 0.34857204732181513,
      -0.93728198949189157 }, { 0.36812455268467786, -0.92977648588825146 }, {
      0.38751558645210293, -0.92186315158850052 }, { 0.40673664307580021,
      -0.91354545764260087 }, { 0.42577929156507244, -0.90482705246601958 }, {
      0.44463517918492734, -0.8957117602394129 }, { 0.46329603511986162,
      -0.88620357923121473 }, { 0.48175367410171516, -0.87630668004386369 }, {
      0.49999999999999989, -0.86602540378443871 }, { 0.51802700937313018,
      -0.85536426016050671 }, { 0.53582679497899655, -0.84432792550201508 }, {
      0.55339154924334411, -0.83292124071009954 }, { 0.57071356768443171,
      -0.821149209133704 }, { 0.58778525229247314, -0.80901699437494745 }, {
      0.60459911486237494, -0.79652991802419626 }, { 0.62114778027831008,
      -0.78369345732584006 }, { 0.63742398974868941, -0.77051324277578948 }, {
      0.65342060399010526, -0.75699505565175662 }, { 0.669130606358858,
      -0.74314482547739436 }, { 0.6845471059286885, -0.72896862742141177 }, {
      0.69966334051336532, -0.71447267963280359 }, { 0.71447267963280325,
      -0.69966334051336554 }, { 0.72896862742141144, -0.68454710592868873 }, {
      0.74314482547739413, -0.66913060635885824 }, { 0.7569950556517564,
      -0.65342060399010549 }, { 0.77051324277578914, -0.63742398974868975 }, {
      0.78369345732583984, -0.62114778027831041 }, { 0.79652991802419626,
      -0.60459911486237483 }, { 0.80901699437494745, -0.58778525229247314 }, {
      0.82114920913370382, -0.570713567684432 }, { 0.83292124071009932,
      -0.55339154924334433 }, { 0.84432792550201485, -0.53582679497899688 }, {
      0.85536426016050648, -0.51802700937313051 }, { 0.86602540378443849,
      -0.50000000000000022 }, { 0.87630668004386347, -0.48175367410171549 }, {
      0.88620357923121462, -0.46329603511986195 }, { 0.89571176023941279,
      -0.44463517918492768 }, { 0.90482705246601947, -0.42577929156507277 }, {
      0.91354545764260087, -0.40673664307580032 }, { 0.92186315158850052,
      -0.38751558645210304 }, { 0.92977648588825135, -0.36812455268467803 }, {
      0.93728198949189145, -0.34857204732181524 }, { 0.944376370237481,
      -0.32886664673858323 }, { 0.95105651629515353, -0.3090169943749474 }, {
      0.95731949753206713, -0.28903179694447195 }, { 0.9631625667976581,
      -0.26891982061526609 }, { 0.96858316112863108, -0.24868988716485513 }, {
      0.97357890287316018, -0.22835087011065605 }, { 0.97814760073380558,
      -0.20791169081775962 }, { 0.98228725072868861, -0.18738131458572488 }, {
      0.98599603707050487, -0.16676874671610251 }, { 0.98927233296298833,
      -0.14608302856241182 }, { 0.99211470131447776, -0.12533323356430442 }, {
      0.99452189536827329, -0.10452846326765361 }, { 0.99649285924950437,
      -0.083677843332315607 }, { 0.99802672842827156, -0.062790519529313457 }, {
      0.99912283009885838, -0.041875653729199686 }, { 0.9997806834748455,
      -0.020942419883356989 }, { 1.0, -4.4408920985006262E-16 }, {
      0.9997806834748455, 0.020942419883356544 }, { 0.99912283009885838,
      0.041875653729199241 }, { 0.99802672842827156, 0.062790519529313013 }, {
      0.99649285924950437, 0.083677843332315163 }, { 0.9945218953682734,
      0.10452846326765318 }, { 0.99211470131447788, 0.12533323356430398 }, {
      0.98927233296298833, 0.14608302856241137 }, { 0.985996037070505,
      0.16676874671610206 }, { 0.98228725072868872, 0.18738131458572446 }, {
      0.97814760073380569, 0.20791169081775918 }, { 0.97357890287316029,
      0.22835087011065561 }, { 0.96858316112863119, 0.24868988716485468 }, {
      0.96316256679765822, 0.26891982061526565 }, { 0.95731949753206735,
      0.28903179694447112 }, { 0.95105651629515375, 0.309016994374947 }, {
      0.94437637023748122, 0.32886664673858285 }, { 0.93728198949189168,
      0.34857204732181485 }, { 0.92977648588825157, 0.36812455268467759 }, {
      0.92186315158850063, 0.38751558645210266 }, { 0.913545457642601,
      0.40673664307579993 }, { 0.90482705246601969, 0.42577929156507238 }, {
      0.895711760239413, 0.44463517918492723 }, { 0.88620357923121484,
      0.4632960351198615 }, { 0.87630668004386369, 0.4817536741017151 }, {
      0.86602540378443871, 0.49999999999999983 }, { 0.85536426016050671,
      0.51802700937313007 }, { 0.84432792550201519, 0.53582679497899655 }, {
      0.83292124071009976, 0.55339154924334366 }, { 0.82114920913370426,
      0.57071356768443127 }, { 0.80901699437494767, 0.58778525229247269 }, {
      0.79652991802419648, 0.6045991148623745 }, { 0.78369345732584006,
      0.62114778027831008 }, { 0.77051324277578948, 0.63742398974868941 }, {
      0.75699505565175662, 0.65342060399010515 }, { 0.74314482547739447,
      0.669130606358858 }, { 0.72896862742141177, 0.6845471059286885 }, {
      0.71447267963280359, 0.69966334051336521 }, { 0.69966334051336565,
      0.71447267963280325 }, { 0.68454710592868884, 0.72896862742141144 }, {
      0.66913060635885835, 0.74314482547739413 }, { 0.6534206039901056,
      0.75699505565175629 }, { 0.63742398974869019, 0.77051324277578892 }, {
      0.62114778027831041, 0.78369345732583973 }, { 0.60459911486237528,
      0.796529918024196 }, { 0.58778525229247314, 0.80901699437494745 }, {
      0.570713567684432, 0.82114920913370382 }, { 0.55339154924334411,
      0.83292124071009954 }, { 0.535826794978997, 0.84432792550201485 }, {
      0.51802700937313018, 0.85536426016050671 }, { 0.50000000000000033,
      0.86602540378443849 }, { 0.48175367410171593, 0.87630668004386325 }, {
      0.463296035119862, 0.88620357923121462 }, { 0.44463517918492812,
      0.89571176023941257 }, { 0.42577929156507283, 0.90482705246601947 }, {
      0.40673664307580076, 0.91354545764260064 }, { 0.3875155864521031,
      0.92186315158850052 }, { 0.36812455268467847, 0.92977648588825124 }, {
      0.34857204732181529, 0.93728198949189145 }, { 0.32886664673858373,
      0.94437637023748089 }, { 0.30901699437494745, 0.95105651629515353 }, {
      0.289031796944472, 0.95731949753206713 }, { 0.2689198206152657,
      0.96316256679765822 }, { 0.24868988716485518, 0.96858316112863108 }, {
      0.22835087011065655, 0.97357890287316007 }, { 0.20791169081775968,
      0.97814760073380558 }, { 0.18738131458572538, 0.9822872507286885 }, {
      0.16676874671610256, 0.98599603707050487 }, { 0.14608302856241231,
      0.98927233296298822 }, { 0.12533323356430448, 0.99211470131447776 }, {
      0.10452846326765412, 0.99452189536827329 }, { 0.083677843332315663,
      0.99649285924950437 }, { 0.062790519529313971, 0.99802672842827156 }, {
      0.041875653729199748, 0.99912283009885838 }, { 0.020942419883357495,
      0.9997806834748455 }, { 6.123233995736766E-17, 1.0 }, { -
      0.020942419883356482, 0.9997806834748455 }, { -0.041875653729199623,
      0.99912283009885838 }, { -0.062790519529312958, 0.99802672842827156 }, { -
      0.083677843332314664, 0.99649285924950437 }, { -0.10452846326765311,
      0.9945218953682734 }, { -0.12533323356430348, 0.99211470131447788 }, { -
      0.14608302856241132, 0.98927233296298833 }, { -0.16676874671610156,
      0.98599603707050509 }, { -0.18738131458572438, 0.98228725072868872 }, { -
      0.2079116908177587, 0.9781476007338058 }, { -0.22835087011065555,
      0.97357890287316029 }, { -0.24868988716485421, 0.9685831611286313 }, { -
      0.26891982061526559, 0.96316256679765822 }, { -0.28903179694447106,
      0.95731949753206746 }, { -0.30901699437494734, 0.95105651629515364 }, { -
      0.32886664673858279, 0.94437637023748122 }, { -0.34857204732181435,
      0.93728198949189179 }, { -0.36812455268467759, 0.92977648588825157 }, { -
      0.38751558645210221, 0.92186315158850085 }, { -0.40673664307579988,
      0.91354545764260109 }, { -0.42577929156507194, 0.90482705246601991 }, { -
      0.44463517918492723, 0.895711760239413 }, { -0.46329603511986106,
      0.88620357923121507 }, { -0.48175367410171505, 0.87630668004386369 }, { -
      0.49999999999999944, 0.866025403784439 }, { -0.51802700937313007,
      0.85536426016050671 }, { -0.5358267949789961, 0.84432792550201541 }, { -
      0.553391549243344, 0.83292124071009954 }, { -0.57071356768443127,
      0.82114920913370437 }, { -0.587785252292473, 0.80901699437494745 }, { -
      0.6045991148623745, 0.79652991802419659 }, { -0.62114778027830964,
      0.78369345732584039 }, { -0.63742398974868941, 0.77051324277578948 }, { -
      0.65342060399010482, 0.756995055651757 }, { -0.6691306063588579,
      0.74314482547739447 }, { -0.68454710592868806, 0.72896862742141211 }, { -
      0.69966334051336521, 0.71447267963280359 }, { -0.71447267963280281,
      0.699663340513366 }, { -0.72896862742141133, 0.68454710592868884 }, { -
      0.7431448254773938, 0.66913060635885868 }, { -0.75699505565175629,
      0.6534206039901056 }, { -0.77051324277578881, 0.63742398974869019 }, { -
      0.78369345732583973, 0.62114778027831052 }, { -0.79652991802419593,
      0.60459911486237528 }, { -0.80901699437494734, 0.58778525229247325 }, { -
      0.82114920913370371, 0.57071356768443215 }, { -0.832921240710099,
      0.55339154924334488 }, { -0.84432792550201485, 0.535826794978997 }, { -
      0.85536426016050615, 0.518027009373131 }, { -0.86602540378443849,
      0.50000000000000033 }, { -0.87630668004386325, 0.481753674101716 }, { -
      0.88620357923121451, 0.46329603511986206 }, { -0.89571176023941257,
      0.44463517918492818 }, { -0.90482705246601935, 0.42577929156507288 }, { -
      0.91354545764260064, 0.40673664307580082 }, { -0.92186315158850041,
      0.38751558645210316 }, { -0.92977648588825113, 0.36812455268467853 }, { -
      0.93728198949189145, 0.34857204732181535 }, { -0.94437637023748089,
      0.32886664673858379 }, { -0.95105651629515331, 0.30901699437494839 }, { -
      0.95731949753206713, 0.28903179694447212 }, { -0.96316256679765788,
      0.26891982061526659 }, { -0.968583161128631, 0.24868988716485524 }, { -
      0.97357890287316007, 0.22835087011065661 }, { -0.97814760073380558,
      0.20791169081775973 }, { -0.9822872507286885, 0.18738131458572543 }, { -
      0.98599603707050487, 0.16676874671610262 }, { -0.98927233296298822,
      0.14608302856241237 }, { -0.99211470131447776, 0.12533323356430454 }, { -
      0.99452189536827329, 0.10452846326765418 }, { -0.99649285924950437,
      0.083677843332315732 }, { -0.99802672842827156, 0.062790519529314026 }, {
      -0.99912283009885838, 0.04187565372919981 }, { -0.9997806834748455,
      0.020942419883357554 }, { -1.0, 1.2246467991473532E-16 } };

  int32_T b_index;
  boolean_T varargout_1;
  real_T rtb_Product3_n;
  real_T rtb_fcn5;
  real_T rtb_q0;
  real_T rtb_q3;
  int32_T i;
  static const real_T tmp[301] = { -1.5707963267948966, -1.5498523757709646,
    -1.5289084247470326, -1.5079644737231006, -1.4870205226991686,
    -1.4660765716752366, -1.4451326206513047, -1.4241886696273731,
    -1.4032447186034411, -1.3823007675795091, -1.3613568165555772,
    -1.3404128655316452, -1.3194689145077132, -1.2985249634837812,
    -1.2775810124598492, -1.2566370614359172, -1.2356931104119853,
    -1.2147491593880533, -1.1938052083641213, -1.1728612573401893,
    -1.1519173063162573, -1.1309733552923253, -1.1100294042683938,
    -1.0890854532444618, -1.0681415022205298, -1.0471975511965979,
    -1.0262536001726659, -1.0053096491487339, -0.9843656981248019,
    -0.96342174710086992, -0.94247779607693793, -0.921533845053006,
    -0.900589894029074, -0.879645943005142, -0.85870199198121,
    -0.83775804095727846, -0.816814089933346, -0.79587013890941449,
    -0.77492618788548251, -0.75398223686155053, -0.73303828583761854,
    -0.71209433481368656, -0.69115038378975457, -0.67020643276582259,
    -0.64926248174189061, -0.62831853071795862, -0.60737457969402664,
    -0.58643062867009466, -0.56548667764616312, -0.54454272662223069,
    -0.52359877559829915, -0.50265482457436672, -0.48171087355043518,
    -0.46076692252650275, -0.43982297150257121, -0.41887902047863923,
    -0.39793506945470725, -0.37699111843077526, -0.35604716740684328,
    -0.3351032163829113, -0.31415926535897931, -0.29321531433504755,
    -0.27227136331111557, -0.25132741228718358, -0.2303834612632516,
    -0.20943951023931962, -0.18849555921538763, -0.16755160819145565,
    -0.14660765716752389, -0.1256637061435919, -0.10471975511965992,
    -0.083775804095727935, -0.062831853071795951, -0.041887902047863967,
    -0.020943951023931984, -2.2204460492503131E-16, 0.020943951023931762,
    0.041887902047863745, 0.062831853071795729, 0.083775804095727713,
    0.1047197551196597, 0.12566370614359168, 0.14660765716752344,
    0.16755160819145543, 0.18849555921538741, 0.20943951023931939,
    0.23038346126325138, 0.25132741228718336, 0.27227136331111534,
    0.29321531433504711, 0.31415926535897909, 0.33510321638291107,
    0.35604716740684306, 0.37699111843077504, 0.397935069454707,
    0.418879020478639, 0.43982297150257077, 0.46076692252650275,
    0.48171087355043474, 0.50265482457436672, 0.5235987755982987,
    0.54454272662223069, 0.56548667764616267, 0.58643062867009466,
    0.60737457969402664, 0.62831853071795862, 0.64926248174189061,
    0.67020643276582215, 0.69115038378975413, 0.71209433481368611,
    0.7330382858376181, 0.75398223686155008, 0.77492618788548207,
    0.795870138909414, 0.816814089933346, 0.837758040957278, 0.85870199198121,
    0.879645943005142, 0.900589894029074, 0.921533845053006, 0.94247779607693793,
    0.96342174710086947, 0.98436569812480146, 1.0053096491487334,
    1.0262536001726654, 1.0471975511965974, 1.0681415022205294,
    1.0890854532444614, 1.1100294042683934, 1.1309733552923253,
    1.1519173063162573, 1.1728612573401893, 1.1938052083641213,
    1.2147491593880533, 1.2356931104119853, 1.2566370614359172,
    1.2775810124598488, 1.2985249634837808, 1.3194689145077128,
    1.3404128655316447, 1.3613568165555767, 1.3823007675795087,
    1.4032447186034407, 1.4241886696273727, 1.4451326206513047,
    1.4660765716752366, 1.4870205226991686, 1.5079644737231006,
    1.5289084247470326, 1.5498523757709646, 1.5707963267948961,
    1.5917402778188281, 1.61268422884276, 1.6336281798666921, 1.654572130890624,
    1.675516081914556, 1.696460032938488, 1.71740398396242, 1.738347934986352,
    1.759291886010284, 1.780235837034216, 1.8011797880581479, 1.82212373908208,
    1.8430676901060119, 1.8640116411299434, 1.8849555921538754,
    1.9058995431778074, 1.9268434942017394, 1.9477874452256714,
    1.9687313962496034, 1.9896753472735353, 2.0106192982974673,
    2.0315632493213993, 2.0525072003453313, 2.0734511513692633,
    2.0943951023931953, 2.1153390534171272, 2.1362830044410592,
    2.1572269554649908, 2.1781709064889228, 2.1991148575128547,
    2.2200588085367867, 2.2410027595607187, 2.2619467105846507,
    2.2828906616085827, 2.3038346126325147, 2.3247785636564466,
    2.3457225146803786, 2.3666664657043106, 2.3876104167282426,
    2.4085543677521746, 2.4294983187761066, 2.4504422698000381,
    2.4713862208239705, 2.4923301718479021, 2.5132741228718345,
    2.534218073895766, 2.5551620249196985, 2.57610597594363, 2.5970499269675624,
    2.617993877991494, 2.6389378290154255, 2.6598817800393579,
    2.6808257310632895, 2.7017696820872219, 2.7227136331111534,
    2.7436575841350859, 2.7646015351590174, 2.78554548618295, 2.8064894372068814,
    2.8274333882308138, 2.8483773392547453, 2.8693212902786778,
    2.8902652413026093, 2.9112091923265409, 2.9321531433504733,
    2.9530970943744048, 2.9740410453983372, 2.9949849964222688,
    3.0159289474462012, 3.0368728984701328, 3.0578168494940652,
    3.0787608005179967, 3.0997047515419291, 3.1206487025658607,
    3.1415926535897931, 3.1625366046137247, 3.1834805556376571,
    3.2044245066615886, 3.22536845768552, 3.2463124087094526, 3.2672563597333841,
    3.2882003107573166, 3.3091442617812481, 3.3300882128051805,
    3.3510321638291121, 3.3719761148530445, 3.392920065876976,
    3.4138640169009085, 3.43480796792484, 3.4557519189487724, 3.476695869972704,
    3.4976398209966355, 3.5185837720205679, 3.5395277230444995,
    3.5604716740684319, 3.5814156250923634, 3.6023595761162959,
    3.6233035271402274, 3.64424747816416, 3.6651914291880914, 3.6861353802120238,
    3.7070793312359553, 3.7280232822598878, 3.7489672332838193,
    3.7699111843077517, 3.7908551353316833, 3.8117990863556148,
    3.8327430373795472, 3.8536869884034788, 3.8746309394274112,
    3.8955748904513428, 3.9165188414752752, 3.9374627924992067,
    3.9584067435231391, 3.9793506945470707, 4.0002946455710031,
    4.0212385965949347, 4.0421825476188671, 4.0631264986427986,
    4.0840704496667311, 4.1050144006906626, 4.1259583517145941,
    4.1469023027385266, 4.1678462537624581, 4.1887902047863905,
    4.2097341558103221, 4.2306781068342545, 4.251622057858186,
    4.2725660088821185, 4.29350995990605, 4.3144539109299824, 4.335397861953914,
    4.3563418129778464, 4.3772857640017779, 4.3982297150257095,
    4.4191736660496419, 4.4401176170735734, 4.4610615680975059,
    4.4820055191214374, 4.50294947014537, 4.5238934211693014, 4.5448373721932338,
    4.5657813232171653, 4.5867252742410978, 4.6076692252650293,
    4.6286131762889617, 4.6495571273128933, 4.6705010783368257,
    4.6914450293607572, 4.71238898038469 };

  real_T rtb_sincos_o1_idx_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S14>/In1'
  //   MATLABSystem: '<S7>/SourceBlock'

  varargout_1 = Sub_hoffmannFollower_13.getLatestMessage
    (&hoffmannFollower_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (varargout_1) {
    hoffmannFollower_B.In1 = hoffmannFollower_B.varargout_2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // MATLAB Function: '<S6>/circle centered' incorporates:
  //   Constant: '<S6>/radius'

  // MATLAB Function 'Select desired path/circle centered': '<S12>:1'
  // '<S12>:1:3' angles=linspace(-pi,pi,301);
  // '<S12>:1:4' r = radius*exp(angles*1j);
  for (b_index = 0; b_index < 301; b_index++) {
    hoffmannFollower_B.r[b_index].re = hoffmannFollower_P.radius_Value *
      b[b_index].re;
    hoffmannFollower_B.r[b_index].im = hoffmannFollower_P.radius_Value *
      b[b_index].im;
  }

  // MATLAB Function: '<S6>/straight line' incorporates:
  //   Constant: '<S6>/heading'
  //   Constant: '<S6>/len'

  // '<S12>:1:5' xs = real(r)-radius+start(1);
  // '<S12>:1:6' ys = imag(r)+start(2);
  // '<S12>:1:7' phis=(pi/2)+angles;
  //  % To visualize the angles, run this code:
  //  radius=3.6; start=[0 0];
  //  angles=linspace(-pi,pi,300);
  //  r = radius*exp(angles*1j);
  //  xs = real(r)-radius+start(1);
  //  ys = imag(r)+start(2);
  //  % since the direction of travel is in the 'x' direction, the
  //  % heading (phi) matchines the angle of the circle
  //  phis=(pi/2)+angles;
  //  xends=cos(phis);yends=sin(phis);
  //  figure;plot(xs,ys);hold on; quiver(xs,ys,xends,yends);axis equal;hold off
  // MATLAB Function 'Select desired path/straight line': '<S13>:1'
  // '<S13>:1:3' r = linspace(0,len,301);
  hoffmannFollower_B.ys[300] = hoffmannFollower_P.len_Value;
  hoffmannFollower_B.ys[0] = 0.0;
  if ((hoffmannFollower_P.len_Value < 0.0) && (fabs(hoffmannFollower_P.len_Value)
       > 8.9884656743115785E+307)) {
    hoffmannFollower_B.delta1 = hoffmannFollower_P.len_Value / 300.0;
    for (b_index = 0; b_index < 299; b_index++) {
      hoffmannFollower_B.ys[1 + b_index] = (1.0 + (real_T)b_index) *
        hoffmannFollower_B.delta1;
    }
  } else {
    hoffmannFollower_B.delta1 = hoffmannFollower_P.len_Value / 300.0;
    for (b_index = 0; b_index < 299; b_index++) {
      hoffmannFollower_B.ys[1 + b_index] = (1.0 + (real_T)b_index) *
        hoffmannFollower_B.delta1;
    }
  }

  // '<S13>:1:4' xs = r*cos(heading);
  hoffmannFollower_B.delta1 = cos(hoffmannFollower_P.heading_Value);
  for (i = 0; i < 301; i++) {
    hoffmannFollower_B.xs[i] = hoffmannFollower_B.ys[i] *
      hoffmannFollower_B.delta1;
  }

  // '<S13>:1:5' ys = r*sin(heading);
  hoffmannFollower_B.delta1 = sin(hoffmannFollower_P.heading_Value);
  for (b_index = 0; b_index < 301; b_index++) {
    hoffmannFollower_B.ys[b_index] *= hoffmannFollower_B.delta1;
  }

  // End of MATLAB Function: '<S6>/straight line'

  // MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
  //   Constant: '<S6>/heading'
  //   Constant: '<S6>/pathChoice '
  //   Constant: '<S6>/radius'
  //   Constant: '<S6>/start point'
  //   MATLAB Function: '<S6>/circle centered'

  // '<S13>:1:6' phis = heading*ones(1,length(r));
  if ((int32_T)hoffmannFollower_P.pathChoice_Value == 1) {
    for (b_index = 0; b_index < 301; b_index++) {
      hoffmannFollower_B.MultiportSwitch[b_index] =
        (hoffmannFollower_B.r[b_index].re - hoffmannFollower_P.radius_Value) +
        hoffmannFollower_P.startpoint_Value[0];
      hoffmannFollower_B.MultiportSwitch[b_index + 301] =
        hoffmannFollower_B.r[b_index].im + hoffmannFollower_P.startpoint_Value[1];
      hoffmannFollower_B.MultiportSwitch[b_index + 602] = tmp[b_index];
    }
  } else {
    for (i = 0; i < 301; i++) {
      hoffmannFollower_B.MultiportSwitch[i] = hoffmannFollower_B.xs[i];
      hoffmannFollower_B.MultiportSwitch[i + 301] = hoffmannFollower_B.ys[i];
      hoffmannFollower_B.MultiportSwitch[i + 602] =
        hoffmannFollower_P.heading_Value;
    }
  }

  // End of MultiPortSwitch: '<S6>/Multiport Switch'

  // MATLAB Function: '<S3>/calculate e'
  // MATLAB Function 'Hoffmann Controller/calculate e': '<S11>:1'
  // '<S11>:1:3' path=reshape(pathV,[],3);
  // '<S11>:1:4' x1 = path(1,1);
  // '<S11>:1:5' y1 = path(1,2);
  // '<S11>:1:6' phi1=path(1,3);
  // '<S11>:1:7' etmp = inf;
  // '<S11>:1:8' e = inf;
  hoffmannFollower_B.delta1 = (rtInf);

  // '<S11>:1:9' index=1;
  b_index = 0;

  //  find the nearest x,y
  // '<S11>:1:11' for i=1:length(path)
  for (i = 0; i < 301; i++) {
    // '<S11>:1:12' etmp = sqrt((x-path(i,1))^2+(y-path(i,2))^2);
    rtb_Product3_n = hoffmannFollower_B.In1.Pose.Pose.Position.X -
      hoffmannFollower_B.MultiportSwitch[i];
    rtb_fcn5 = hoffmannFollower_B.In1.Pose.Pose.Position.Y -
      hoffmannFollower_B.MultiportSwitch[301 + i];
    rtb_Product3_n = sqrt(rtb_Product3_n * rtb_Product3_n + rtb_fcn5 * rtb_fcn5);

    // '<S11>:1:13' if( etmp < e )
    if (rtb_Product3_n < hoffmannFollower_B.delta1) {
      // '<S11>:1:14' e = etmp;
      hoffmannFollower_B.delta1 = rtb_Product3_n;

      // '<S11>:1:15' index=i;
      b_index = i;
    }
  }

  // '<S11>:1:19' xpathOut=path(index,1);
  // '<S11>:1:20' ypathOut=path(index,2);
  // '<S11>:1:21' phipath=path(index,3);
  // '<S11>:1:23' ex1 = (path(index,1)-x);
  // '<S11>:1:24' ey1 = (path(index,2)-y);
  // '<S11>:1:25' ex2 = cos(phipath);
  // '<S11>:1:26' ey2 = sin(phipath);
  // '<S11>:1:27' sinnnn = ex1*ey2-ey1*ex2;
  // '<S11>:1:28' e = sign(sinnnn)*e;
  rtb_Product3_n = (hoffmannFollower_B.MultiportSwitch[b_index] -
                    hoffmannFollower_B.In1.Pose.Pose.Position.X) * sin
    (hoffmannFollower_B.MultiportSwitch[602 + b_index]) -
    (hoffmannFollower_B.MultiportSwitch[301 + b_index] -
     hoffmannFollower_B.In1.Pose.Pose.Position.Y) * cos
    (hoffmannFollower_B.MultiportSwitch[602 + b_index]);
  if (rtb_Product3_n < 0.0) {
    rtb_Product3_n = -1.0;
  } else if (rtb_Product3_n > 0.0) {
    rtb_Product3_n = 1.0;
  } else {
    if (rtb_Product3_n == 0.0) {
      rtb_Product3_n = 0.0;
    }
  }

  hoffmannFollower_B.delta1 *= rtb_Product3_n;

  // Sqrt: '<S17>/sqrt' incorporates:
  //   Product: '<S18>/Product'
  //   Product: '<S18>/Product1'
  //   Product: '<S18>/Product2'
  //   Product: '<S18>/Product3'
  //   Sum: '<S18>/Sum'

  rtb_Product3_n = sqrt(((hoffmannFollower_B.In1.Pose.Pose.Orientation.W *
    hoffmannFollower_B.In1.Pose.Pose.Orientation.W +
    hoffmannFollower_B.In1.Pose.Pose.Orientation.X *
    hoffmannFollower_B.In1.Pose.Pose.Orientation.X) +
    hoffmannFollower_B.In1.Pose.Pose.Orientation.Y *
    hoffmannFollower_B.In1.Pose.Pose.Orientation.Y) +
                        hoffmannFollower_B.In1.Pose.Pose.Orientation.Z *
                        hoffmannFollower_B.In1.Pose.Pose.Orientation.Z);

  // Product: '<S16>/Product'
  rtb_fcn5 = hoffmannFollower_B.In1.Pose.Pose.Orientation.W / rtb_Product3_n;

  // Product: '<S16>/Product1'
  rtb_q0 = hoffmannFollower_B.In1.Pose.Pose.Orientation.X / rtb_Product3_n;

  // Product: '<S16>/Product2'
  rtb_q3 = hoffmannFollower_B.In1.Pose.Pose.Orientation.Y / rtb_Product3_n;

  // Product: '<S16>/Product3'
  rtb_Product3_n = hoffmannFollower_B.In1.Pose.Pose.Orientation.Z /
    rtb_Product3_n;

  // Sum: '<S3>/Sum' incorporates:
  //   Fcn: '<S15>/fcn1'
  //   Fcn: '<S15>/fcn2'
  //   MATLAB Function: '<S3>/calculate e'
  //   Trigonometry: '<S15>/Trigonometric Function1'

  rtb_Product3_n = rt_atan2d_snf((rtb_q0 * rtb_q3 + rtb_fcn5 * rtb_Product3_n) *
    2.0, ((rtb_fcn5 * rtb_fcn5 + rtb_q0 * rtb_q0) - rtb_q3 * rtb_q3) -
    rtb_Product3_n * rtb_Product3_n) - hoffmannFollower_B.MultiportSwitch[602 +
    b_index];

  // MATLAB Function: '<S3>/calculate delta' incorporates:
  //   Constant: '<Root>/refVelocity'

  rtb_fcn5 = hoffmannFollower_P.refVelocity_Value;

  // MATLAB Function 'Hoffmann Controller/calculate delta': '<S10>:1'
  // '<S10>:1:3' if( abs(v) < eps )
  if (fabs(hoffmannFollower_P.refVelocity_Value) < 2.2204460492503131E-16) {
    // '<S10>:1:4' v = eps;
    rtb_fcn5 = 2.2204460492503131E-16;
  }

  //  if phi is greater than pi (or less than -pi), then
  //  we normalize to between [-pi,pi]
  // '<S10>:1:9' if( phi < -pi )
  if (rtb_Product3_n < -3.1415926535897931) {
    // '<S10>:1:10' phi = phi+2*pi;
    rtb_Product3_n += 6.2831853071795862;
  } else {
    if (rtb_Product3_n > 3.1415926535897931) {
      // '<S10>:1:11' elseif( phi > pi )
      // '<S10>:1:12' phi = phi-2*pi;
      rtb_Product3_n -= 6.2831853071795862;
    }
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  //  if we are pointed the "wrong" way, then screw it, let's
  //  follow in the direction the path is easiest to follow
  //  JMS I think I have a logic error here
  // if( phi < -pi/2 || phi > pi/2 )
  //     phi = max(min(phi - pi,pi/2),-pi/2);
  // end
  // '<S10>:1:22' delta = phi + atan2(k*e,v);
  hoffmannFollower_B.BusAssignment = hoffmannFollower_P.Constant_Value_a;

  // Switch: '<S3>/Switch' incorporates:
  //   MATLAB Function: '<S3>/calculate e'

  if (hoffmannFollower_B.delta1 > hoffmannFollower_P.Switch_Threshold) {
    // BusAssignment: '<Root>/Bus Assignment' incorporates:
    //   Constant: '<S3>/k1'

    hoffmannFollower_B.BusAssignment.Linear.X = hoffmannFollower_P.k1_Value;
  } else {
    // BusAssignment: '<Root>/Bus Assignment' incorporates:
    //   Constant: '<Root>/refVelocity'

    hoffmannFollower_B.BusAssignment.Linear.X =
      hoffmannFollower_P.refVelocity_Value;
  }

  // End of Switch: '<S3>/Switch'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S3>/k'
  //   Gain: '<S3>/Gain'
  //   MATLAB Function: '<S3>/calculate delta'
  //   MATLAB Function: '<S3>/calculate e'

  hoffmannFollower_B.BusAssignment.Angular.Z = (rt_atan2d_snf
    (hoffmannFollower_P.k_Value * hoffmannFollower_B.delta1, rtb_fcn5) +
    rtb_Product3_n) * hoffmannFollower_P.Gain_Gain;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S4>/SinkBlock' incorporates:
  //   MATLABSystem: '<S4>/SinkBlock'

  Pub_hoffmannFollower_9.publish(&hoffmannFollower_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Gain: '<S19>/1//2' incorporates:
  //   MATLAB Function: '<S3>/calculate e'

  rtb_Product3_n = hoffmannFollower_B.MultiportSwitch[602 + b_index] *
    hoffmannFollower_P.u2_Gain;

  // Trigonometry: '<S19>/sincos'
  hoffmannFollower_B.delta1 = cos(rtb_Product3_n);
  rtb_Product3_n = sin(rtb_Product3_n);
  rtb_fcn5 = hoffmannFollower_B.delta1;

  // Gain: '<S19>/1//2' incorporates:
  //   Constant: '<S9>/Constant'

  rtb_q0 = rtb_Product3_n;
  rtb_Product3_n = hoffmannFollower_P.u2_Gain *
    hoffmannFollower_P.Constant_Value_l;

  // Trigonometry: '<S19>/sincos'
  hoffmannFollower_B.delta1 = cos(rtb_Product3_n);
  rtb_Product3_n = sin(rtb_Product3_n);
  rtb_q3 = hoffmannFollower_B.delta1;

  // Gain: '<S19>/1//2' incorporates:
  //   Constant: '<S9>/Constant'

  rtb_sincos_o1_idx_1 = rtb_Product3_n;
  rtb_Product3_n = hoffmannFollower_P.u2_Gain *
    hoffmannFollower_P.Constant_Value_l;

  // Trigonometry: '<S19>/sincos'
  hoffmannFollower_B.delta1 = cos(rtb_Product3_n);
  rtb_Product3_n = sin(rtb_Product3_n);

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S2>/Constant'
  //   Fcn: '<S19>/q0'
  //   Fcn: '<S19>/q1'
  //   Fcn: '<S19>/q2'
  //   Fcn: '<S19>/q3'
  //   MATLAB Function: '<S3>/calculate e'
  //   Trigonometry: '<S19>/sincos'

  hoffmannFollower_B.BusAssignment1 = hoffmannFollower_P.Constant_Value_c;
  hoffmannFollower_B.BusAssignment1.Pose.Position.X =
    hoffmannFollower_B.MultiportSwitch[b_index];
  hoffmannFollower_B.BusAssignment1.Pose.Position.Y =
    hoffmannFollower_B.MultiportSwitch[301 + b_index];
  hoffmannFollower_B.BusAssignment1.Pose.Orientation.X = rtb_fcn5 * rtb_q3 *
    rtb_Product3_n - rtb_q0 * rtb_sincos_o1_idx_1 * hoffmannFollower_B.delta1;
  hoffmannFollower_B.BusAssignment1.Pose.Orientation.Y = rtb_fcn5 *
    rtb_sincos_o1_idx_1 * hoffmannFollower_B.delta1 + rtb_q0 * rtb_q3 *
    rtb_Product3_n;
  hoffmannFollower_B.BusAssignment1.Pose.Orientation.Z = rtb_q0 * rtb_q3 *
    hoffmannFollower_B.delta1 - rtb_fcn5 * rtb_sincos_o1_idx_1 * rtb_Product3_n;
  hoffmannFollower_B.BusAssignment1.Pose.Orientation.W = rtb_fcn5 * rtb_q3 *
    hoffmannFollower_B.delta1 + rtb_q0 * rtb_sincos_o1_idx_1 * rtb_Product3_n;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S5>/SinkBlock' incorporates:
  //   MATLABSystem: '<S5>/SinkBlock'

  Pub_hoffmannFollower_68.publish(&hoffmannFollower_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void hoffmannFollower_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(hoffmannFollower_M, (NULL));

  // block I/O
  (void) memset(((void *) &hoffmannFollower_B), 0,
                sizeof(B_hoffmannFollower_T));

  // states (dwork)
  (void) memset((void *)&hoffmannFollower_DW, 0,
                sizeof(DW_hoffmannFollower_T));

  {
    static const char_T tmp[19] = { '/', 'a', 'z', 'c', 'a', 'r', '_', 's', 'i',
      'm', '/', 'w', 'a', 'y', 'p', 'o', 'i', 'n', 't' };

    static const char_T tmp_0[18] = { '/', 'a', 'z', 'c', 'a', 'r', '_', 's',
      'i', 'm', '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_1[15] = { '/', 'a', 'z', 'c', 'a', 'r', '_', 's',
      'i', 'm', '/', 'o', 'd', 'o', 'm' };

    char_T tmp_2[20];
    char_T tmp_3[19];
    char_T tmp_4[16];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe3'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    hoffmannFollower_DW.obj_l.isInitialized = 0;
    hoffmannFollower_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[15] = '\x00';
    Sub_hoffmannFollower_13.createSubscriber(tmp_4,
      hoffmannFollowe_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe3'

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    hoffmannFollower_DW.obj_n.isInitialized = 0;
    hoffmannFollower_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[18] = '\x00';
    Pub_hoffmannFollower_9.createPublisher(tmp_3,
      hoffmannFollowe_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    hoffmannFollower_DW.obj.isInitialized = 0;
    hoffmannFollower_DW.obj.isInitialized = 1;
    for (i = 0; i < 19; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[19] = '\x00';
    Pub_hoffmannFollower_68.createPublisher(tmp_2,
      hoffmannFollowe_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S14>/Out1'
    hoffmannFollower_B.In1 = hoffmannFollower_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'
  }
}

// Model terminate function
void hoffmannFollower_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (hoffmannFollower_DW.obj_l.isInitialized == 1) {
    hoffmannFollower_DW.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S4>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SinkBlock'

  if (hoffmannFollower_DW.obj_n.isInitialized == 1) {
    hoffmannFollower_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S5>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SinkBlock'

  if (hoffmannFollower_DW.obj.isInitialized == 1) {
    hoffmannFollower_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
