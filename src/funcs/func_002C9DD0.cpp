struct Scr_002C9DD0 {
    int m0;
    int m4;
};

extern "C" void* func_001E6978(Scr_002C9DD0* p);
extern "C" void func_001E7360(Scr_002C9DD0* s, unsigned int name, unsigned int v);
extern "C" void func_001F0370(char* s, Scr_002C9DD0* a, int b, int c);
extern "C" void func_001E6AE8(Scr_002C9DD0* p, int v);
extern char D_0037AB90[];

struct Obj_002C9DD0 {
    char pad0[0x7C];
    int m7C;
    void Report();
};

void Obj_002C9DD0::Report()
{
    Scr_002C9DD0 s;
    func_001E6978(&s);
    if (m7C == 3) {
        func_001E7360(&s, 0x6835B854, 0xE75A3A17);
    } else if (m7C == 2) {
        func_001E7360(&s, 0x6835B854, 0x780A5CF3);
    } else if (m7C == 6) {
        func_001E7360(&s, 0x6835B854, 0xFFD81C08);
    } else {
        func_001E7360(&s, 0x6835B854, 0xB58EFC2B);
    }
    func_001F0370(D_0037AB90, &s, 0, 0);
    func_001E6AE8(&s, 2);
}
