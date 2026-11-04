extern char D_003738F8[];
extern char D_00373910[];

struct Goal_00247338 {
    char m_pad[0x20];
    void* m_params;
};

struct Trick_00247338 {
    int m0;
    unsigned int m4;
    int m8;
    int mC;
};

struct Combo_00247338 {
    int m0;
    unsigned int m4;
    unsigned int m8;
    int mC;
};

extern void* D_0038FC78;

extern "C" void* func_0022E050(void* self);
extern "C" void* func_00262990(void* self);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" Trick_00247338 func_00261FB0(void* self, int index);
extern "C" Combo_00247338* func_00264728(Combo_00247338* self);
extern "C" void func_002620D8(void* self, int index, Combo_00247338* combo, int flag);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_00261F10(void* self, int value);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E6C28(void* params, const char* name);

void func_00247338(Goal_00247338* self)
{
    void* tricks = func_00262990(func_0022E050(D_0038FC78));
    int remove;
    func_001E7E58(self->m_params, D_003738F8, &remove, 1);
    if (remove == 1) {
        unsigned int key;
        if (func_001E8708(self->m_params, 0x8E6014F6)) {
            key = 0;
        } else {
            func_001E8398(self->m_params, 0xEF6FB249, &key, 1);
        }
        for (int i = 0; i < 12; i++) {
            Trick_00247338 trick = func_00261FB0(tricks, i);
            if (trick.m4 == key) {
                Combo_00247338 combo;
                func_00264728(&combo);
                unsigned int none = 0xF60C9090;
                combo.m4 = none;
                combo.m8 = none;
                func_002620D8(tricks, i, &combo, 1);
                func_001E7200(self->m_params, 0xBC678826, 0);
                break;
            }
        }
        func_00261F10(tricks, -1);
    }
    func_001E6B90(self->m_params, 0x79704516);
    func_001E6C28(self->m_params, D_00373910);
}
