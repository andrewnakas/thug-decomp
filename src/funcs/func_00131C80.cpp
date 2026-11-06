struct Scene_00131C80;
extern "C" int func_00133170(Scene_00131C80* s);

struct Scene_00131C80 {
    int m0;
    void Update() { func_00133170(this); }
};

extern Scene_00131C80* D_004653B0[4];

extern "C" void func_00131C80()
{
    for (int i = 0; i < 4; i++) {
        Scene_00131C80* s = D_004653B0[i];
        if (s) {
            s->Update();
        }
    }
}
