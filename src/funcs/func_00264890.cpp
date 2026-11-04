extern int D_0038C608;
extern char D_00375E20[];

extern "C" void* func_001E55F8(const char* name, int a);
extern "C" void* func_00186D60(int mgr, void* comps, void* params, int a);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001A4408(void* p);
extern "C" void func_00185288(void* obj, void* comp);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int c, int d);
extern "C" void func_00185500(void* obj);
extern "C" void* func_00185578(void* obj, unsigned int id);
extern "C" void func_0018DC18(void* comp);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);
extern "C" void func_00184AB0(void* obj, unsigned int a, int b);

struct Factory_00264890 {
    void* Create(void* params);
};

void* Factory_00264890::Create(void* params)
{
    int mgr = D_0038C608;
    void* obj = func_00186D60(mgr, func_001E55F8(D_00375E20, 0), params, 0);
    func_00185288(obj, func_001A4408(func_001046B0(0x70)));
    func_001F0210(0xF3B84DA6, params, obj, 0, 0);
    func_00185500(obj);
    void* c = func_00185578(obj, 0x286A8D26);
    if (c)
        func_0018DC18(c);
    unsigned int a = 0;
    if (func_001E8398(params, 0x2CA8A299, &a, 0)) {
        int b = 0;
        func_001E8180(params, 0x7031F10C, &b, 0);
        func_00184AB0(obj, a, b);
    }
    return obj;
}
