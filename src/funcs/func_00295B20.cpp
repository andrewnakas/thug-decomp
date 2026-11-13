struct Sk_00295B20 {
    char pad[0x3B0];
    unsigned int m3B0;
};

struct Comp_00295B20 {
    char pad[0x94];
    int m94;
};

extern Sk_00295B20* D_0038FC78;
extern "C" int func_00294AE0(void* p);

struct Obj_00295B20 {
    char pad[0xA5C0];
    void* mA5C0;
    void* mA5C4;
    Comp_00295B20* mA5C8;
    void Update();
};

void Obj_00295B20::Update()
{
    if (func_00294AE0(mA5C0) == 1 || func_00294AE0(mA5C0) == 2) {
        if (D_0038FC78->m3B0 != 0xE8B4B836)
            mA5C8->m94 = 0;
        else
            mA5C8->m94 = 1;
    } else {
        mA5C8->m94 = 1;
    }
}
