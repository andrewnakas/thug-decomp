/* cflags: -fopt-stack */
extern "C" int func_00185578(int script, unsigned int checksum);

struct Obj_0028FAE0 {
    char pad0[0xC];
    int mC;
    char pad10[0x1C - 0x10];
    int m1C;
    int m20;
    void Refresh();
};

void Obj_0028FAE0::Refresh() {
    m1C = func_00185578(mC, 0x5BD63B29);
    m20 = func_00185578(mC, 0x43686585);
}
