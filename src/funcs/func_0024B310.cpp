struct Mgr_0024B310 {
    char m_pad[0x394];
    void* m_records;
};

struct Base_0024B310 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0_0024B310();
    virtual void V1_0024B310();
    virtual void V2_0024B310();
    virtual void V3_0024B310();
    virtual void V4_0024B310();
    virtual void V5_0024B310();
    virtual void V6_0024B310();
    virtual void V7_0024B310();
    virtual void V8_0024B310();
    virtual void V9_0024B310();
    virtual void V10_0024B310();
    virtual void V11_0024B310();
    virtual void Win_0024B310();
    virtual void V13_0024B310();
    virtual void V14_0024B310();
    virtual void V15_0024B310();
    virtual void V16_0024B310();
    virtual bool IsMinigame_0024B310();
    virtual void V18_0024B310();
    virtual void V19_0024B310();
    virtual void V20_0024B310();
    virtual void V21_0024B310();
    virtual void V22_0024B310();
    virtual void Deactivate_0024B310();
};

struct Goal_0024B310 : Base_0024B310 {
    int m18;
    int m1C;
    void* m_params;
    char m_pad24[0x50 - 0x24];
    int m_record;
};

extern void* D_00392068;
extern Mgr_0024B310* D_0038FC78;
extern char D_00374068[];
extern char D_00374078[];

extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_00248800(Goal_0024B310* self, unsigned int name);
extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" bool func_002A19A8(void* skaters);
extern "C" bool func_00252150(void* records, int place);
extern "C" void func_001E7268(void* params, const char* name, int value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AE8(void* params, int flags);
extern "C" void func_00248388(Goal_0024B310* self, void* params, int a);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_00248630(Goal_0024B310* self);
extern "C" void func_001E6C28(void* params, const char* name);
extern "C" void func_001E7860(void* params, const char* name, void* value);

static inline void* NewParams_0024B310()
{
    return func_001E6978(func_001190D0(8));
}

static inline void DeleteParams_0024B310(void* params)
{
    if (params) {
        func_001E6AE8(params, 3);
    }
}

bool func_0024B310(Goal_0024B310* self)
{
    func_001E7360(self->m_params, 0, 0xC309CAD1);
    func_00248800(self, 0x01C92CAC);
    func_001E6D18(self->m_params, 0xC309CAD1);
    self->Win_0024B310();
    if (!func_002A19A8(D_00392068)) {
        void* records = D_0038FC78->m_records;
        int place = 999;
        if (func_00252150(records, 1)) {
            place = 1;
        } else if (func_00252150(records, 2)) {
            place = 2;
        } else if (func_00252150(records, 3)) {
            place = 3;
        }
        if (place < self->m_record) {
            func_001E7268(self->m_params, D_00374068, place);
            self->m_record = place;
        }
    }
    void* reward = NewParams_0024B310();
    if (!self->IsMinigame_0024B310()) {
        void* params = NewParams_0024B310();
        func_00248388(self, params, 1);
        func_001E6AC8(reward, params);
        DeleteParams_0024B310(params);
        func_00248630(self);
    } else {
        func_001E6C28(self->m_params, D_00374078);
    }
    func_001E7860(self->m_params, D_00374078, reward);
    func_00248800(self, 0x90FF204D);
    DeleteParams_0024B310(reward);
    if (!self->IsMinigame_0024B310()) {
        self->Deactivate_0024B310();
    }
    return true;
}
