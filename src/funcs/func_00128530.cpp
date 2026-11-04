struct C_00128530 {
    char pad0[0x188];
    float m188;
    char pad18C[0x1A0 - 0x18C];
    void* m1A0;
    char pad1A4[0x1C4 - 0x1A4];
    float m_scale;
    bool Append(const char* text, int checkSep, int check);
};

extern void* D_00388A70;
extern char D_003897C0[];
extern "C" char* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" bool func_00127BE8(C_00128530* self, char* buf, int size);
extern "C" char* func_00331678(char* d, const char* s);
extern "C" int func_00331950(const char* a, const char* b);
extern "C" void* func_00130B80(void* o);
extern "C" int func_00127F98(C_00128530* self, char* word, const char** p);
extern "C" void func_00135890(void* font, const char* text, float* w, float* h);
extern "C" void func_00127BC0(C_00128530* self, const char* text);

bool C_00128530::Append(const char* text, int checkSep, int check)
{
    char* buf = func_0010A638(D_00388A70, 0x200, 1, 0);
    func_00127BE8(this, buf, 0x200);
    func_00331678(buf, text);
    if ((checkSep && func_00331950(text, D_003897C0)) || check) {
        void* font = func_00130B80(m1A0);
        const char* p = buf;
        char word[0x60];
        while (func_00127F98(this, word, &p) != 2)
            ;
        float w;
        float h;
        func_00135890(font, word, &w, &h);
        w *= m_scale;
        if (w > m188) {
            func_0010A8D8(D_00388A70, buf);
            return false;
        }
    }
    func_00127BC0(this, buf);
    func_0010A8D8(D_00388A70, buf);
    return true;
}
