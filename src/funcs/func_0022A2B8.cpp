extern char D_00372540[];
extern char D_00372558[];

struct Heap_0022A2B8 {
    char pad[0xD8];
    void* m_D8;
    char padDC[8];
    void* m_E4;
};

extern Heap_0022A2B8* D_00388A70;

extern "C" void func_001ED9A0(unsigned int key);
extern "C" void func_00229AD0();
extern "C" void func_00229520();
extern "C" void func_0010A950(Heap_0022A2B8* heap, void* a);
extern "C" void func_0010A9B0(Heap_0022A2B8* heap);
extern "C" unsigned char* func_0010BDE0(int size);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001EDBA8(char* name, unsigned char* data, int a, int b);
extern "C" int* func_001E5018(char* name);
extern "C" void func_00292388();

void func_0022A2B8(int count, int bottom)
{
    func_001ED9A0(0xC472ECC5);
    func_00229AD0();
    func_00229520();
    if (bottom)
        func_0010A950(D_00388A70, D_00388A70->m_E4);
    else
        func_0010A950(D_00388A70, D_00388A70->m_D8);
    unsigned char* buf = func_0010BDE0(count * 2 + 9);
    buf[0] = 0x16;
    buf[1] = 0xC5;
    buf[2] = 0xEC;
    buf[3] = 0x72;
    buf[4] = 0xC4;
    buf[5] = 7;
    buf[6] = 5;
    unsigned char* p = buf + 7;
    for (int i = 0; i < count; i++) {
        *p++ = 3;
        *p++ = 4;
    }
    p[0] = 6;
    p[1] = 0;
    func_001EDBA8(D_00372540, buf, 1, 1);
    int* sym = func_001E5018(D_00372558);
    *sym &= ~0x100;
    func_00292388();
    func_0010BEB8(buf);
    func_0010A9B0(D_00388A70);
}
