extern "C" int func_001E87B8(void* params, void* key);
extern "C" int func_001E55F8(char* name, int a);
extern "C" void func_00186D60(int a, int b, void* params, int c);
extern "C" void func_00264890(void* self, void* params, int c);
extern char D_00390FF8[];
extern int D_0038C608;
extern char D_00375E40[];

struct Obj_002649B8 {
    void Run(void* params);
};

void Obj_002649B8::Run(void* params)
{
    if (func_001E87B8(params, D_00390FF8)) {
        int m = D_0038C608;
        func_00186D60(m, func_001E55F8(D_00375E40, 0), params, 1);
        return;
    }
    func_00264890(this, params, 1);
}
