struct Obj_00270728 {
    char m_pad[0x24];
    void* m_params;
};

struct Skater_00270728 {
    char m_pad[0x20];
    int m20;
    char m_pad24[0x180 - 0x24];
    int m180;
};

struct Holder_00270728 {
    char m_pad[0x34];
    Skater_00270728* m_skater;
};

struct Base_00270728 {
    int m0;
    int m4;
    int m8;
    Obj_00270728* m_object;
    int m10;
    int m14;
    virtual void V0_00270728();
    virtual void V1_00270728();
    virtual void V2_00270728();
    virtual void V3_00270728();
    virtual void V4_00270728();
    virtual void V5_00270728();
    virtual void Suspend_00270728(int suspend);
};

struct Comp_00270728 : Base_00270728 {
    char m_pad1C[0x4C - 0x1C];
    Holder_00270728* m_holder;
    char m_pad50[0x94 - 0x50];
    int m_suspended;
};

extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);

int func_00270728(Comp_00270728* self, unsigned int msg)
{
    switch (msg) {
    case 0xEDE3935F:
        if (self->m_suspended != 1) {
            self->Suspend_00270728(0);
            self->m_suspended = 1;
        }
        break;
    case 0x9731E193:
        if (self->m_suspended) {
            self->Suspend_00270728(1);
            self->m_suspended = 0;
        }
        break;
    case 0x0B1E7291: {
        void* params = self->m_object->m_params;
        if (params) {
            Skater_00270728* skater = self->m_holder->m_skater;
            bool idle = false;
            if (!skater->m180) {
                idle = !skater->m20;
            }
            void* sub;
            if (idle && func_001E8180(params, 0x5DB4115F, &sub, 0) && func_001E8708(sub, 0x910D77C1)) {
                self->Suspend_00270728(0);
                self->m_suspended = 1;
            }
        }
        return 2;
    }
    default:
        return 2;
    }
    return 1;
}
