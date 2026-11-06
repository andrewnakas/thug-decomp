struct Obj_001E2C10 {
    int m_mode;
    int m4;
    int m8;
    void* m_dst;
    int m10;
    char* m_total;
};

extern char* D_0038E278;

extern "C" int func_0010E698(void* dst, char* src, int a, int size);

extern "C" void func_001E2C10(Obj_001E2C10* o, int idx)
{
    if (!o->m_dst)
        return;
    if (o->m_mode == 0) {
        func_0010E698(o->m_dst, D_0038E278 + idx * 0x30000, 1, 0x30000);
        o->m_total += 0x30000;
    } else {
        char* src = D_0038E278 + 0x60000;
        src += (o->m_mode - 1) * 0x10000;
        src += idx * 0x8000;
        func_0010E698(o->m_dst, src, 1, 0x8000);
        o->m_total += 0x8000;
    }
}
