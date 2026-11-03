extern char D_00376430[];
extern char D_00376440[];
extern char D_00376450[];
extern char D_00376460[];
extern char D_00376470[];
extern char D_00376480[];

extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" void func_0026E690(void* table, void* in);
extern "C" void func_0026E2F8(void* rec, void* in);

struct Records_0026EA30 {
    int m0;
    void* m4;
    void* m8;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    void ReadFromStructure(void* in);
};

void Records_0026EA30::ReadFromStructure(void* in)
{
    void* s = 0;
    func_001E81F0(in, D_00376430, &s, 0);
    func_0026E690(m4, s);
    func_001E81F0(in, D_00376440, &s, 0);
    func_0026E690(m8, s);
    func_001E81F0(in, D_00376450, &s, 0);
    func_0026E2F8(m18, s);
    func_001E81F0(in, D_00376460, &s, 0);
    func_0026E2F8(mC, s);
    func_001E81F0(in, D_00376470, &s, 0);
    func_0026E2F8(m14, s);
    func_001E81F0(in, D_00376480, &s, 0);
    func_0026E2F8(m10, s);
}
