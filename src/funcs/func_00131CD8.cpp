class Scene_00131CD8 {
public:
    char pad0[0x280];
    virtual ~Scene_00131CD8();
};

extern Scene_00131CD8* D_004653B0[4];
extern "C" void func_001325A0(Scene_00131CD8* s);
extern "C" void func_00132E20(Scene_00131CD8* s);
extern "C" int func_00146178(Scene_00131CD8* s);

extern "C" bool func_00131CD8(Scene_00131CD8* s)
{
    func_001325A0(s);
    func_00132E20(s);
    if (func_00146178(s)) {
        if (s) {
            delete s;
        }
        for (int i = 0; i < 4; i++) {
            if (D_004653B0[i] == s) {
                D_004653B0[i] = 0;
                return true;
            }
        }
    }
    return false;
}
