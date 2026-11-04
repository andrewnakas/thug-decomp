extern char D_0037ACC0[];
extern char D_0037ACE0[];
extern "C" void func_001F0370(char* name, int a, int b, int c);

struct Obj_002CA650 {
    char pad0[0x10];
    int m10;
    void Reset();
};

void Obj_002CA650::Reset()
{
    func_001F0370(D_0037ACC0, 0, 0, 0);
    func_001F0370(D_0037ACE0, 0, 0, 0);
    m10 = 0;
}
