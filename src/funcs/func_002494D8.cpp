struct Mgr_002494D8 {
    int m0;
    int m4;
};

extern "C" void* func_00249FE0(Mgr_002494D8* self);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7C80(void* params, unsigned int name, int* out, int assert_);
extern "C" int func_00248AA0(Mgr_002494D8* self, int* out, int a, int b, int c, bool d);
extern "C" void func_00249C58(Mgr_002494D8* self);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_00248FF8(Mgr_002494D8* self, int goal, int a, unsigned int b, bool c);

void func_002494D8(Mgr_002494D8* self, void* params)
{
    if (self->m4 || func_001E8708(func_00249FE0(self), 0x102A8591)) {
        return;
    }
    int level = -1;
    func_001E7DE8(params, 0x64EEE2E6, &level, 0);
    int arg = 0;
    func_001E7C80(params, 0x82CBE8D1, &arg, 0);
    bool flag = func_001E8708(params, 0x0E7F5FF8);
    int goal;
    bool ok = func_00248AA0(self, &goal, level, 0, arg, flag);
    if (goal) {
        func_00249C58(self);
        unsigned int name = 0;
        func_001E8398(params, 0xF0C598FA, &name, 0);
        func_00248FF8(self, goal, 0, name, ok);
    }
}
