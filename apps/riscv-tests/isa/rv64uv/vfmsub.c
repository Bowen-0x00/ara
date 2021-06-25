// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matteo Perotti <mperotti@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "float_macros.h"
#include "vector_macros.h"

// Simple random test with similar values
void TEST_CASE1(void) {
  VSET(16, e16, m1);
  //               0.6821,  0.7749,  0.0299,  0.0299, -0.5410, -0.1865,  0.1885,
  //               0.0228, -0.5410,  0.1902, -0.9160, -0.3511, -0.9287, -0.9961,
  //               -0.6509, -0.3940
  VLOAD_16(v2, 0x3975, 0x3a33, 0x27a5, 0x27a5, 0xb854, 0xb1f8, 0x3208, 0x25d8,
           0xb854, 0x3216, 0xbb54, 0xb59e, 0xbb6e, 0xbbf8, 0xb935, 0xb64e);
  //              -0.9048,  0.1698,  0.2411,  0.2411, -0.6147,  0.9580,  0.5117,
  //              0.8330, -0.6147,  0.5591,  0.7031, -0.1556,  0.2397,  0.8154,
  //              0.1646,  0.2693
  VLOAD_16(v3, 0xbb3d, 0x316f, 0x33b7, 0x33b7, 0xb8eb, 0x3baa, 0x3818, 0x3aaa,
           0xb8eb, 0x3879, 0x39a0, 0xb0fb, 0x33ac, 0x3a86, 0x3144, 0x344f);
  //              -0.2292,  0.7578, -0.7427, -0.7427,  0.1119,  0.2939, -0.2983,
  //              -0.3608,  0.1119, -0.5562, -0.0629, -0.1968, -0.8638, -0.2700,
  //              -0.7690,  0.4216
  VLOAD_16(v1, 0xb356, 0x3a10, 0xb9f1, 0xb9f1, 0x2f29, 0x34b4, 0xb4c6, 0xb5c6,
           0x2f29, 0xb873, 0xac06, 0xb24c, 0xbae9, 0xb452, 0xba27, 0x36bf);
  asm volatile("vfmsub.vv v1, v2, v3");
  //               0.7485,  0.4175, -0.2632, -0.2632,  0.5542, -1.0127, -0.5679,
  //               -0.8413,  0.5542, -0.6650, -0.6455,  0.2247,  0.5625,
  //               -0.5464,  0.3359, -0.4355
  VCMP_U16(1, v1, 0x39fd, 0x36ae, 0xb436, 0xb436, 0x386f, 0xbc0d, 0xb88b,
           0xbabb, 0x386f, 0xb952, 0xb92a, 0x3331, 0x3880, 0xb85f, 0x3560,
           0xb6f8);

  VSET(16, e32, m1);
  //              -0.74553698, -0.16736358, -0.11869104, -0.85860848,
  //              -0.66138542, -0.68386567, -0.45389724, -0.12761629,
  //              -0.95652348,  0.71083277,  0.24187960,  0.01609672,
  //              -0.58867335, -0.55222940, -0.67417240, -0.06725668
  VLOAD_32(v2, 0xbf3edb83, 0xbe2b615c, 0xbdf3144a, 0xbf5bcdc4, 0xbf29508e,
           0xbf2f11d2, 0xbee86538, 0xbe02add8, 0xbf74deb9, 0x3f35f923,
           0x3e77af49, 0x3c83dd45, 0xbf16b34c, 0xbf0d5ee8, 0xbf2c9690,
           0xbd89bddf);
  //              -0.17500710, -0.81537211, -0.31956050,  0.22762603,
  //              0.49659184, -0.09389434,  0.05757815, -0.13087828,
  //              -0.73042232, -0.79662275, -0.96801740,  0.03017101,
  //              0.70759267, -0.35606241,  0.18037270, -0.35372722
  VLOAD_32(v3, 0xbe333510, 0xbf50bc3a, 0xbea39d6f, 0x3e6916cc, 0x3efe4149,
           0xbdc04bad, 0x3d6bd711, 0xbe0604f5, 0xbf3afcf5, 0xbf4bef78,
           0xbf77cffd, 0x3cf72932, 0x3f3524cb, 0xbeb64dd0, 0x3e38b39f,
           0xbeb51bbc);
  //               0.92876774,  0.18572871, -0.42147154, -0.79289448,
  //               0.90907055,  0.07037155,  0.07339484,  0.17415307,
  //               -0.61978233, -0.04939311,  0.56138068, -0.51601994,
  //               -0.80625385, -0.31227911,  0.91474551,  0.78424871
  VLOAD_32(v1, 0x3f6dc3b9, 0x3e3e2fab, 0xbed7cb1e, 0xbf4afb22, 0x3f68b8d9,
           0x3d901ef6, 0x3d965009, 0x3e32552f, 0xbf1eaa0e, 0xbd4a506e,
           0x3f0fb6a5, 0xbf0419e2, 0xbf4e66a7, 0xbe9fe30c, 0x3f6a2cc3,
           0x3f48c486);
  asm volatile("vfmsub.vv v1, v2, v3");
  //              -0.51742357,  0.78428787,  0.36958539,  0.45315993,
  //              -1.09783781,  0.04576965, -0.09089187,
  //              0.10865352,  1.32325864,  0.76151252,  1.10380387,
  //              -0.03847724, -0.23297250,  0.52851212, -0.79706889, 0.30098125
  VCMP_U32(2, v1, 0xbf0475df, 0x3f48c717, 0x3ebd3a4c, 0x3ee80493, 0xbf8c85f3,
           0x3d3b78f5, 0xbdba2584, 0x3dde85bc, 0x3fa9608a, 0x3f42f27c,
           0x3f8d4973, 0xbd1d9a4f, 0xbe6e9058, 0x3f074c92, 0xbf4c0cb5,
           0x3e9a1a37);

  VSET(16, e64, m1);
  //               0.3304351537536074, -0.7528197595818080, -0.7530937950641439,
  //               -0.7994160811423281,  0.0797802827518117,
  //               -0.6361377214985149,  0.1748070414096887, 0.8251843575618585,
  //               0.0699629848559165, -0.8195631240215655, -0.4843919596862658,
  //               -0.9206444585342115,  0.9791118581337512, 0.5143481050333210,
  //               0.5856279779979670, -0.5536419150604011
  VLOAD_64(v2, 0x3fd525d97cb482ac, 0xbfe8171976e5f762, 0xbfe819582893df6e,
           0xbfe994d1088ce396, 0x3fb46c7b0948dfc0, 0xbfe45b3d7eb2d188,
           0x3fc66013befb8968, 0x3fea67e9069cc438, 0x3fb1e9181be2ff10,
           0xbfea39dc71d5c454, 0xbfdf00472253102c, 0xbfed75eb5e14bcf6,
           0x3fef54e26439ed98, 0x3fe0758a283c1602, 0x3fe2bd76e2a3f6ca,
           0xbfe1b76f3fdc22ac);
  //               0.4156163852505284, -0.7806302214299039, -0.8826873649954201,
  //               0.4810449553239884,  0.9337837820126544, -0.5377837408558668,
  //               -0.1434453653318362,  0.1199087999382409,
  //               -0.2601268153647489, -0.1813009025048657,
  //               -0.2492371358416354,  0.4131695659117063,
  //               -0.9085600854772706, -0.3952216110937696, 0.0817663443229741,
  //               0.1439804529607418
  VLOAD_64(v3, 0x3fda997577954be0, 0xbfe8faec3ae9f10e, 0xbfec3ef992a7ed86,
           0x3fdec970c7c16d8c, 0x3fede18e86a8f206, 0xbfe135863f697cd2,
           0xbfc25c6af06e7710, 0x3fbeb257d63cc310, 0xbfd0a5eaf1337874,
           0xbfc734de337f3100, 0xbfcfe700a1b1bb78, 0x3fda715ec352c558,
           0xbfed12ec99b26d4c, 0xbfd94b4f95947db0, 0x3fb4eea39ec7d8a0,
           0x3fc26df3945d6540);
  //              -0.2185765241217579, -0.9587275435281344,  0.1216903502931035,
  //              0.7653655177934149, -0.5928258331230032,  0.9123074434439491,
  //              0.1569052366565831,  0.2566745252901157, -0.9113595614847214,
  //              0.1628442001087833,  0.2337303194688813,  0.1926350000139823,
  //              -0.6653994610877216, -0.6745212179353777,  0.8748797125997727,
  //              -0.7324641634418565
  VLOAD_64(v1, 0xbfcbfa50c7635df8, 0xbfeeade562a749c2, 0x3fbf27194abf66e0,
           0x3fe87ddfd38d1514, 0xbfe2f86de1af9792, 0x3fed319f612fa6f6,
           0x3fc4157886016dd8, 0x3fd06d5afcf59780, 0xbfed29db86ef2934,
           0x3fc4d81428e7be98, 0x3fcdeae00719eac8, 0x3fc8a84380900070,
           0xbfe54af3cf84bab0, 0xbfe595ad856fb278, 0x3febff03bd3198ce,
           0xbfe77058af6f3156);
  asm volatile("vfmsub.vv v1, v2, v3");
  //              -0.4878417526056305,  1.5023792602532113,  0.7910431172705017,
  //              -1.0928904581998689, -0.9810795946017860, -0.0425694375227023,
  //              0.1708735055334605,  0.0918950033157782,  0.1963653801662987,
  //              0.0478398011349183,  0.1360200483560070, -0.5905179111943168,
  //              0.2570595827304748,  0.0482829008439404,  0.4305876927582732,
  //              0.2615424092003222
  VCMP_U64(3, v1, 0xbfdf38cc9d4420dd, 0x3ff809bed5cf9e94, 0x3fe95039a7cce2e7,
           0xbff17c7ab4814324, 0xbfef650108b2cdb1, 0xbfa5cba94bf030ac,
           0x3fc5df2edb027178, 0x3fb7866e51e83656, 0x3fc9228032f0c004,
           0x3fa87e755aa4ab1c, 0x3fc1691adda50ab1, 0xbfe2e585d18904b2,
           0x3fd073aa093cd9d6, 0x3fa8b88950295616, 0x3fdb8ebfae9d3d83,
           0x3fd0bd1c5f821364);
};

