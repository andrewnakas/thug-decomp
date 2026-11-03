extern char D_0037BF98[];
extern char* D_0038C308;

extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_00105260(void* p, int v);

struct Obj_002D5050 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x37C - 0x10];
    char m37C[1];
    void Start();
};

extern "C" void func_002D4CF8(Obj_002D5050* p, char* msg);

void Obj_002D5050::Start()
{
    char buf[128];
    char* q = D_0038C308;
    m4 = 1;
    func_003331D0(buf, D_0037BF98, m37C);
    func_002D4CF8(this, buf);
    mC = 0;
    func_00105260(q + 8, m0);
}
