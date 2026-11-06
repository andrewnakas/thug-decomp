struct Obj_002D5720_M {
    char pad0[0x8];
    void* m8;
};

struct Req_002D5720 {
    int m0;
    char m4[0x100];
    void (*m104)();
    unsigned int m108;
    unsigned int m10C;
    unsigned int m110;
    unsigned int m114;
};

extern Obj_002D5720_M* D_00392068;
extern char D_00392C58[];

extern "C" void func_001E7D18(void* p, char* name, char** out, int v);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_002D4040();
extern "C" void func_002D5608(void* p, Req_002D5720* req);

int func_002D5720(void* params)
{
    Req_002D5720 req;
    char* s;
    Obj_002D5720_M* m = D_00392068;
    unsigned int key = 0x0089990F;
    func_001E7D18(params, D_00392C58, &s, 0);
    void* q = m->m8;
    req.m108 = 0x7335AB7F;
    req.m10C = key;
    req.m114 = 0xCF040665;
    req.m110 = 0x4B85EE64;
    req.m0 = 0x14000;
    func_003331D0(req.m4, s);
    req.m104 = func_002D4040;
    func_002D5608(q, &req);
    return 1;
}
