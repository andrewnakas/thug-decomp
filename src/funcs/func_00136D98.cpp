extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001349F0(void* self, int n);
extern void* D_00388A70;

struct Light_00136D98 {
    char pad[0x10];
    float m10;
    float m14;
    int m18;
    unsigned char m1C;
    unsigned char m1D;
    unsigned char m1E;
    void* m20;
    Light_00136D98();
};

Light_00136D98::Light_00136D98()
{
    m20 = func_001349F0(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    m14 = 0.0f;
    m10 = 0.0f;
    m1C = 0x80;
    m1D = 0x80;
    m1E = 0x80;
}
