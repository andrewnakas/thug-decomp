/* fuzzy: 88.3 */
/* blocked: the game keeps a second copy of this+0x60 for the loop ($t0 = $a2 at 0x00107FE4); local, member,
   struct-pointer, reference and per-iteration pointer forms and cxxperm give one register (loop.c tie). */
extern "C" void func_0031AA28(int a, int b);

struct Obj_00107FB0 {
    char pad[0x10];
    int m10;
    int m14;
    char pad18[0x60 - 0x18];
    struct Bufs {
        char a[0x40];
        char b[0x2C];
    } m60;
    int mCC;
    int mD0;
    int mD4;
    int mD8;
    int mDC;
    void Clear();
};

void Obj_00107FB0::Clear()
{
    if (mDC == 2) {
        int i = 0;
        if (mCC & 2) {
            char* a = m60.a;
            while (i < mD4) {
                char* b = m60.b;
                a[i] = 0;
                b[i] = 0;
                i++;
            }
            func_0031AA28(m10, m14);
        }
    }
}
