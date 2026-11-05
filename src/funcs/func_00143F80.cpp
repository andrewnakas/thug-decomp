class Fx_00143F80 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    float m10;
    char pad14[0x10];
    virtual ~Fx_00143F80();
};

struct Game_00143F80 {
    char pad[0x38];
    int m38;
};

extern Game_00143F80* D_00390828;
extern void* D_0038A63C;
extern "C" float func_0010FAB8();
extern "C" void func_00144A28(void* table);
extern "C" Fx_00143F80* func_00144A38(void* table, int a);
extern "C" void func_00144AE8(void* table, Fx_00143F80** key);
extern "C" void func_00151A68(Fx_00143F80* fx, float dt);

static inline void Remove_00143F80(Fx_00143F80* key)
{
    func_00144AE8(D_0038A63C, &key);
}

extern "C" void func_00143F80()
{
    if (D_00390828->m38)
        return;
    if (!D_0038A63C)
        return;
    float dt = func_0010FAB8();
    func_00144A28(D_0038A63C);
    Fx_00143F80* fx = func_00144A38(D_0038A63C, 0);
    while (fx) {
        Fx_00143F80* dead = 0;
        fx->m10 -= dt;
        if (fx->m10 <= 0.0f)
            dead = fx;
        else
            func_00151A68(fx, dt);
        fx = func_00144A38(D_0038A63C, 0);
        if (dead) {
            Remove_00143F80(dead);
            delete dead;
        }
    }
}
