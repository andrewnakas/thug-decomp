struct Slot_00111FB8 {
    int m_size;
    volatile int m_used;
    void* m_mem;
};

extern Slot_00111FB8 D_00464DB8[2];
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

extern "C" void func_00111FB8()
{
    int step = 0x3268;
    for (int i = 0; i < 2; i++) {
        int size = 0x1000 + i * step;
        D_00464DB8[i].m_mem = func_0010A638(D_00388A70, size, 1, 0);
        D_00464DB8[i].m_size = size;
        D_00464DB8[i].m_used = 0;
    }
}
