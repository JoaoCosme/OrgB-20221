#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

#define N 50

void matrixMulti(int a[][N], int b[][N], int *res)
{
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            for(int k=0; k<N; ++k) 
                *(res + i + j) += a[i][k] * b[k][j];
}

int main(int argc, char *argv[])
{
    std::string csv_name = "something.csv";
    int iterations = 100;
    if(argc > 1)
    {
        csv_name = "../Data/";
        csv_name.append(argv[1]);
        csv_name.append(".csv");
        if(argc > 2)
            iterations = atoi(argv[2]);

        cout << csv_name<< endl;
        cout << iterations << endl;
    }
    
    
    int mat1[N][N] = {{0, 9794, 6087, 182, 423, 6807, 8529, 8767, 5404, 1628, 5877, 4111, 9591, 1277, 3624, 9568, 4439, 9144, 1712, 9871, 196, 9313, 6504, 520, 4341, 4998, 2055, 1892, 3058, 9672, 6333, 9418, 9466, 8771,9599, 6240, 5578, 8128, 5006, 981, 6107, 7234, 1444, 5697, 8510},

{1419, 0, 5265, 9301, 6915, 3328, 9171, 3462, 2640, 2026, 3981, 6980, 3376, 6035, 5223, 6433, 5707, 7907, 5851, 1524, 6677, 5449, 7763, 8606, 9928, 2769, 5939, 6035, 6354, 3734, 1731, 1216, 5152, 3347, 516, 8418, 3026, 6038, 1880, 5665, 8064, 5860, 8996, 7791, 1895},

{4218, 4223, 0, 3953, 2124, 6425, 1828, 5153, 1874, 9590, 3758, 8153, 8710, 6048, 4187, 5064, 9781, 2270, 6279, 1285, 1968, 3146, 9702, 4994, 5535, 1581, 658, 9950, 3793, 9654, 7740, 2039, 223, 1963, 5991, 2347, 4739, 7818, 3851, 6612, 3759, 7608, 1117, 2469, 3656},

{5303, 3884, 9788, 0, 3924, 162, 1072, 5892, 9659, 774, 885, 1545, 8706, 7894, 1495, 2498, 7547, 9234, 4536, 7770, 7548, 6878, 6468, 2287, 4695, 318, 5250, 8454, 4277, 6366, 7274, 4284, 8021, 1157,4072, 1944, 7670, 5143, 4187, 3680, 2268, 5071, 5224, 974, 9317},

{6718, 9823, 6863, 2304, 0, 4359, 984, 6203, 1236, 3803, 8489, 2283, 4120, 91, 7088, 4749, 2808, 713, 9032, 7180, 1869, 3103, 9124, 5890, 4598, 3310, 9569, 3217, 4733, 1144, 4190, 4049, 4214, 4013,7263, 6517, 4723, 4599, 9071, 2310, 8401, 3912, 944, 8873, 4002},

{4383, 3621, 3161, 5095, 9004, 0, 341, 3315, 8459, 5816, 9204, 3056, 9125, 5124, 2624, 209, 2620, 6814, 609, 6833, 7178, 7872, 9701, 8252, 8822, 8771, 6913, 7222, 2682, 7857, 2446, 6683, 2239, 2418, 6196, 7334, 7774, 6536, 7000, 6232, 2351, 2556, 5639, 7827, 7679},

{8262, 4388, 6650, 1427, 4996, 3482, 0, 8604, 9219, 3182, 3207, 8040, 1953, 120, 1614, 4634, 7976,4059, 7669, 6566, 2829, 216, 251, 602, 6751, 7251, 3185, 5453, 9806, 8823, 3279, 3836, 7084, 7666,486, 4863, 2662, 3967, 9818, 8232, 3501, 3025, 6272, 1805, 9496},

{7885, 2790, 7471, 8295, 6810, 388, 7475, 0, 7025, 639, 8076, 3775, 4241, 1260, 9227, 4046, 6434, 8858, 4233, 9870, 6523, 4718, 4732, 5536, 5037, 4549, 3768, 4889, 7573, 6391, 6693, 7068, 627, 9482, 890, 8921, 6292, 7630, 2748, 3316, 4620, 7175, 3443, 8860, 4787},

{9021, 9257, 1220, 7878, 3489, 1089, 753, 4559, 0, 2172, 2640, 5947, 6721, 6407, 835, 645, 2797, 7527, 4065, 3423, 3360, 1306, 8696, 9651, 5287, 7795, 9319, 9906, 4969, 9113, 8765, 9755, 8133, 4373, 975, 2363, 4214, 8415, 3115, 5124, 6939, 5754, 1070, 3659, 8513},

{8256, 655, 7661, 2134, 1071, 7436, 5493, 8729, 2483, 0, 1496, 4015, 277, 7166, 3921, 5245, 6278, 9037, 5000, 762, 9762, 2326, 3124, 3975, 7092, 6238, 5450, 4030, 8344, 6519, 4040, 3208, 1126, 1047, 868, 3259, 2117, 4655, 5103, 7197, 7137, 6598, 1212, 3765, 115},

{1484, 9010, 6392, 6872, 361, 7154, 2985, 9038, 6629, 3311, 0, 6129, 9219, 8760, 6511, 3914, 5278,550, 7121, 2755, 7948, 4340, 6013, 6417, 8995, 1116, 3613, 6131, 4065, 1176, 9896, 4180, 9011, 5257, 571, 2235, 1969, 4076, 5219, 1006, 7057, 8530, 7134, 6275, 3641},

{9996, 188, 8919, 546, 7308, 1673, 4845, 1647, 4038, 1261, 6993, 0, 5153, 4874, 9476, 9217, 6049, 5723, 3396, 1412, 979, 319, 3646, 2947, 746, 8864, 3952, 7802, 3745, 7437, 428, 7386, 7433, 615, 2656, 4330, 4274, 680, 9174, 2273, 4717, 435, 9265, 6221, 1660},

{8740, 1790, 4060, 4462, 5185, 5471, 1792, 1855, 9116, 4738, 8953, 4332, 0, 5041, 6754, 4428, 8830, 3534, 1813, 2614, 4148, 820, 6943, 4774, 7852, 2468, 7046, 2568, 2902, 2662, 5141, 4561, 1402, 6930, 4973, 2215, 8466, 443, 4007, 6673, 5911, 5096, 5625, 6594, 6489},

{8730, 1021, 1670, 2263, 9186, 4283, 2763, 5, 1225, 7536, 7856, 3692, 933, 0, 6776, 2946, 3594, 8268, 3858, 1347, 5197, 8830, 9914, 14, 5625, 272, 6686, 1535, 1719, 8662, 8128, 8207, 7392, 9148, 6228, 9654, 8333, 510, 2416, 4690, 8086, 6303, 8897, 1778, 7235},

{5672, 1075, 7181, 291, 4932, 4879, 1839, 114, 4792, 1853, 5738, 1415, 4890, 3624, 0, 3134, 3552, 1751, 7692, 943, 7250, 3920, 6948, 1935, 4429, 5716, 6624, 2515, 2018, 1872, 644, 5605, 3896, 1718,9137, 4186, 3001, 367, 6025, 9466, 5159, 7877, 5203, 2925, 9118},

{8826, 6058, 2669, 6928, 3750, 9963, 4178, 4021, 6911, 2464, 8449, 8978, 5439, 7315, 7347, 0, 7310, 4310, 9303, 1205, 2379, 8439, 5391, 5380, 5158, 7767, 4845, 316, 1995, 6400, 9592, 1112, 1577, 5650, 3781, 8505, 5751, 95, 9034, 9771, 3357, 1497, 4571, 2334, 6935},

{8238, 9681, 596, 2547, 8983, 1801, 4926, 3774, 3543, 6657, 8931, 1309, 7853, 5598, 9655, 4252, 0,5189, 766, 2181, 7190, 898, 7037, 2940, 993, 6070, 9062, 701, 3918, 3633, 3035, 852, 8222, 9067, 1447, 768, 4401, 9599, 2045, 8174, 9493, 8701, 3456, 7153, 2906},

{9053, 6807, 3509, 594, 7573, 5689, 7783, 4822, 2725, 7075, 2166, 5146, 6136, 2867, 9063, 6120, 2253, 0, 6266, 4341, 1319, 4065, 1461, 5719, 3663, 9857, 3893, 3156, 4910, 3700, 308, 7815, 9105, 7115, 1323, 9698, 1039, 3364, 3832, 2212, 2440, 7258, 4378, 7586, 9746},

{3596, 6648, 2217, 5848, 2914, 2910, 7166, 6978, 4370, 2884, 6992, 4226, 3128, 147, 9135, 3180, 6807, 3301, 0, 2284, 273, 4624, 8333, 7663, 4339, 2164, 9874, 6778, 5774, 603, 4363, 5519, 4198, 7363, 7735, 6397, 276, 644, 3562, 3605, 1365, 2798, 596, 1943, 2277},

{7095, 7429, 5456, 3901, 730, 7739, 525, 1705, 6071, 8187, 6043, 4587, 4412, 2820, 360, 5015, 3535, 2230, 5564, 0, 897, 6316, 1961, 7524, 6960, 1874, 1128, 4676, 4671, 8075, 6618, 3300, 5169, 4047,8755, 5421, 1128, 2846, 2297, 2832, 8916, 483, 5226, 9854, 4895},

{4397, 6565, 6261, 7931, 8794, 1824, 8827, 5110, 136, 2702, 8421, 2010, 3829, 9448, 3032, 1904, 6066, 6331, 3424, 6464, 0, 1438, 5197, 7591, 4283, 7493, 6774, 9550, 4328, 1999, 9404, 5574, 6395, 2320, 1834, 4326, 1114, 9, 9504, 2575, 145, 2206, 7347, 8506, 2386},

{6794, 1537, 641, 9211, 7868, 417, 5674, 9305, 5613, 9616, 9939, 9457, 6389, 9488, 136, 8387, 5243, 5709, 1134, 7563, 3894, 0, 5459, 5028, 3903, 1314, 3954, 399, 9871, 1300, 8904, 8609, 4445, 6792,9249, 3656, 4659, 6017, 9329, 315, 7981, 5297, 6605, 7438, 1685},

{2445, 7573, 6424, 7687, 3282, 7557, 1601, 3527, 9367, 2980, 3781, 7032, 3285, 4179, 6903, 4584, 9434, 1863, 5381, 6226, 1111, 9036, 0, 7236, 7128, 4716, 3903, 5108, 12, 507, 8897, 8049, 2951, 2822, 4472, 6990, 2455, 8380, 4942, 5981, 7746, 7922, 9762, 4777, 1206},

{3940, 8031, 2142, 9726, 9893, 7522, 2303, 7356, 2909, 9538, 835, 7624, 9792, 2294, 3988, 299, 1191, 2036, 9601, 4012, 2859, 6590, 6466, 0, 1238, 7884, 8798, 8983, 5805, 8559, 111, 3362, 8851, 8142, 1855, 8576, 4386, 5728, 878, 1741, 8636, 6767, 2575, 2612, 6559},

{1221, 2951, 3209, 2411, 1338, 2809, 2774, 4196, 5751, 5591, 5433, 3634, 4388, 767, 9438, 9299, 7229, 9151, 8149, 1722, 7358, 3076, 6108, 3085, 0, 3953, 4200, 8073, 7071, 3127, 7036, 3629, 4347, 9986, 6837, 3109, 1323, 9646, 2234, 1870, 5396, 7824, 3654, 9029, 8563},

{4420, 4818, 7861, 8000, 320, 2361, 9722, 7677, 5436, 5829, 7114, 5740, 28, 1538, 2811, 9506, 8573, 6439, 3852, 4910, 9628, 6960, 2584, 5625, 9193, 0, 4453, 7372, 3368, 8106, 2752, 8283, 8877, 7569, 2495, 6876, 4240, 4856, 2949, 8269, 6643, 8777, 1734, 2383, 5157},

{3271, 1545, 4662, 8195, 4335, 4866, 3104, 3962, 8177, 5687, 5938, 7370, 6491, 3309, 7089, 4596, 6060, 5371, 9824, 9980, 7866, 6699, 4220, 9073, 9648, 8840, 0, 5715, 4776, 573, 4449, 6284, 195, 2345, 7298, 8389, 6680, 2163, 1492, 6993, 339, 3530, 2931, 4060, 20},

{6239, 1149, 967, 2299, 2871, 790, 2278, 736, 3840, 2849, 6160, 3487, 8040, 8227, 4615, 8612, 2675, 7250, 8806, 5020, 4547, 3546, 8051, 3061, 5037, 5043, 9752, 0, 4918, 7973, 163, 4937, 564, 1311, 5903, 9214, 534, 6692, 1491, 7621, 532, 692, 3781, 370, 8731},

{2007, 1336, 3695, 1033, 8586, 8852, 6052, 9484, 2398, 454, 2545, 7434, 5497, 8648, 2352, 9821, 8810, 3640, 6736, 6473, 9543, 5949, 7006, 2586, 3792, 4626, 9469, 4483, 0, 8406, 6191, 9565, 6764, 7526, 3259, 7797, 6111, 2111, 200, 1947, 4508, 654, 843, 8293, 2502},

{9490, 6996, 8674, 8299, 636, 5410, 1123, 6530, 1358, 8128, 5467, 5149, 2754, 4936, 5983, 7511, 1126, 5548, 4275, 5003, 5158, 8423, 7466, 7268, 8622, 9412, 8127, 5627, 254, 0, 6420, 4480, 9743, 9767, 3154, 4393, 6754, 8563, 5516, 3283, 6272, 9995, 5102, 7773, 2748},

{37, 3755, 6611, 7514, 5654, 7237, 2516, 7164, 5659, 9981, 4431, 632, 5744, 8910, 2611, 5997, 1681, 7090, 2091, 1447, 6595, 2836, 8201, 5157, 4703, 7835, 7781, 4697, 2936, 5553, 0, 3797, 9324, 5659, 407, 3189, 7665, 3995, 2057, 4828, 6005, 8389, 5610, 2988, 4133},

{4519, 5598, 6481, 2551, 9040, 4924, 3998, 5634, 7759, 8550, 7143, 2461, 2736, 1275, 7157, 2024, 3179, 7305, 7699, 8837, 7711, 888, 2853, 8057, 9296, 4032, 4061, 7684, 9642, 3401, 1816, 0, 512, 5350, 4649, 3063, 4389, 9572, 3412, 6375, 7330, 8313, 3517, 6142, 1048},

{4791, 9650, 9423, 7969, 6955, 7122, 3157, 1017, 4361, 2362, 9074, 3656, 6393, 9486, 7691, 6034, 2886, 5859, 2898, 8236, 507, 5960, 8976, 78, 5723, 5350, 3759, 4035, 8866, 9900, 5082, 8, 0, 9549, 857, 4328, 2855, 7978, 7485, 3872, 8690, 9846, 2945, 2345, 2590},

{8782, 35, 8624, 8020, 5893, 7873, 6255, 2751, 3832, 1582, 9180, 5906, 6932, 2938, 9940, 2149, 9189, 1373, 2157, 5090, 2229, 6484, 7944, 6558, 320, 8167, 5247, 6517, 1111, 7591, 9107, 6245, 3978, 0, 4082, 4264, 6222, 1954, 6870, 5325, 2137, 8451, 4504, 8042, 5382},

{7442, 7981, 7531, 2982, 5705, 6039, 8071, 7934, 8874, 2367, 4491, 5546, 533, 9738, 2062, 7996, 3680, 7520, 4240, 4009, 1601, 4855, 6583, 9906, 1724, 1907, 2042, 174, 6410, 83, 1908, 203, 4415, 9438, 0, 3185, 120, 1828, 7607, 8053, 7053, 6325, 8895, 2598, 6858},

{4984, 1012, 1205, 5016, 8531, 1796, 9024, 6484, 6650, 5606, 6389, 8373, 3864, 4783, 4898, 274, 1217, 6805, 6828, 5632, 2594, 6364, 5751, 773, 323, 155, 7826, 6647, 5401, 423, 9856, 385, 7786, 1060, 5400, 0, 2669, 9207, 775, 5504, 5856, 2733, 8244, 580, 6596},

{3026, 5478, 3221, 4243, 8634, 6401, 6226, 1228, 2764, 8328, 8352, 9438, 8482, 6177, 6085, 234, 2952, 2292, 618, 737, 9704, 2369, 9757, 8910, 9496, 5260, 4766, 2228, 3504, 1697, 8823, 6529, 7174, 8396, 7123, 2160, 0, 4796, 3348, 9739, 7559, 1675, 8090, 6997, 6508},

{4267, 9433, 3094, 3570, 1724, 63, 658, 7779, 2432, 415, 6689, 1927, 5674, 7806, 506, 9177, 9502, 9328, 2058, 3028, 7723, 9180, 5187, 2518, 8880, 4925, 6429, 6906, 3014, 9777, 9766, 3632, 5561, 2859, 7201, 3636, 2921, 0, 7859, 1415, 5352, 8273, 8103, 3630, 298},

{2260, 4135, 5827, 1761, 9815, 7884, 4788, 3889, 3415, 9974, 2759, 8646, 4898, 9187, 5552, 4264, 5315, 5317, 7895, 875, 8175, 5096, 4510, 1095, 9306, 5924, 2799, 3930, 378, 2780, 4227, 2637, 3267, 53, 4398, 3081, 4288, 5537, 0, 3321, 7703, 5511, 6079, 6348, 6760},

{5265, 1899, 7375, 6931, 3567, 5270, 7805, 1741, 6717, 8667, 9188, 2374, 942, 8338, 6303, 1320, 1117, 529, 308, 735, 6934, 1057, 167, 1221, 6594, 3488, 8923, 8456, 9566, 1623, 1567, 1183, 9873, 8942, 8113, 3440, 563, 2270, 1532, 0, 3631, 936, 7071, 6004, 1877},

{5408, 2306, 9548, 2877, 9186, 6208, 9963, 6119, 7264, 130, 7340, 209, 3617, 2614, 5016, 3182, 588, 2935, 716, 461, 8228, 8829, 252, 8790, 7450, 8135, 8772, 8385, 5206, 4775, 6613, 6965, 3432, 2513, 6193, 2617, 8720, 6156, 5088, 2335, 0, 2637, 8779, 8896, 6253},

{1392, 3911, 5786, 8332, 3197, 6502, 8792, 1424, 1682, 5395, 6565, 9131, 3529, 5336, 3867, 5086, 110, 479, 8403, 9893, 9343, 4595, 2510, 4414, 7102, 3949, 3101, 9738, 2727, 1996, 2342, 470, 2258, 8128, 8801, 5455, 4629, 7592, 3230, 6310, 9338, 0, 9795, 1792, 2867},

{5130, 5658, 4304, 1592, 2488, 2706, 1484, 1831, 7301, 345, 2596, 754, 4293, 5696, 6844, 7019, 4043, 9185, 7489, 2653, 7312, 6289, 4459, 8292, 233, 7688, 953, 9570, 7482, 2744, 8788, 2612, 4753, 3092, 555, 7241, 5797, 2038, 5423, 9449, 2383, 8018, 0, 6555, 3027},

{66, 3398, 46, 460, 2582, 3886, 3112, 6246, 174, 3922, 889, 6758, 1610, 8194, 6328, 5443, 7289, 1467, 4406, 2042, 4558, 4960, 9282, 6707, 6998, 1056, 6155, 5732, 9073, 2709, 8758, 5490, 2458, 8803,5950, 5040, 9040, 9061, 7637, 9214, 9335, 4877, 5971, 0, 944},

{3070, 8650, 6386, 359, 117, 792, 8752, 1026, 2103, 4385, 7732, 9100, 5440, 239, 1183, 4512, 9299,9941, 2, 1757, 5095, 2303, 6796, 4135, 7715, 784, 9700, 7049, 5660, 2022, 7992, 8730, 672, 730, 5440, 7140, 7873, 4191, 8165, 9975, 4927, 2249, 5427, 366, 0}}; 

    int mat2[N][N] = {{0, 9794, 6087, 182, 423, 6807, 8529, 8767, 5404, 1628, 5877, 4111, 9591, 1277, 3624, 9568, 4439, 9144, 1712, 9871, 196, 9313, 6504, 520, 4341, 4998, 2055, 1892, 3058, 9672, 6333, 9418, 9466, 8771,9599, 6240, 5578, 8128, 5006, 981, 6107, 7234, 1444, 5697, 8510},

{1419, 0, 5265, 9301, 6915, 3328, 9171, 3462, 2640, 2026, 3981, 6980, 3376, 6035, 5223, 6433, 5707, 7907, 5851, 1524, 6677, 5449, 7763, 8606, 9928, 2769, 5939, 6035, 6354, 3734, 1731, 1216, 5152, 3347, 516, 8418, 3026, 6038, 1880, 5665, 8064, 5860, 8996, 7791, 1895},

{4218, 4223, 0, 3953, 2124, 6425, 1828, 5153, 1874, 9590, 3758, 8153, 8710, 6048, 4187, 5064, 9781, 2270, 6279, 1285, 1968, 3146, 9702, 4994, 5535, 1581, 658, 9950, 3793, 9654, 7740, 2039, 223, 1963, 5991, 2347, 4739, 7818, 3851, 6612, 3759, 7608, 1117, 2469, 3656},

{5303, 3884, 9788, 0, 3924, 162, 1072, 5892, 9659, 774, 885, 1545, 8706, 7894, 1495, 2498, 7547, 9234, 4536, 7770, 7548, 6878, 6468, 2287, 4695, 318, 5250, 8454, 4277, 6366, 7274, 4284, 8021, 1157,4072, 1944, 7670, 5143, 4187, 3680, 2268, 5071, 5224, 974, 9317},

{6718, 9823, 6863, 2304, 0, 4359, 984, 6203, 1236, 3803, 8489, 2283, 4120, 91, 7088, 4749, 2808, 713, 9032, 7180, 1869, 3103, 9124, 5890, 4598, 3310, 9569, 3217, 4733, 1144, 4190, 4049, 4214, 4013,7263, 6517, 4723, 4599, 9071, 2310, 8401, 3912, 944, 8873, 4002},

{4383, 3621, 3161, 5095, 9004, 0, 341, 3315, 8459, 5816, 9204, 3056, 9125, 5124, 2624, 209, 2620, 6814, 609, 6833, 7178, 7872, 9701, 8252, 8822, 8771, 6913, 7222, 2682, 7857, 2446, 6683, 2239, 2418, 6196, 7334, 7774, 6536, 7000, 6232, 2351, 2556, 5639, 7827, 7679},

{8262, 4388, 6650, 1427, 4996, 3482, 0, 8604, 9219, 3182, 3207, 8040, 1953, 120, 1614, 4634, 7976,4059, 7669, 6566, 2829, 216, 251, 602, 6751, 7251, 3185, 5453, 9806, 8823, 3279, 3836, 7084, 7666,486, 4863, 2662, 3967, 9818, 8232, 3501, 3025, 6272, 1805, 9496},

{7885, 2790, 7471, 8295, 6810, 388, 7475, 0, 7025, 639, 8076, 3775, 4241, 1260, 9227, 4046, 6434, 8858, 4233, 9870, 6523, 4718, 4732, 5536, 5037, 4549, 3768, 4889, 7573, 6391, 6693, 7068, 627, 9482, 890, 8921, 6292, 7630, 2748, 3316, 4620, 7175, 3443, 8860, 4787},

{9021, 9257, 1220, 7878, 3489, 1089, 753, 4559, 0, 2172, 2640, 5947, 6721, 6407, 835, 645, 2797, 7527, 4065, 3423, 3360, 1306, 8696, 9651, 5287, 7795, 9319, 9906, 4969, 9113, 8765, 9755, 8133, 4373, 975, 2363, 4214, 8415, 3115, 5124, 6939, 5754, 1070, 3659, 8513},

{8256, 655, 7661, 2134, 1071, 7436, 5493, 8729, 2483, 0, 1496, 4015, 277, 7166, 3921, 5245, 6278, 9037, 5000, 762, 9762, 2326, 3124, 3975, 7092, 6238, 5450, 4030, 8344, 6519, 4040, 3208, 1126, 1047, 868, 3259, 2117, 4655, 5103, 7197, 7137, 6598, 1212, 3765, 115},

{1484, 9010, 6392, 6872, 361, 7154, 2985, 9038, 6629, 3311, 0, 6129, 9219, 8760, 6511, 3914, 5278,550, 7121, 2755, 7948, 4340, 6013, 6417, 8995, 1116, 3613, 6131, 4065, 1176, 9896, 4180, 9011, 5257, 571, 2235, 1969, 4076, 5219, 1006, 7057, 8530, 7134, 6275, 3641},

{9996, 188, 8919, 546, 7308, 1673, 4845, 1647, 4038, 1261, 6993, 0, 5153, 4874, 9476, 9217, 6049, 5723, 3396, 1412, 979, 319, 3646, 2947, 746, 8864, 3952, 7802, 3745, 7437, 428, 7386, 7433, 615, 2656, 4330, 4274, 680, 9174, 2273, 4717, 435, 9265, 6221, 1660},

{8740, 1790, 4060, 4462, 5185, 5471, 1792, 1855, 9116, 4738, 8953, 4332, 0, 5041, 6754, 4428, 8830, 3534, 1813, 2614, 4148, 820, 6943, 4774, 7852, 2468, 7046, 2568, 2902, 2662, 5141, 4561, 1402, 6930, 4973, 2215, 8466, 443, 4007, 6673, 5911, 5096, 5625, 6594, 6489},

{8730, 1021, 1670, 2263, 9186, 4283, 2763, 5, 1225, 7536, 7856, 3692, 933, 0, 6776, 2946, 3594, 8268, 3858, 1347, 5197, 8830, 9914, 14, 5625, 272, 6686, 1535, 1719, 8662, 8128, 8207, 7392, 9148, 6228, 9654, 8333, 510, 2416, 4690, 8086, 6303, 8897, 1778, 7235},

{5672, 1075, 7181, 291, 4932, 4879, 1839, 114, 4792, 1853, 5738, 1415, 4890, 3624, 0, 3134, 3552, 1751, 7692, 943, 7250, 3920, 6948, 1935, 4429, 5716, 6624, 2515, 2018, 1872, 644, 5605, 3896, 1718,9137, 4186, 3001, 367, 6025, 9466, 5159, 7877, 5203, 2925, 9118},

{8826, 6058, 2669, 6928, 3750, 9963, 4178, 4021, 6911, 2464, 8449, 8978, 5439, 7315, 7347, 0, 7310, 4310, 9303, 1205, 2379, 8439, 5391, 5380, 5158, 7767, 4845, 316, 1995, 6400, 9592, 1112, 1577, 5650, 3781, 8505, 5751, 95, 9034, 9771, 3357, 1497, 4571, 2334, 6935},

{8238, 9681, 596, 2547, 8983, 1801, 4926, 3774, 3543, 6657, 8931, 1309, 7853, 5598, 9655, 4252, 0,5189, 766, 2181, 7190, 898, 7037, 2940, 993, 6070, 9062, 701, 3918, 3633, 3035, 852, 8222, 9067, 1447, 768, 4401, 9599, 2045, 8174, 9493, 8701, 3456, 7153, 2906},

{9053, 6807, 3509, 594, 7573, 5689, 7783, 4822, 2725, 7075, 2166, 5146, 6136, 2867, 9063, 6120, 2253, 0, 6266, 4341, 1319, 4065, 1461, 5719, 3663, 9857, 3893, 3156, 4910, 3700, 308, 7815, 9105, 7115, 1323, 9698, 1039, 3364, 3832, 2212, 2440, 7258, 4378, 7586, 9746},

{3596, 6648, 2217, 5848, 2914, 2910, 7166, 6978, 4370, 2884, 6992, 4226, 3128, 147, 9135, 3180, 6807, 3301, 0, 2284, 273, 4624, 8333, 7663, 4339, 2164, 9874, 6778, 5774, 603, 4363, 5519, 4198, 7363, 7735, 6397, 276, 644, 3562, 3605, 1365, 2798, 596, 1943, 2277},

{7095, 7429, 5456, 3901, 730, 7739, 525, 1705, 6071, 8187, 6043, 4587, 4412, 2820, 360, 5015, 3535, 2230, 5564, 0, 897, 6316, 1961, 7524, 6960, 1874, 1128, 4676, 4671, 8075, 6618, 3300, 5169, 4047,8755, 5421, 1128, 2846, 2297, 2832, 8916, 483, 5226, 9854, 4895},

{4397, 6565, 6261, 7931, 8794, 1824, 8827, 5110, 136, 2702, 8421, 2010, 3829, 9448, 3032, 1904, 6066, 6331, 3424, 6464, 0, 1438, 5197, 7591, 4283, 7493, 6774, 9550, 4328, 1999, 9404, 5574, 6395, 2320, 1834, 4326, 1114, 9, 9504, 2575, 145, 2206, 7347, 8506, 2386},

{6794, 1537, 641, 9211, 7868, 417, 5674, 9305, 5613, 9616, 9939, 9457, 6389, 9488, 136, 8387, 5243, 5709, 1134, 7563, 3894, 0, 5459, 5028, 3903, 1314, 3954, 399, 9871, 1300, 8904, 8609, 4445, 6792,9249, 3656, 4659, 6017, 9329, 315, 7981, 5297, 6605, 7438, 1685},

{2445, 7573, 6424, 7687, 3282, 7557, 1601, 3527, 9367, 2980, 3781, 7032, 3285, 4179, 6903, 4584, 9434, 1863, 5381, 6226, 1111, 9036, 0, 7236, 7128, 4716, 3903, 5108, 12, 507, 8897, 8049, 2951, 2822, 4472, 6990, 2455, 8380, 4942, 5981, 7746, 7922, 9762, 4777, 1206},

{3940, 8031, 2142, 9726, 9893, 7522, 2303, 7356, 2909, 9538, 835, 7624, 9792, 2294, 3988, 299, 1191, 2036, 9601, 4012, 2859, 6590, 6466, 0, 1238, 7884, 8798, 8983, 5805, 8559, 111, 3362, 8851, 8142, 1855, 8576, 4386, 5728, 878, 1741, 8636, 6767, 2575, 2612, 6559},

{1221, 2951, 3209, 2411, 1338, 2809, 2774, 4196, 5751, 5591, 5433, 3634, 4388, 767, 9438, 9299, 7229, 9151, 8149, 1722, 7358, 3076, 6108, 3085, 0, 3953, 4200, 8073, 7071, 3127, 7036, 3629, 4347, 9986, 6837, 3109, 1323, 9646, 2234, 1870, 5396, 7824, 3654, 9029, 8563},

{4420, 4818, 7861, 8000, 320, 2361, 9722, 7677, 5436, 5829, 7114, 5740, 28, 1538, 2811, 9506, 8573, 6439, 3852, 4910, 9628, 6960, 2584, 5625, 9193, 0, 4453, 7372, 3368, 8106, 2752, 8283, 8877, 7569, 2495, 6876, 4240, 4856, 2949, 8269, 6643, 8777, 1734, 2383, 5157},

{3271, 1545, 4662, 8195, 4335, 4866, 3104, 3962, 8177, 5687, 5938, 7370, 6491, 3309, 7089, 4596, 6060, 5371, 9824, 9980, 7866, 6699, 4220, 9073, 9648, 8840, 0, 5715, 4776, 573, 4449, 6284, 195, 2345, 7298, 8389, 6680, 2163, 1492, 6993, 339, 3530, 2931, 4060, 20},

{6239, 1149, 967, 2299, 2871, 790, 2278, 736, 3840, 2849, 6160, 3487, 8040, 8227, 4615, 8612, 2675, 7250, 8806, 5020, 4547, 3546, 8051, 3061, 5037, 5043, 9752, 0, 4918, 7973, 163, 4937, 564, 1311, 5903, 9214, 534, 6692, 1491, 7621, 532, 692, 3781, 370, 8731},

{2007, 1336, 3695, 1033, 8586, 8852, 6052, 9484, 2398, 454, 2545, 7434, 5497, 8648, 2352, 9821, 8810, 3640, 6736, 6473, 9543, 5949, 7006, 2586, 3792, 4626, 9469, 4483, 0, 8406, 6191, 9565, 6764, 7526, 3259, 7797, 6111, 2111, 200, 1947, 4508, 654, 843, 8293, 2502},

{9490, 6996, 8674, 8299, 636, 5410, 1123, 6530, 1358, 8128, 5467, 5149, 2754, 4936, 5983, 7511, 1126, 5548, 4275, 5003, 5158, 8423, 7466, 7268, 8622, 9412, 8127, 5627, 254, 0, 6420, 4480, 9743, 9767, 3154, 4393, 6754, 8563, 5516, 3283, 6272, 9995, 5102, 7773, 2748},

{37, 3755, 6611, 7514, 5654, 7237, 2516, 7164, 5659, 9981, 4431, 632, 5744, 8910, 2611, 5997, 1681, 7090, 2091, 1447, 6595, 2836, 8201, 5157, 4703, 7835, 7781, 4697, 2936, 5553, 0, 3797, 9324, 5659, 407, 3189, 7665, 3995, 2057, 4828, 6005, 8389, 5610, 2988, 4133},

{4519, 5598, 6481, 2551, 9040, 4924, 3998, 5634, 7759, 8550, 7143, 2461, 2736, 1275, 7157, 2024, 3179, 7305, 7699, 8837, 7711, 888, 2853, 8057, 9296, 4032, 4061, 7684, 9642, 3401, 1816, 0, 512, 5350, 4649, 3063, 4389, 9572, 3412, 6375, 7330, 8313, 3517, 6142, 1048},

{4791, 9650, 9423, 7969, 6955, 7122, 3157, 1017, 4361, 2362, 9074, 3656, 6393, 9486, 7691, 6034, 2886, 5859, 2898, 8236, 507, 5960, 8976, 78, 5723, 5350, 3759, 4035, 8866, 9900, 5082, 8, 0, 9549, 857, 4328, 2855, 7978, 7485, 3872, 8690, 9846, 2945, 2345, 2590},

{8782, 35, 8624, 8020, 5893, 7873, 6255, 2751, 3832, 1582, 9180, 5906, 6932, 2938, 9940, 2149, 9189, 1373, 2157, 5090, 2229, 6484, 7944, 6558, 320, 8167, 5247, 6517, 1111, 7591, 9107, 6245, 3978, 0, 4082, 4264, 6222, 1954, 6870, 5325, 2137, 8451, 4504, 8042, 5382},

{7442, 7981, 7531, 2982, 5705, 6039, 8071, 7934, 8874, 2367, 4491, 5546, 533, 9738, 2062, 7996, 3680, 7520, 4240, 4009, 1601, 4855, 6583, 9906, 1724, 1907, 2042, 174, 6410, 83, 1908, 203, 4415, 9438, 0, 3185, 120, 1828, 7607, 8053, 7053, 6325, 8895, 2598, 6858},

{4984, 1012, 1205, 5016, 8531, 1796, 9024, 6484, 6650, 5606, 6389, 8373, 3864, 4783, 4898, 274, 1217, 6805, 6828, 5632, 2594, 6364, 5751, 773, 323, 155, 7826, 6647, 5401, 423, 9856, 385, 7786, 1060, 5400, 0, 2669, 9207, 775, 5504, 5856, 2733, 8244, 580, 6596},

{3026, 5478, 3221, 4243, 8634, 6401, 6226, 1228, 2764, 8328, 8352, 9438, 8482, 6177, 6085, 234, 2952, 2292, 618, 737, 9704, 2369, 9757, 8910, 9496, 5260, 4766, 2228, 3504, 1697, 8823, 6529, 7174, 8396, 7123, 2160, 0, 4796, 3348, 9739, 7559, 1675, 8090, 6997, 6508},

{4267, 9433, 3094, 3570, 1724, 63, 658, 7779, 2432, 415, 6689, 1927, 5674, 7806, 506, 9177, 9502, 9328, 2058, 3028, 7723, 9180, 5187, 2518, 8880, 4925, 6429, 6906, 3014, 9777, 9766, 3632, 5561, 2859, 7201, 3636, 2921, 0, 7859, 1415, 5352, 8273, 8103, 3630, 298},

{2260, 4135, 5827, 1761, 9815, 7884, 4788, 3889, 3415, 9974, 2759, 8646, 4898, 9187, 5552, 4264, 5315, 5317, 7895, 875, 8175, 5096, 4510, 1095, 9306, 5924, 2799, 3930, 378, 2780, 4227, 2637, 3267, 53, 4398, 3081, 4288, 5537, 0, 3321, 7703, 5511, 6079, 6348, 6760},

{5265, 1899, 7375, 6931, 3567, 5270, 7805, 1741, 6717, 8667, 9188, 2374, 942, 8338, 6303, 1320, 1117, 529, 308, 735, 6934, 1057, 167, 1221, 6594, 3488, 8923, 8456, 9566, 1623, 1567, 1183, 9873, 8942, 8113, 3440, 563, 2270, 1532, 0, 3631, 936, 7071, 6004, 1877},

{5408, 2306, 9548, 2877, 9186, 6208, 9963, 6119, 7264, 130, 7340, 209, 3617, 2614, 5016, 3182, 588, 2935, 716, 461, 8228, 8829, 252, 8790, 7450, 8135, 8772, 8385, 5206, 4775, 6613, 6965, 3432, 2513, 6193, 2617, 8720, 6156, 5088, 2335, 0, 2637, 8779, 8896, 6253},

{1392, 3911, 5786, 8332, 3197, 6502, 8792, 1424, 1682, 5395, 6565, 9131, 3529, 5336, 3867, 5086, 110, 479, 8403, 9893, 9343, 4595, 2510, 4414, 7102, 3949, 3101, 9738, 2727, 1996, 2342, 470, 2258, 8128, 8801, 5455, 4629, 7592, 3230, 6310, 9338, 0, 9795, 1792, 2867},

{5130, 5658, 4304, 1592, 2488, 2706, 1484, 1831, 7301, 345, 2596, 754, 4293, 5696, 6844, 7019, 4043, 9185, 7489, 2653, 7312, 6289, 4459, 8292, 233, 7688, 953, 9570, 7482, 2744, 8788, 2612, 4753, 3092, 555, 7241, 5797, 2038, 5423, 9449, 2383, 8018, 0, 6555, 3027},

{66, 3398, 46, 460, 2582, 3886, 3112, 6246, 174, 3922, 889, 6758, 1610, 8194, 6328, 5443, 7289, 1467, 4406, 2042, 4558, 4960, 9282, 6707, 6998, 1056, 6155, 5732, 9073, 2709, 8758, 5490, 2458, 8803,5950, 5040, 9040, 9061, 7637, 9214, 9335, 4877, 5971, 0, 944},

{3070, 8650, 6386, 359, 117, 792, 8752, 1026, 2103, 4385, 7732, 9100, 5440, 239, 1183, 4512, 9299,9941, 2, 1757, 5095, 2303, 6796, 4135, 7715, 784, 9700, 7049, 5660, 2022, 7992, 8730, 672, 730, 5440, 7140, 7873, 4191, 8165, 9975, 4927, 2249, 5427, 366, 0}}; 

    int res[N][N];

    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point end;
    std::chrono::duration<float> duration;

    std::ofstream csv;
    csv.open(csv_name);
    csv << "iteration,time(ms)\n";
    for(int i = 0; i < iterations; i++){
        start = std::chrono::high_resolution_clock::now();

        matrixMulti(mat1, mat2, &res[0][0]);

        end = std::chrono::high_resolution_clock::now();
        
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        csv << to_string(i+1) + "," + to_string(ms) + "\n";
    }

    csv.close();
    return 0;
}