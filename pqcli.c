/*
 * Copyright (C) 2024 Bardia Moshiri
 * SPDX-License-Identifier: GPL-3.0+
 * Author: Bardia Moshiri <fakeshell@bardia.tech>
 */

#include "pq.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_func_valid(int func) {
    return func >= 1 && func <= 20;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s function_id input\n"
               "id 1: setPQMode, inputs: <0: standard mode, 1: vivid mode>\n"
               "id 2: enableBlueLight, inputs: <0: disable, 1: enable>\n"
               "id 3: setBlueLightStrength, inputs: <0-1000>\n"
               "id 4: enableChameleon, inputs: <0: disable, 1: enable>\n"
               "id 5: setChameleonStrength, inputs: <0-1000>\n"
               "id 6: setGammaIndex, inputs: <0-1000>\n"
               "id 7: setFeatureDisplayColor, inputs: <0: disable, 1: enable>\n"
               "id 8: setFeatureContentColor, inputs: <0: disable, 1: enable>\n"
               "id 9: setFeatureContentColorVideo, inputs: <0: disable, 1: enable>\n"
               "id 10: setFeatureSharpness, inputs: <0: disable, 1: enable>\n"
               "id 11: setFeatureDynamicContrast, inputs: <0: disable, 1: enable>\n"
               "id 12: setFeatureDynamicSharpness, inputs: <0: disable, 1: enable>\n"
               "id 13: setFeatureDisplayCcorr, inputs: <0: disable, 1: enable>\n"
               "id 14: setFeatureDisplayGamma, inputs: <0: disable, 1: enable>\n"
               "id 15: setFeatureDisplayOverDrive, inputs: <0: disable, 1: enable>\n"
               "id 16: setFeatureIsoAdaptiveSharpness, inputs: <0: disable, 1: enable>\n"
               "id 17: setFeatureUltraResolution, inputs: <0: disable, 1: enable>\n"
               "id 18: setFeatureVideoHdr, inputs: <0: disable, 1: enable>\n"
               "id 19: setGlobalPQSwitch, inputs: <0: disable, 1: enable>\n"
               "id 20: setGlobalPQStrength, inputs: <0-1000>\n", argv[0]);
        return 1;
    }

    int func = atoi(argv[1]);
    int input = atoi(argv[2]);

    if (is_func_valid(func)) {
        int ret = run_pq_hidl(func, input);

        if (ret != 0) {
           printf("None of the backends are available for PQ. Exiting.\n");
           return 1;
        } else {
           printf("Using HIDL backend\n");
        }
    } else {
        printf("Invalid function ID. Please check the usage and try again.\n");
        return 1;
    }

    return 0;
}