// Simple random test with similar values (masked)
// The numbers are the same of TEST_CASE1
void TEST_CASE2(void) {
  VSET(16, e16, m1);
  //               0.6821,  0.7749,  0.0299,  0.0299, -0.5410, -0.1865,  0.1885,
  //               0.0228,  0.7217,  0.1902, -0.9160, -0.3511, -0.9287, -0.9961,
  //               -0.6509, -0.3940
  VLOAD_16(v2, 0x3975, 0x3a33, 0x27a5, 0x27a5, 0xb854, 0xb1f8, 0x3208, 0x25d8,
           0x39c6, 0x3216, 0xbb54, 0xb59e, 0xbb6e, 0xbbf8, 0xb935, 0xb64e);
  //              -0.9048,  0.1698,  0.2411,  0.2411, -0.6147,  0.9580,  0.5117,
  //              0.8330, -0.8584,  0.5591,  0.7031, -0.1556,  0.2397,  0.8154,
  //              0.1646,  0.2693
  VLOAD_16(v3, 0xbb3d, 0x316f, 0x33b7, 0x33b7, 0xb8eb, 0x3baa, 0x3818, 0x3aaa,
           0xbade, 0x3879, 0x39a0, 0xb0fb, 0x33ac, 0x3a86, 0x3144, 0x344f);
  VLOAD_8(v0, 0xAA, 0xAA);
  //              -0.2292,  0.7578, -0.7427, -0.7427,  0.1119,  0.2939, -0.2983,
  //              -0.3608,  0.3169, -0.5562, -0.0629, -0.1968, -0.8638, -0.2700,
  //              -0.7690,  0.4216
  VLOAD_16(v1, 0xb356, 0x3a10, 0xb9f1, 0xb9f1, 0x2f29, 0x34b4, 0xb4c6, 0xb5c6,
           0x3512, 0xb873, 0xac06, 0xb24c, 0xbae9, 0xb452, 0xba27, 0x36bf);
  asm volatile("vfmsub.vv v1, v2, v3, v0.t");
  //              -0.2292,  0.4175, -0.7427, -0.2632,  0.1119, -1.0127, -0.2983,
  //              -0.8413,  0.3169, -0.6650, -0.0629,  0.2247, -0.8638, -0.5464,
  //              -0.7690, -0.4355
  VCMP_U16(4, v1, 0xb356, 0x36ae, 0xb9f1, 0xb436, 0x2f29, 0xbc0d, 0xb4c6,
           0xbabb, 0x3512, 0xb952, 0xac06, 0x3331, 0xbae9, 0xb85f, 0xba27,
           0xb6f8);

  VSET(16, e32, m1);
  //              -0.74553698, -0.16736358, -0.11869104, -0.85860848,
  //              -0.66138542, -0.68386567, -0.45389724, -0.12761629,
  //              -0.95652348,  0.71083277,  0.24187960,  0.01609672,
  //              -0.58867335, -0.55222940, -0.67417240, -0.06725668
  VLOAD_32(v2, 0xbf3edb83, 0xbe2b615c, 0xbdf3144a, 0xbf5bcdc4, 0xbf29508e,
           0xbf2f11d2, 0xbee86538, 0xbe02add8, 0xbf74deb9, 0x3f35f923,
           0x3e77af49, 0x3c83dd45, 0xbf16b34c, 0xbf0d5ee8, 0xbf2c9690,
           0xbd89bddf);
  //              -0.17500710, -0.81537211, -0.31956050,  0.22762603,
  //              0.49659184, -0.09389434,  0.05757815, -0.13087828,
  //              -0.73042232, -0.79662275, -0.96801740,  0.03017101,
  //              0.70759267, -0.35606241,  0.18037270, -0.35372722
  VLOAD_32(v3, 0xbe333510, 0xbf50bc3a, 0xbea39d6f, 0x3e6916cc, 0x3efe4149,
           0xbdc04bad, 0x3d6bd711, 0xbe0604f5, 0xbf3afcf5, 0xbf4bef78,
           0xbf77cffd, 0x3cf72932, 0x3f3524cb, 0xbeb64dd0, 0x3e38b39f,
           0xbeb51bbc);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               0.92876774,  0.18572871, -0.42147154, -0.79289448,
  //               0.90907055,  0.07037155,  0.07339484,  0.17415307,
  //               -0.61978233, -0.04939311,  0.56138068, -0.51601994,
  //               -0.80625385, -0.31227911,  0.91474551,  0.78424871
  VLOAD_32(v1, 0x3f6dc3b9, 0x3e3e2fab, 0xbed7cb1e, 0xbf4afb22, 0x3f68b8d9,
           0x3d901ef6, 0x3d965009, 0x3e32552f, 0xbf1eaa0e, 0xbd4a506e,
           0x3f0fb6a5, 0xbf0419e2, 0xbf4e66a7, 0xbe9fe30c, 0x3f6a2cc3,
           0x3f48c486);
  asm volatile("vfmsub.vv v1, v2, v3, v0.t");
  //               0.92876774,  0.78428787, -0.42147154,  0.45315993,
  //               0.90907055,  0.04576965,  0.07339484,  0.10865352,
  //               -0.61978233,  0.76151252,  0.56138068, -0.03847724,
  //               -0.80625385,  0.52851212,  0.91474551,  0.30098125
  VCMP_U32(5, v1, 0x3f6dc3b9, 0x3f48c717, 0xbed7cb1e, 0x3ee80493, 0x3f68b8d9,
           0x3d3b78f5, 0x3d965009, 0x3dde85bc, 0xbf1eaa0e, 0x3f42f27c,
           0x3f0fb6a5, 0xbd1d9a4f, 0xbf4e66a7, 0x3f074c92, 0x3f6a2cc3,
           0x3e9a1a37);

  VSET(16, e64, m1);
  //               0.3304351537536074, -0.7528197595818080, -0.7530937950641439,
  //               -0.7994160811423281,  0.0797802827518117,
  //               -0.6361377214985149,  0.1748070414096887, 0.8251843575618585,
  //               0.0699629848559165, -0.8195631240215655, -0.4843919596862658,
  //               -0.9206444585342115,  0.9791118581337512, 0.5143481050333210,
  //               0.5856279779979670, -0.5536419150604011
  VLOAD_64(v2, 0x3fd525d97cb482ac, 0xbfe8171976e5f762, 0xbfe819582893df6e,
           0xbfe994d1088ce396, 0x3fb46c7b0948dfc0, 0xbfe45b3d7eb2d188,
           0x3fc66013befb8968, 0x3fea67e9069cc438, 0x3fb1e9181be2ff10,
           0xbfea39dc71d5c454, 0xbfdf00472253102c, 0xbfed75eb5e14bcf6,
           0x3fef54e26439ed98, 0x3fe0758a283c1602, 0x3fe2bd76e2a3f6ca,
           0xbfe1b76f3fdc22ac);
  //               0.4156163852505284, -0.7806302214299039, -0.8826873649954201,
  //               0.4810449553239884,  0.9337837820126544, -0.5377837408558668,
  //               -0.1434453653318362,  0.1199087999382409,
  //               -0.2601268153647489, -0.1813009025048657,
  //               -0.2492371358416354,  0.4131695659117063,
  //               -0.9085600854772706, -0.3952216110937696, 0.0817663443229741,
  //               0.1439804529607418
  VLOAD_64(v3, 0x3fda997577954be0, 0xbfe8faec3ae9f10e, 0xbfec3ef992a7ed86,
           0x3fdec970c7c16d8c, 0x3fede18e86a8f206, 0xbfe135863f697cd2,
           0xbfc25c6af06e7710, 0x3fbeb257d63cc310, 0xbfd0a5eaf1337874,
           0xbfc734de337f3100, 0xbfcfe700a1b1bb78, 0x3fda715ec352c558,
           0xbfed12ec99b26d4c, 0xbfd94b4f95947db0, 0x3fb4eea39ec7d8a0,
           0x3fc26df3945d6540);
  VLOAD_8(v0, 0xAA, 0xAA);
  //              -0.2185765241217579, -0.9587275435281344,  0.1216903502931035,
  //              0.7653655177934149, -0.5928258331230032,  0.9123074434439491,
  //              0.1569052366565831,  0.2566745252901157, -0.9113595614847214,
  //              0.1628442001087833,  0.2337303194688813,  0.1926350000139823,
  //              -0.6653994610877216, -0.6745212179353777,  0.8748797125997727,
  //              -0.7324641634418565
  VLOAD_64(v1, 0xbfcbfa50c7635df8, 0xbfeeade562a749c2, 0x3fbf27194abf66e0,
           0x3fe87ddfd38d1514, 0xbfe2f86de1af9792, 0x3fed319f612fa6f6,
           0x3fc4157886016dd8, 0x3fd06d5afcf59780, 0xbfed29db86ef2934,
           0x3fc4d81428e7be98, 0x3fcdeae00719eac8, 0x3fc8a84380900070,
           0xbfe54af3cf84bab0, 0xbfe595ad856fb278, 0x3febff03bd3198ce,
           0xbfe77058af6f3156);
  asm volatile("vfmsub.vv v1, v2, v3, v0.t");
  //              -0.2185765241217579,  1.5023792602532113,  0.1216903502931035,
  //              -1.0928904581998689, -0.5928258331230032, -0.0425694375227023,
  //              0.1569052366565831,  0.0918950033157782, -0.9113595614847214,
  //              0.0478398011349183,  0.2337303194688813, -0.5905179111943168,
  //              -0.6653994610877216,  0.0482829008439404,  0.8748797125997727,
  //              0.2615424092003222
  VCMP_U64(6, v1, 0xbfcbfa50c7635df8, 0x3ff809bed5cf9e94, 0x3fbf27194abf66e0,
           0xbff17c7ab4814324, 0xbfe2f86de1af9792, 0xbfa5cba94bf030ac,
           0x3fc4157886016dd8, 0x3fb7866e51e83656, 0xbfed29db86ef2934,
           0x3fa87e755aa4ab1c, 0x3fcdeae00719eac8, 0xbfe2e585d18904b2,
           0xbfe54af3cf84bab0, 0x3fa8b88950295616, 0x3febff03bd3198ce,
           0x3fd0bd1c5f821364);
};

