struct Obj_00114E50;
extern "C" int func_001842E0(Obj_00114E50* self, unsigned int name, void* params, void* script);
extern "C" int func_001E7EB0(void* params, int name, float* out, int required);
extern "C" void func_00114D28(Obj_00114E50* self, float v);

struct Obj_00114E50 {
    int m0;
    int Dispatch(unsigned int name, void* params, void* script);
};

int Obj_00114E50::Dispatch(unsigned int name, void* params, void* script)
{
    if (name == 0x44EA2B6D) {
        float v;
        func_001E7EB0(params, 0, &v, 1);
        func_00114D28(this, v * 57.29577637f);
        return 1;
    }
    return func_001842E0(this, name, params, script);
}
