struct Obj_001F3628 {
    char pad0[0x10];
    int m10;
};

extern Obj_001F3628* D_0038E890[2];
extern int D_0038E8A0;

int func_001F3628() {
    return D_0038E890[D_0038E8A0]->m10;
}
