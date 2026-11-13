struct Params_00197378 {
    int m0;
    int m4;
    char pad8[0xF0 - 0x8];
    float mF0;
    float mF4;
    float mF8;
    float mFC;
    float m100;
    float m104;
    float m108;
};

struct Obj_00197378 {
    char pad0[0x350];
    int m350;
    int m354;
    int m358;
    float GetSpeed(Params_00197378* p, float t);
};

float Obj_00197378::GetSpeed(Params_00197378* p, float t)
{
    if (m358) {
        float top;
        if (m350) {
            p->m4 = 6;
            top = p->m104;
        } else {
            p->m4 = 7;
            top = p->m108;
        }
        if (t < p->mF0) {
            p->m4 = 2;
            return top * t / p->mF0;
        }
        return top;
    }
    float k = 1.0f;
    if (m354) k = 2.0f;
    if (t < p->mF0) {
        p->m4 = 2;
        return p->mFC * t / p->mF0;
    }
    if (t < p->mF4) {
        p->m4 = 3;
        return k * p->mFC;
    }
    if (t < p->mF8) {
        p->m4 = 4;
        return k * p->m100 + (p->mFC - p->m100) * (t - p->mF4) / (p->mF8 - p->mF4);
    }
    p->m4 = 5;
    return k * p->m100;
}