// Simple random test with similar values (vector-scalar)
void TEST_CASE3(void) {
  VSET(16, e16, m1);
  double dscalar_16;
  //                              0.1489
  BOX_HALF_IN_DOUBLE(dscalar_16, 0x30c4);
  //               0.8530, -0.3298, -0.1814, -0.2385,  0.9946,  0.6553,  0.8711,
  //               -0.6377,  0.4224, -0.1814,  0.7026,  0.2852,  0.0553, 0.7349,
  //               -0.8105,  0.0033
  VLOAD_16(v2, 0x3ad3, 0xb547, 0xb1ce, 0xb3a2, 0x3bf5, 0x393e, 0x3af8, 0xb91a,
           0x36c2, 0xb1ce, 0x399f, 0x3490, 0x2b15, 0x39e1, 0xba7c, 0x1abd);
  //              -0.2338, -0.2512,  0.0069,  0.0613, -0.1733,  0.8560, -0.2766,
  //              -0.0028, -0.1803,  0.0069,  0.7856, -0.0243, -0.1974,  0.6416,
  //              0.7109,  0.0817
  VLOAD_16(v1, 0xb37b, 0xb405, 0x1f06, 0x2bd8, 0xb18c, 0x3ad9, 0xb46d, 0x99d2,
           0xb1c5, 0x1f06, 0x3a49, 0xa639, 0xb251, 0x3922, 0x39b0, 0x2d3a);
  asm volatile("vfmsub.vf v1, %[A], v2" ::[A] "f"(dscalar_16));
  //              -0.8877,  0.2925,  0.1824,  0.2477, -1.0205, -0.5278, -0.9121,
  //              0.6372, -0.4492,  0.1824, -0.5854, -0.2888, -0.0847, -0.6392,
  //              0.9165,  0.0089
  VCMP_U16(7, v1, 0xbb1a, 0x34ae, 0x31d6, 0x33ed, 0xbc15, 0xb839, 0xbb4c,
           0x3919, 0xb730, 0x31d6, 0xb8af, 0xb49f, 0xad6c, 0xb91d, 0x3b55,
           0x208b);

  VSET(16, e32, m1);
  double dscalar_32;
  //                              -0.12857932
  BOX_FLOAT_IN_DOUBLE(dscalar_32, 0xbe03aa4c);
  //               0.31050768, -0.13843875,  0.23405042, -0.30545133,
  //               -0.28880060,  0.46233574, -0.51105869, -0.11776974,
  //               -0.39969075,  0.51141965,  0.88750082, -0.22310242,
  //               0.60111052,  0.58466393, -0.14306845, -0.01826003
  VLOAD_32(v2, 0x3e9efadd, 0xbe0dc2e3, 0x3e6faaea, 0xbe9c641e, 0xbe93ddac,
           0x3eecb745, 0xbf02d4be, 0xbdf13143, 0xbecca444, 0x3f02ec66,
           0x3f633341, 0xbe6474f6, 0x3f19e261, 0x3f15ac89, 0xbe128089,
           0xbc95960e);
  //              -0.51789892,  0.77328473, -0.88433731,  0.40865302,
  //              -0.50454420,  0.30827177, -0.25503114,  0.07736996,
  //              0.20596179, -0.42633566,  0.89622146,  0.03779412, 0.50878429,
  //              0.67896879, -0.17667305,  0.06984760
  VLOAD_32(v1, 0xbf049506, 0x3f45f5fd, 0xbf6263ee, 0x3ed13af8, 0xbf0129cf,
           0x3e9dd5cc, 0xbe829371, 0x3d9e7424, 0x3e52e7a6, 0xbeda48ab,
           0x3f656ec5, 0x3d1ace01, 0x3f023fb0, 0x3f2dd0e6, 0xbe34e9c8,
           0x3d8f0c42);
  asm volatile("vfmsub.vf v1, %[A], v2" ::[A] "f"(dscalar_32));
  //              -0.24391660,  0.03901032, -0.12034293,  0.25290701,
  //              0.35367453, -0.50197309,  0.54385042,  0.10782156, 0.37320831,
  //              -0.45660171, -1.00273633,  0.21824288, -0.66652966,
  //              -0.67196524,  0.16578496,  0.00927907
  VCMP_U32(8, v1, 0xbe79c546, 0x3d1fc94a, 0xbdf6765b, 0x3e817d07, 0x3eb514d5,
           0xbf00814f, 0x3f0b39c8, 0x3ddcd18d, 0x3ebf1529, 0xbee9c7b3,
           0xbf8059aa, 0x3e5f7b10, 0xbf2aa1b0, 0xbf2c05eb, 0x3e29c388,
           0x3c18073f);

  VSET(16, e64, m1);
  double dscalar_64;
  //                               -0.6953502965951812
  BOX_DOUBLE_IN_DOUBLE(dscalar_64, 0xbfe6404f43e47c8c);
  //               -0.8873182146436771,  0.3913246153259273, 0.8941416868753180,
  //               0.2630283463166789, -0.8096670634564123,  0.6449486037845993,
  //               0.8384405697279889, -0.9956067461953679, -0.8936777193492917,
  //               -0.4464070291333477,  0.5599998966835931,
  //               -0.3406088963725078,  0.4908382567748615,
  //               -0.5194254665571632,  0.0909287222245825,  0.5893410930389467
  VLOAD_64(v2, 0xbfec64e92b21453c, 0x3fd90b76663c74f4, 0x3fec9ccf06e3d51a,
           0x3fd0d574d8567864, 0xbfe9e8cae6c6325c, 0x3fe4a36b411b6206,
           0x3fead4815153e1da, 0xbfefdc02add2c126, 0xbfec990204389c42,
           0xbfdc91eec9b5438c, 0x3fe1eb84e7409f04, 0xbfd5cc8941a96178,
           0x3fdf69e4dd1e50c8, 0xbfe09f2227f25264, 0x3fb7471ad038be10,
           0x3fe2dbe1da195142);
  //               -0.4387964890891065, -0.2425720412460179,
  //               -0.8909058709916624, -0.7961584351708695, 0.0353694444236163,
  //               0.2992862865812480, -0.4186756300648600, -0.5421957392048740,
  //               0.3780444269462682, -0.6731508364205383,  0.1263808806166760,
  //               0.8571806635726140,  0.5149747658358419,  0.3530123248386567,
  //               -0.3756405874818076, -0.4529815298587780
  VLOAD_64(v1, 0xbfdc153dde8f3078, 0xbfcf0c99c409ad98, 0xbfec824d0777279c,
           0xbfe97a21412fca1a, 0x3fa21bf19e277c80, 0x3fd32781ab407ee0,
           0xbfdacb94deb0b06c, 0xbfe159aae0fd4b9a, 0x3fd831e1408ad588,
           0xbfe58a739f7670b4, 0x3fc02d3faa8b4d88, 0x3feb6e062499dac6,
           0x3fe07aac5c30f764, 0x3fd697c1019115dc, 0xbfd80a7ed19236bc,
           0xbfdcfda63e1bdf38);
  asm volatile("vfmsub.vf v1, %[A], v2" ::[A] "f"(dscalar_64));
  //               1.1924354834767115, -0.2226520744998102, -0.2746500252428773,
  //               0.2905806577161405,  0.7850729097860438, -0.8530574119257405,
  //               -0.5473143461852141,  1.3726227142641205, 0.6308044149460488,
  //               0.9144826628916634, -0.6478788795043589, -0.2554319322783636,
  //               -0.8489261129378481,  0.2739582417788488, 0.1702730716940806,
  //               -0.2743602518995064
  VCMP_U64(9, v1, 0x3ff314373ac1f573, 0xbfcc7fdcf92e7eaa, 0xbfd193ddb310e0ff,
           0x3fd298df9d6f6c70, 0x3fe91f5139103634, 0xbfeb4c3f0eba9b49,
           0xbfe18399602fe862, 0x3ff5f6433c382dac, 0x3fe42f8cbd8bb3c3,
           0x3fed4371253c1e34, 0xbfe4bb6c7ce7b0ea, 0xbfd058ff2cdf5691,
           0xbfeb2a6718793b11, 0x3fd18888263a3a6e, 0x3fc5cb820d286398,
           0xbfd18f1e4d4ec3d2);
};

