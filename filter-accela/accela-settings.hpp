#pragma once

#include "options/options.hpp"
using namespace options;
#include "spline/spline.hpp"

// ------------------------------------
// debug knobs
// ------------------------------------

//#define DEBUG_ACCELA
//#define SPLINE_ROT_DEBUG
//#define SPLINE_TRANS_DEBUG

struct settings_accela : opts
{
    struct gains
    {
        double x, y;
    };

    static constexpr inline gains const rot_gains[16] =
    {
        { 9, 300 },
        { 8, 200 },
        { 5, 100 },
        { 2.5, 35 },
        { 1.5, 8 },
        { 1, 1.5 },
        { .5, .4 },
    };

    static constexpr inline gains const pos_gains[16] =
    {
        { 9, 200 },
        { 8, 150 },
        { 7, 110 },
        { 5, 60 },
        { 3, 24 },
        { 2, 7.5 },
        { 1.66, 4.5 },
        { 1.33, 2.25 },
        { .66, .75 },
        { .33, .375 },
        { 0, 0 },
    };

    static void make_splines(spline& rot, spline& pos);

    value<slider_value> rot_smoothing { b, "rotation-sensitivity", slider_value(1.5, .05, 2.5) },
                        pos_smoothing { b, "translation-sensitivity", slider_value(1., .05, 1.5) },
                        rot_deadzone { b, "rotation-deadzone", slider_value(.03, 0, .2) },
                        pos_deadzone { b, "translation-deadzone", slider_value(.1, 0, 1) };

    settings_accela() : opts("accela-sliders") {}
};
