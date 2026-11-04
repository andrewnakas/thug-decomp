extern int D_00388A70;
extern "C" void* func_0010A638(int pool, int size, int a, int b);
extern "C" void* func_001046B0(int size);

struct Table_001CFED0;
extern "C" Table_001CFED0* func_001D0C10(void* self, int bits);

struct Node_001CFED0 {
    char pad[0x18];
    Node_001CFED0* m18;
    Node_001CFED0* m1C;
};
extern "C" Node_001CFED0* func_001D0FB0(void* self);

struct Registry_001CFED0 {
    int m0;
    int m4;
    int m8;
    Table_001CFED0* mC;
    Node_001CFED0* m10;
    Registry_001CFED0();
};

Registry_001CFED0::Registry_001CFED0()
{
    mC = func_001D0C10(func_0010A638(D_00388A70, 0x18, 1, 0), 10);
    m10 = func_001D0FB0(func_001046B0(0x24));
    m10->m1C = m10;
    m10->m18 = m10;
}