// Simple random test with similar values (vector-scalar) (masked)
void TEST_CASE4(void) {
  VSET(16, e16, m1);
  double dscalar_16;
  //                              0.1489
  BOX_HALF_IN_DOUBLE(dscalar_16, 0x30c4);
  //                0.8530, -0.3298, -0.1814, -0.2385,  0.9946,  0.6553, 0.8711,
  //                -0.6377,  0.4224, -0.1814,  0.7026,  0.2852,  0.0553,
  //                0.7349, -0.8105,  0.0033
  VLOAD_16(v2, 0x3ad3, 0xb547, 0xb1ce, 0xb3a2, 0x3bf5, 0x393e, 0x3af8, 0xb91a,
           0x36c2, 0xb1ce, 0x399f, 0x3490, 0x2b15, 0x39e1, 0xba7c, 0x1abd);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               -0.2338, -0.2512,  0.0069,  0.0613, -0.1733,  0.8560,
  //               -0.2766, -0.0028, -0.1803,  0.0069,  0.7856, -0.0243,
  //               -0.1974,  0.6416,  0.7109,  0.0817
  VLOAD_16(v1, 0xb37b, 0xb405, 0x1f06, 0x2bd8, 0xb18c, 0x3ad9, 0xb46d, 0x99d2,
           0xb1c5, 0x1f06, 0x3a49, 0xa639, 0xb251, 0x3922, 0x39b0, 0x2d3a);
  asm volatile("vfmsub.vf v1, %[A], v2, v0.t" ::[A] "f"(dscalar_16));
  //               -0.2338,  0.2925,  0.0069,  0.2477, -0.1733, -0.5278,
  //               -0.2766,  0.6372, -0.1803,  0.1824,  0.7856, -0.2888,
  //               -0.1974, -0.6392,  0.7109,  0.0089
  VCMP_U16(10, v1, 0xb37b, 0x34ae, 0x1f06, 0x33ed, 0xb18c, 0xb839, 0xb46d,
           0x3919, 0xb1c5, 0x31d6, 0x3a49, 0xb49f, 0xb251, 0xb91d, 0x39b0,
           0x208b);

  VSET(16, e32, m1);
  double dscalar_32;
  //                              -0.12857932
  BOX_FLOAT_IN_DOUBLE(dscalar_32, 0xbe03aa4c);
  //                0.31050768, -0.13843875,  0.23405042, -0.30545133,
  //                -0.28880060,  0.46233574, -0.51105869, -0.11776974,
  //                -0.39969075,  0.51141965,  0.88750082, -0.22310242,
  //                0.60111052,  0.58466393, -0.14306845, -0.01826003
  VLOAD_32(v2, 0x3e9efadd, 0xbe0dc2e3, 0x3e6faaea, 0xbe9c641e, 0xbe93ddac,
           0x3eecb745, 0xbf02d4be, 0xbdf13143, 0xbecca444, 0x3f02ec66,
           0x3f633341, 0xbe6474f6, 0x3f19e261, 0x3f15ac89, 0xbe128089,
           0xbc95960e);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               -0.51789892,  0.77328473, -0.88433731,  0.40865302,
  //               -0.50454420,  0.30827177, -0.25503114,  0.07736996,
  //               0.20596179, -0.42633566,  0.89622146,  0.03779412,
  //               0.50878429,  0.67896879, -0.17667305,  0.06984760
  VLOAD_32(v1, 0xbf049506, 0x3f45f5fd, 0xbf6263ee, 0x3ed13af8, 0xbf0129cf,
           0x3e9dd5cc, 0xbe829371, 0x3d9e7424, 0x3e52e7a6, 0xbeda48ab,
           0x3f656ec5, 0x3d1ace01, 0x3f023fb0, 0x3f2dd0e6, 0xbe34e9c8,
           0x3d8f0c42);
  asm volatile("vfmsub.vf v1, %[A], v2, v0.t" ::[A] "f"(dscalar_32));
  //               -0.51789892,  0.03901032, -0.88433731,  0.25290701,
  //               -0.50454420, -0.50197309, -0.25503114,  0.10782156,
  //               0.20596179, -0.45660171,  0.89622146,  0.21824288,
  //               0.50878429, -0.67196524, -0.17667305,  0.00927907
  VCMP_U32(11, v1, 0xbf049506, 0x3d1fc94a, 0xbf6263ee, 0x3e817d07, 0xbf0129cf,
           0xbf00814f, 0xbe829371, 0x3ddcd18d, 0x3e52e7a6, 0xbee9c7b3,
           0x3f656ec5, 0x3e5f7b10, 0x3f023fb0, 0xbf2c05eb, 0xbe34e9c8,
           0x3c18073f);

  VSET(16, e64, m1);
  double dscalar_64;
  //                               -0.6953502965951812
  BOX_DOUBLE_IN_DOUBLE(dscalar_64, 0xbfe6404f43e47c8c);
  //                -0.8873182146436771,  0.3913246153259273,
  //                0.8941416868753180,  0.2630283463166789,
  //                -0.8096670634564123,  0.6449486037845993,
  //                0.8384405697279889, -0.9956067461953679,
  //                -0.8936777193492917, -0.4464070291333477,
  //                0.5599998966835931, -0.3406088963725078, 0.4908382567748615,
  //                -0.5194254665571632,  0.0909287222245825, 0.5893410930389467
  VLOAD_64(v2, 0xbfec64e92b21453c, 0x3fd90b76663c74f4, 0x3fec9ccf06e3d51a,
           0x3fd0d574d8567864, 0xbfe9e8cae6c6325c, 0x3fe4a36b411b6206,
           0x3fead4815153e1da, 0xbfefdc02add2c126, 0xbfec990204389c42,
           0xbfdc91eec9b5438c, 0x3fe1eb84e7409f04, 0xbfd5cc8941a96178,
           0x3fdf69e4dd1e50c8, 0xbfe09f2227f25264, 0x3fb7471ad038be10,
           0x3fe2dbe1da195142);
  VLOAD_8(v0, 0xAA, 0xAA);
  //                -0.4387964890891065, -0.2425720412460179,
  //                -0.8909058709916624, -0.7961584351708695,
  //                0.0353694444236163,  0.2992862865812480,
  //                -0.4186756300648600, -0.5421957392048740,
  //                0.3780444269462682, -0.6731508364205383, 0.1263808806166760,
  //                0.8571806635726140,  0.5149747658358419, 0.3530123248386567,
  //                -0.3756405874818076, -0.4529815298587780
  VLOAD_64(v1, 0xbfdc153dde8f3078, 0xbfcf0c99c409ad98, 0xbfec824d0777279c,
           0xbfe97a21412fca1a, 0x3fa21bf19e277c80, 0x3fd32781ab407ee0,
           0xbfdacb94deb0b06c, 0xbfe159aae0fd4b9a, 0x3fd831e1408ad588,
           0xbfe58a739f7670b4, 0x3fc02d3faa8b4d88, 0x3feb6e062499dac6,
           0x3fe07aac5c30f764, 0x3fd697c1019115dc, 0xbfd80a7ed19236bc,
           0xbfdcfda63e1bdf38);
  asm volatile("vfmsub.vf v1, %[A], v2, v0.t" ::[A] "f"(dscalar_64));
  //               -0.4387964890891065, -0.2226520744998102,
  //               -0.8909058709916624,  0.2905806577161405, 0.0353694444236163,
  //               -0.8530574119257405,
  //               -0.4186756300648600,  1.3726227142641205, 0.3780444269462682,
  //               0.9144826628916634,  0.1263808806166760, -0.2554319322783636,
  //               0.5149747658358419,  0.2739582417788488, -0.3756405874818076,
  //               -0.2743602518995064
  VCMP_U64(12, v1, 0xbfdc153dde8f3078, 0xbfcc7fdcf92e7eaa, 0xbfec824d0777279c,
           0x3fd298df9d6f6c70, 0x3fa21bf19e277c80, 0xbfeb4c3f0eba9b49,
           0xbfdacb94deb0b06c, 0x3ff5f6433c382dac, 0x3fd831e1408ad588,
           0x3fed4371253c1e34, 0x3fc02d3faa8b4d88, 0xbfd058ff2cdf5691,
           0x3fe07aac5c30f764, 0x3fd18888263a3a6e, 0xbfd80a7ed19236bc,
           0xbfd18f1e4d4ec3d2);
};

int main(void) {
  enable_vec();
  enable_fp();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
