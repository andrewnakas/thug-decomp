extern char D_0038FFB8[];
extern char D_0038FFC0[];

struct Array_00245580 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

struct Goal_00245580 {
    char m_pad[0x20];
    void* m_params;
};

extern void* D_0038FC78;

extern "C" bool func_001E8248(void* params, unsigned int name, Array_00245580** out, int assert_);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int assert_);
extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00203360(void* skater);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" unsigned int func_001055B0(unsigned int prefix, const char* name);
extern "C" int func_0023A168(void* self, unsigned int name, int a, int b, int c);
extern "C" unsigned int func_001E9270(Array_00245580* self, unsigned int index);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" bool func_00245450(Goal_00245580* self, unsigned int flag, int value);

bool func_00245580(Goal_00245580* self, unsigned int id)
{
    Array_00245580* list = 0;
    if (!func_001E8248(self->m_params, 0x52D4489E, &list, 0)) {
        return false;
    }
    const char* trick = D_0038FFB8;
    func_001E7C80(self->m_params, 0x730844A3, &trick, 0);
    if (*trick) {
        void* skater = func_0022DD38(D_0038FC78);
        if (!skater) {
            return false;
        }
        void* tricks = func_00203360(skater);
        unsigned int a = func_001F0D78(trick);
        unsigned int b = func_001055B0(0x7491335E, trick);
        unsigned int c = func_001055B0(0x73989B82, trick);
        if (!func_0023A168(tricks, a, 0, 0, 1) && !func_0023A168(tricks, b, 0, 0, 1) && !func_0023A168(tricks, c, 0, 0, 1)) {
            return false;
        }
    }
    for (unsigned int i = 0; i < list->GetSize(); i++) {
        if (id == func_001E9270(list, i)) {
            char buf[32];
            func_003331D0(buf, D_0038FFC0, i + 1);
            func_00245450(self, func_001F0D78(buf), 1);
            return true;
        }
    }
    return false;
}
