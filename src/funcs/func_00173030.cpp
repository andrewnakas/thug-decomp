extern "C" void func_0010BEB8(void* p);
extern "C" void func_0017B4D8();

struct Font_00173030 {
    char pad0[0x8];
    void* m8;
    char padC[0x12C - 0xC];
    void* m12C;
    char pad130[0x19C - 0x130];
    Font_00173030* m19C;
};

extern Font_00173030* D_00393F60;

void func_00173030(Font_00173030* f)
{
    if (D_00393F60 == f) {
        D_00393F60 = f->m19C;
    } else {
        for (Font_00173030* p = D_00393F60; p->m19C; p = p->m19C) {
            if (p->m19C == f) {
                p->m19C = f->m19C;
                break;
            }
        }
    }
    func_0010BEB8(f->m8);
    func_0010BEB8(f->m12C);
    func_0010BEB8(f);
    func_0017B4D8();
}
