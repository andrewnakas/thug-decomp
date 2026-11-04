struct Goal_00248388 {
    char pad[0x20];
    void* m_params;
};

extern void* D_00392068;
extern void* D_0038FC78;
extern char D_00373A90[];
extern char D_00373AA8[];
extern char D_003738F8[];
extern char D_00373AB8[];
extern char D_00373AC8[];
extern char D_00390010[];

extern "C" void* func_00240850();
extern "C" bool func_001E8708(void* self, unsigned int name);
extern "C" void func_0023D588(void* self);
extern "C" void func_001E7360(void* self, unsigned int name, unsigned int value);
extern "C" bool func_002A19A8(void* self);
extern "C" bool func_001E87B8(void* self, const char* name);
extern "C" void* func_0022E368(void* self, int index);
extern "C" int func_00261F80(void* self);
extern "C" int func_001E53A0(unsigned int name, int assert_);
extern "C" bool func_001E7E58(void* self, const char* name, int* out, int assert_);
extern "C" void func_001E7268(void* self, const char* name, int value);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void* func_001E5588(const char* name, int assert_);
extern "C" unsigned int func_00246258(Goal_00248388* self);
extern "C" bool func_001E8180(void* self, unsigned int name, void** out, int assert_);
extern "C" void func_001E6C28(void* self, const char* name);
extern "C" void func_001E6AC8(void* self, void* other);

void func_00248388(Goal_00248388* self, void* params, int cash)
{
    int remove;
    void* reward;
    int amount;
    int amount2;
    int stat;

    void* mgr = func_00240850();
    void* game = D_00392068;
    if (!func_001E8708(self->m_params, 0x981D3AD0))
        func_0023D588(mgr);
    func_001E7360(params, 0, 0xC7FEF529);
    if (func_002A19A8(game))
        return;
    if (func_001E87B8(self->m_params, D_00373A90) && !func_001E8708(self->m_params, 0x8E6014F6)) {
        int n = func_00261F80(func_0022E368(D_0038FC78, 0));
        if (func_001E53A0(0x20297D6F, 0) >= n) {
            remove = 0;
            func_001E7E58(self->m_params, D_003738F8, &remove, 0);
            if (remove == 1) {
                func_001E7268(self->m_params, D_003738F8, 0);
                func_001E7360(self->m_params, 0, 0x65CA5FFC);
                func_001E7200(self->m_params, 0xB45FD352, 1);
            }
        }
    }
    void* rewards = func_001E5588(D_00373AA8, 1);
    reward = 0;
    func_001E8180(rewards, func_00246258(self), &reward, 0);
    if (reward) {
        if (func_001E87B8(reward, D_00373AB8)) {
            func_001E6C28(reward, D_00373AB8);
            func_001E7268(reward, D_00373AB8, 1);
        }
        func_001E6AC8(params, reward);
        if (cash && func_001E7E58(reward, D_00373AC8, &amount, 0))
            func_001E7268(params, D_00390010, amount);
    } else {
        if (cash && func_001E7E58(self->m_params, D_00373AC8, &amount2, 0))
            func_001E7268(params, D_00390010, amount2);
        if (func_001E87B8(self->m_params, D_00373AB8))
            func_001E7268(params, D_00373AB8, 1);
        else if (func_001E7E58(self->m_params, D_00373AB8, &stat, 0))
            func_001E7268(params, D_00373AB8, stat);
    }
}
