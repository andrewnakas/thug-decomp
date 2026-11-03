/* cflags: -fopt-stack */
extern "C" int func_00185578(int script, unsigned int checksum);

struct Obj_00290A18 {
    char pad0[0xC];
    int mC;
    char pad10[0x230 - 0x10];
    int m230;
    void Refresh();
};

void Obj_00290A18::Refresh() { m230 = func_00185578(mC, 0x72AD7B23); }
