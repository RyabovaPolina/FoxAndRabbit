#pragma once
#include <string>
const int height1 = 15;//размер карты высота
const int width1 = 40;//размер карты ширина 
const int height2 = 20;//размер карты высота
const int width2 = 45;//размер карты ширина 
const int height3 = 20;//размер карты высота
const int width3 = 50;//размер карты ширина 

using namespace std;

string Maze1[height1] = {
"CAADAAAAAAADAAAAAAAADAAAAAAADAAAAAAAAAAD                                ",
"B  B       B        B       B          B                                ",
"B  B       B     CAAK    CAAB    CAAA  B                                ",
"B  SAAAAD  SAAD  B       B  B    B     B                                ",
"B       B     B          B  BAAAAK  AAAB                                ",
"BAAAD   SAA   BAAAAAAAD                B                                ",
"B                     B     B    CAA   B                         LEVEL 1",
"B   CAAAAAAD     AAD  B  CAAK    B     B                                ",
"BAAAK      B  B    B  B  B       SAAAAAB                                ",
"B          B  B    B     B  B          B                                ",
"B   AAAAD  B       SAAAAAK  B      B   B                                ",
"B       B     B             SAAD   SAAAB                                ",
"BAAAA   B     SAAAD   AAAD     B       B                                ",
"B                 B      B     B    B  B                                ",
"SAAAAAAAAAAAAAAAAASAAAAAASAAAAASAAAASAAK                                ",
};

string Maze2[height2] = {
"CAAAAAAAADAAAAADAAAAAAAAAAADAAAADAAAAAAAAAAAD                                ",
"B        B     B           B    B           B                                ",
"BAA   B  B  B  B  CAAAAA   SAA      CAA  B  B                                ",
"B   AAB  SAAK  B  B                 B    B  B                                ",
"B     B        B  B  CAAAAAAAAAAAAAAK       B                                ",
"BAAD  SAAAAAAAAK     B              B  CAA  B                                ",
"B  B              CAAK    CAAD   B  B  B    B                                ",
"B  BAAAAAAAAAAAAAAK       B  B   B     B    B                         LEVEL 2",
"B  B       B          CAAAK            B    B                                ",
"B  SAA  B     B   B   B      B   B  AAAK    B                                ",
"B       SAAAAAK   BAAAKAAD   SAAAK          B                                ",
"B  B              B      B          CAAAA   B                                ",
"B  B   AAAAAAAAAAAB      BAAAAA  B  B       B                                ",
"B  B              B  CAAAD       BAAAAA  AAAB                                ",
"SAAKAAD   CAAAD   B  B   B  AAD  B          B                                ",
"      B   B   B      BAA      B  B   AAAAD  B                                ",
"B     B   B   SAAADAAK    B              B  B                                ",
"B  AAAK   SA      B     AAK      AAAAAA  B  B                                ",
"B                    B        B          B  B                                ",
"SAAAAAAAAAAAAAAAAAAAASAAAAAAAASAAAAAAAAAASAAK                                ",
};

string Maze3[height3] = {
"CAAAAAAAADAAADAADAAAAADAADAAAAAAAAADAADAAAAAAAAAAD                                ",
"B        B   B  B     B  B         B  B          B                                ",
"BAAAAAD  BAAAK  B     B  SAAAD  B  B       CAAAAAB                                ",
"B               SAAD         B  B  SAAAAD  B     B                                ",
"B  CAAA  B  B      B  B         B       B  B  B  B                                ",
"B  B     B  BAAD      B  CAAD   SAAAAA  B  SAAK  B                                ",
"B  B  B     B  B  CAAAB  B              B        B                                ",
"BAAAAASAAA  B  B  B   SAAK  B  CAAD  B  SA  AD   B                         LEVEL 3",
"B              B  B B       B  B  B  B       B   B                                ",
"B  CAAD  B  CAAK  SAAAD  CAAK  B  SAAB  B    B   B                                ",
"B  B     B  B         B  B     B     B  B  AAK   B                                ",
"B     B  SAAK  AAAD   B  B  AAAK  CAAK  B        B                                ",
"BAAAACK           SAAAK  B        B        CAAD  B                                ",
"B    B   AAA  B          B  AAD  AB  AAAD  B  SAAB                                ",
"B CA          B  CAAAAAAAK    B   B     B        B                                ",
"BAK   B  CAAAAK  B            B   BAAD  BAAAAAD  B                                ",
"B     B  B       B   CAAD  CAAKAAAB  B  B     B  B                                ",
"B  CAAK  B  AAADAK   B  SAAB      SA B  B  SAAK  B                                ",
"B  B     B     B     B          B                B                                ",
"SAASAAAAASAAAAASAAAAASAAAAAAAAAAAAAAAAAAAAAAAAAAAK                                ",
};