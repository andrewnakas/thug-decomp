struct Obj_0011B638;
extern "C" void func_0011ABE0(Obj_0011B638* self, void* params);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_0011B638 {
    char pad[0x18];
    int m18;
    int m1C;
    void Init(void* params);
};

void Obj_0011B638::Init(void* params)
{
    int a;
    int b;
    func_0011ABE0(this, params);
    if (func_001E7DE8(params, 0x0C7A712C, &a, 0)) {
        m18 = a != 0;
    }
    if (func_001E7DE8(params, 0x6EA3704A, &b, 0)) {
        m1C = b != 0;
    }
}
