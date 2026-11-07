// Static initialiser (initialize, priority) for the vector tables at 0x00452230-0x00452ED0:
// five preset vectors, five all-ones colours (func_0025C388 later reloads them from script params),
// 96 {0,0,0,1} vectors and 96 vectors whose default constructor does nothing.
struct Vec4_0025EF50 {
    float x, y, z, w;
    Vec4_0025EF50() {}
    Vec4_0025EF50(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

inline void* operator new(unsigned int, void* p) { return p; }


extern Vec4_0025EF50 D_00452230[5];
extern Vec4_0025EF50 D_00452280[5];
extern Vec4_0025EF50 D_004522D0[96];
extern Vec4_0025EF50 D_004528D0[96];

extern "C" void func_0025EF50(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        Vec4_0025EF50* p = D_00452230;
        new (p) Vec4_0025EF50(0.0f, 0.0f, 0.0f, 1.0f);
        p++;
        new (p) Vec4_0025EF50(0.003875999944f, 3.697956085f, 1.117333055f, 1.0f);
        p++;
        new (p) Vec4_0025EF50(0.003871999914f, 4.297436237f, 2.893996f, 1.0f);
        p++;
        new (p) Vec4_0025EF50(0.003868000116f, 9.568744659f, 1.807595968f, 1.0f);
        p++;
        new (p) Vec4_0025EF50(0.003863000078f, 7.351618767f, 5.444900036f, 1.0f);
        Vec4_0025EF50* q = D_00452280;
        new (q) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        q++;
        new (q) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        q++;
        new (q) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        q++;
        new (q) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        q++;
        new (q) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        Vec4_0025EF50* r = D_004522D0;
        for (int i = 95; i != -1; i--, r++)
            new (r) Vec4_0025EF50(0.0f, 0.0f, 0.0f, 1.0f);
        p = D_004528D0;
        for (int i = 95; i != -1; i--, p++)
            new (p) Vec4_0025EF50();
    }
}
