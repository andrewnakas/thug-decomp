extern char D_00376430[];
extern char D_00376440[];
extern char D_00376450[];
extern char D_00376460[];
extern char D_00376470[];
extern char D_00376480[];

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_0026E740(void* table, void* out);
extern "C" void func_0026E258(void* rec, void* out);

struct Records_0026EB38 {
    int m0;
    void* m4;
    void* m8;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    void WriteToStructure(void* out);
};

void Records_0026EB38::WriteToStructure(void* out)
{
    void* s = func_001E6978(func_001190D0(8));
    func_0026E740(m4, s);
    func_001E7A68(out, func_001F0D78(D_00376430), 0xB, s);
    s = func_001E6978(func_001190D0(8));
    func_0026E740(m8, s);
    func_001E7A68(out, func_001F0D78(D_00376440), 0xB, s);
    s = func_001E6978(func_001190D0(8));
    func_0026E258(m18, s);
    func_001E7A68(out, func_001F0D78(D_00376450), 0xB, s);
    s = func_001E6978(func_001190D0(8));
    func_0026E258(mC, s);
    func_001E7A68(out, func_001F0D78(D_00376460), 0xB, s);
    s = func_001E6978(func_001190D0(8));
    func_0026E258(m14, s);
    func_001E7A68(out, func_001F0D78(D_00376470), 0xB, s);
    s = func_001E6978(func_001190D0(8));
    func_0026E258(m10, s);
    func_001E7A68(out, func_001F0D78(D_00376480), 0xB, s);
}
