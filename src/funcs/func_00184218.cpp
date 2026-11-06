extern char D_003618E0[];
extern char D_003618F8[];
extern char D_0038C4A8[];
extern char D_00361908[];

extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_001E82B8(void* params, const char* name, void* out, int required);
extern "C" int func_001E81F0(void* params, const char* name, void* out, int required);
extern "C" void func_00183F38(void* obj, int a, int flag);
extern "C" void func_001840F8(void* obj, int b);
extern "C" void func_00184138(void* obj, void* set);

class Obj_00184218 {
public:
    void InitFromStructure(void* params);
};

void Obj_00184218::InitFromStructure(void* params)
{
    int a;
    int b;
    void* set;
    int flag = func_001E87B8(params, D_003618E0);
    if (func_001E82B8(params, D_003618F8, &a, 0)) {
        func_00183F38(this, a, flag);
    }
    if (func_001E81F0(params, D_0038C4A8, &b, 0)) {
        func_001840F8(this, b);
    }
    if (func_001E82B8(params, D_00361908, &set, 0)) {
        func_00184138(this, set);
    }
}
