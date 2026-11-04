struct Band_001DD9B0 {
    float m_peak;
    float m_start;
    float m_end;
};

extern "C" float func_00341068(float);
extern Band_001DD9B0 D_00351CC8[5];

struct Obj_001DD9B0 {
    void GetWeights(float* out, float hue);
};

void Obj_001DD9B0::GetWeights(float* out, float hue)
{
    if (hue < 0.0f) hue += 360.0f;
    for (int i = 0; i < 5; i++) {
        Band_001DD9B0* b = &D_00351CC8[i];
        float start = b->m_start;
        float peak = b->m_peak;
        float end = b->m_end;
        float v = 0.0f;
        if (start < peak) {
            if (start < hue && hue <= peak) {
                v = (hue - start) / (peak - start);
            } else if (peak < hue && hue < end) {
                v = 1.0f - (hue - peak) / (end - peak);
            }
        } else {
            if (start < hue) {
                v = (hue - start) / (360.0f - start);
            } else if (hue < end) {
                v = (end - hue) / end;
            }
        }
        out[i] = func_00341068(v * 1.5707964f);
    }
}
