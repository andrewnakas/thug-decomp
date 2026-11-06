extern "C" void func_003315B8(void*, int, int);
extern "C" int func_00327BE0(int, int, void*, int);
extern "C" int func_00326E60(char*, int*);
extern "C" int func_001F84E8(char*);

struct Net_001F87E0 {
    char m_pad[0x260];
    char m260[0x20];
};

extern "C" int func_001FA588(Net_001F87E0*);
extern "C" char* func_001FA640(Net_001F87E0*);
extern "C" char* func_001FA610(Net_001F87E0*);
extern "C" char* func_001FA608(Net_001F87E0*);
extern "C" void func_001FA658(Net_001F87E0*, int);

extern "C" int func_001F87E0(Net_001F87E0* n)
{
    int ip[3];
    if (func_001FA588(n)) {
        func_003315B8(ip, 0, 0xC);
    } else {
        func_00326E60(func_001FA640(n), &ip[0]);
        func_00326E60(func_001FA610(n), &ip[1]);
        func_00326E60(func_001FA608(n), &ip[2]);
    }
    if (func_00327BE0(0, 0, ip, 0xC) != 0 || (func_001FA588(n) && func_001F84E8(n->m260) != 0)) {
        func_001FA658(n, 1);
        return 0;
    }
    return 1;
}
