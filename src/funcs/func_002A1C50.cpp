extern char D_00378280[];
extern char D_00378290[];
extern char D_003782A0[];
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* p, char* name, char* v);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002A1C50 {
    void Run(char* text);
};

void Obj_002A1C50::Run(char* text)
{
    func_001F0370(D_00378280, 0, 0, 0);
    if (text) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7268(p, D_00378290, text);
        func_001F0370(D_003782A0, p, 0, 0);
        if (p)
            func_001E6AE8(p, 3);
    }
}
