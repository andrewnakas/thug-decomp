struct State_00136178 {
    char pad[0x38];
    float m38;
    float m3C[2];
};

extern State_00136178 D_003BEB00;
extern float D_00389E1C;
extern float D_00389E20;
extern float D_00389E24;
extern float D_00389E28;
extern float D_00389E30[2];
extern "C" void func_0014AB90();

extern "C" int func_00136178(float t)
{
    D_00389E20 = t;
    if (D_00389E1C < t) {
        D_00389E1C += 0.02f;
        if (t < D_00389E1C)
            D_00389E1C = t;
    } else if (t < D_00389E1C) {
        D_00389E1C -= 0.02f;
        if (D_00389E1C < t)
            D_00389E1C = t;
    }
    float lo = D_00389E24;
    D_00389E28 = (D_00389E1C + D_00389E1C - 1.0f) * D_003BEB00.m38 + 1.0f;
    if (D_00389E28 < lo)
        D_00389E28 = lo;
    for (int i = 0; i < 2; i++) {
        D_00389E30[i] = (D_00389E1C + D_00389E1C - 1.0f) * D_003BEB00.m3C[i] + 1.0f;
        if (D_00389E30[i] < lo)
            D_00389E30[i] = lo;
    }
    func_0014AB90();
    return 1;
}
