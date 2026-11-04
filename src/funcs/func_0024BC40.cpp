extern char D_003742C0[];
extern char D_003742D0[];
extern char D_003902D8[];
extern char D_003742E0[];
extern char D_003902E0[];
extern char D_003742F0[];
extern char D_003902E8[];

struct Array_0024BC40 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

struct GoalBase_0024BC40 {
    char m_pad[0x14];
    virtual void V0();
    virtual bool IsExpired();
};

struct Goal_0024BC40 : GoalBase_0024BC40 {
    int m18;
    int m1C;
    void* m_params;
    char m_pad24[0x54 - 0x24];
    int m54;
    char m_pad58[0x60 - 0x58];
    int m60;
    char m_pad64[0xA0 - 0x64];
    int mA0;
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" bool func_001E82B8(void* params, const char* name, Array_0024BC40** out, int assert_);
extern "C" void* func_001E9378(Array_0024BC40* self, unsigned int index);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" bool func_00245748(Goal_0024BC40* self, unsigned int flag, int a);
extern "C" void func_001E7268(void* params, const char* name, int value);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" void* func_001F0938(const char* script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" void func_00244600(Goal_0024BC40* self, int value);

bool func_0024BC40(Goal_0024BC40* self, unsigned int id)
{
    if (self->IsExpired()) {
        func_00103F28(D_003742C0);
        return false;
    }
    Array_0024BC40* list;
    func_001E82B8(self->m_params, D_003742D0, &list, 1);
    for (unsigned int i = 0; i < list->GetSize(); i++) {
        void* elem = func_001E9378(list, i);
        unsigned int flag;
        func_001E84E8(elem, D_003902D8, &flag, 1);
        if (!func_00245748(self, flag, 1)) {
            if (!self->m60) {
                self->m54 = 0;
                func_001E7268(elem, D_003742E0, 1);
            }
            func_001E73C8(elem, D_003902E0, id);
            if (func_001E8708(self->m_params, 0x38221DF4)) {
                func_001E7360(elem, 0, 0x38221DF4);
            } else {
                func_001E6D18(elem, 0x38221DF4);
            }
            func_001F0938(D_003742F0, elem, 0, 0, -1, 0, 0, 0, 0, 0);
            if (!self->mA0) {
                int time;
                func_001E7E58(elem, D_003902E8, &time, 0);
                func_00244600(self, time);
            }
            return true;
        }
    }
    return true;
}
