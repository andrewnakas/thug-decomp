struct Vec_00192380 {
    float x, y, z, w;
    float& operator[](int i) { return (&x)[i]; }
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);

struct Corner_00192380 {
    Vec_00192380 v;
    char m10[0x10];
    unsigned char m20;
    char pad21[0xF];
    Corner_00192380() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Box_00192380 {
    char pad0[0x50];
    Corner_00192380* m50;
    unsigned short m54;
    void Build(Vec_00192380* hi, Vec_00192380* lo);
};

void Box_00192380::Build(Vec_00192380* hi, Vec_00192380* lo)
{
    m54 = 8;
    if (m50) func_0010A8D8(D_00388A70, m50);
    m50 = new Corner_00192380[m54];
    int n = 0;
    bool bx = false;
    do {
        bool by = false;
        do {
            bool bz = false;
            do {
                m50[n].v[0] = (bx ? 1.0f : -1.0f) * (by ? hi->x : lo->x);
                m50[n].v[1] = (by ? 1.0f : -1.0f) * (by ? hi->y : lo->y);
                m50[n].v[2] = (bz ? 1.0f : -1.0f) * (by ? hi->z : lo->z);
                m50[n].v[3] = 1.0f;
                m50[n].m20 = 0;
                n++;
                bz = !bz;
            } while (bz);
            by = !by;
        } while (by);
        bx = !bx;
    } while (bx);
}
