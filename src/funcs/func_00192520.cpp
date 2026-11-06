struct Vec_00192520 {
    float x, y, z, w;
};

extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);

struct Corner_00192520 {
    Vec_00192520 v;
    char m10[0x10];
    unsigned char m20;
    char pad21[0xF];
    Corner_00192520() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Box_00192520 {
    char pad0[0x50];
    Corner_00192520* m50;
    unsigned short m54;
    void BuildPyramid(float h, float r);
};

void Box_00192520::BuildPyramid(float h, float r)
{
    m54 = 5;
    if (m50) func_0010A8D8(D_00388A70, m50);
    m50 = new Corner_00192520[m54];
    m50[0].v.x = r;
    m50[0].v.y = h * -0.6f;
    m50[0].v.z = r;
    m50[0].v.w = 1.0f;
    m50[0].m20 = 0;
    m50[1].v.x = -r;
    m50[1].v.y = h * -0.6f;
    m50[1].v.z = r;
    m50[1].v.w = 1.0f;
    m50[0].m20 = 0;
    m50[2].v.x = -r;
    m50[2].v.y = h * -0.6f;
    m50[2].v.z = -r;
    m50[2].v.w = 1.0f;
    m50[0].m20 = 0;
    m50[3].v.x = r;
    m50[3].v.y = h * -0.6f;
    m50[3].v.z = -r;
    m50[3].v.w = 1.0f;
    m50[0].m20 = 0;
    m50[4].v.x = 0.0f;
    m50[4].v.y = h * 1.6f;
    m50[4].v.z = 0.0f;
    m50[4].v.w = 1.0f;
    m50[0].m20 = 0;
}
