/* fuzzy: 34.7 */
// Static initialiser (initialize, priority) for the vector tables at 0x00452230-0x00452ED0:
// five preset vectors, five all-ones colours (func_0025C388 later reloads them from script params),
// 96 {0,0,0,1} vectors and 96 vectors whose default constructor does nothing.
struct Vec4_0025EF50 {
    float x, y, z, w;
    Vec4_0025EF50() {}
    Vec4_0025EF50(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

inline void* operator new(unsigned int, void* p) { return p; }

// The game's .lit4 constants for the preset vectors (the compiler schedules the loads out of
// source order, so they are named instead of written as literals).
extern float D_00387DEC; // 0.00387599994
extern float D_00387DF0; // 3.69795609
extern float D_00387DF4; // 1.11733305
extern float D_00387DF8; // 0.00387199991
extern float D_00387DFC; // 4.29743624
extern float D_00387E00; // 2.893996
extern float D_00387E04; // 0.00386800012
extern float D_00387E08; // 9.56874466
extern float D_00387E0C; // 1.80759597
extern float D_00387E10; // 0.00386300008
extern float D_00387E14; // 7.35161877
extern float D_00387E18; // 5.44490004

extern Vec4_0025EF50 D_00452230[5];
extern Vec4_0025EF50 D_00452280[5];
extern Vec4_0025EF50 D_004522D0[96];
extern Vec4_0025EF50 D_004528D0[96];

extern "C" void func_0025EF50(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        new (&D_00452230[0]) Vec4_0025EF50(0.0f, 0.0f, 0.0f, 1.0f);
        new (&D_00452230[1]) Vec4_0025EF50(D_00387DEC, D_00387DF0, D_00387DF4, 1.0f);
        new (&D_00452230[2]) Vec4_0025EF50(D_00387DF8, D_00387DFC, D_00387E00, 1.0f);
        new (&D_00452230[3]) Vec4_0025EF50(D_00387E04, D_00387E08, D_00387E0C, 1.0f);
        new (&D_00452230[4]) Vec4_0025EF50(D_00387E10, D_00387E14, D_00387E18, 1.0f);
        new (&D_00452280[0]) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        new (&D_00452280[1]) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        new (&D_00452280[2]) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        new (&D_00452280[3]) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        new (&D_00452280[4]) Vec4_0025EF50(1.0f, 1.0f, 1.0f, 1.0f);
        Vec4_0025EF50* p = D_004522D0;
        for (int i = 95; i != -1; i--, p++)
            new (p) Vec4_0025EF50(0.0f, 0.0f, 0.0f, 1.0f);
        p = D_004528D0;
        for (int i = 95; i != -1; i--, p++)
            new (p) Vec4_0025EF50();
    }
}
