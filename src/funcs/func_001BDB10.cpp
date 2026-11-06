typedef int qword_001BDB10 __attribute__((mode(TI)));

struct Vec_001BDB10 {
    qword_001BDB10 q;
};

extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_001BDB10* out, int req);

struct Model_001BDB10 {
    char pad[0xB0];
    Vec_001BDB10 mB0;
};

struct Obj_001BDB10 {
    char pad[0xC];
    Model_001BDB10* mC;
    void Method(void* params);
};

void Obj_001BDB10::Method(void* params)
{
    Vec_001BDB10 v;
    func_001E7FA8(params, 0x0C4C809E, &v, 1);
    mC->mB0 = v;
}
