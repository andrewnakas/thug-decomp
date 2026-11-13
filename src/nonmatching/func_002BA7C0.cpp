/* fuzzy: 84.8 */
struct Ent_002BA7C0 {
    int a;
    int b;
    char pad2[0x28];
};

extern "C" void func_002BA688(void* self, int n, int* a, int* b);

struct Obj_002BA7C0 {
    char pad[0xCC];
    Ent_002BA7C0 ents[1];
    bool Check(int n);
};

bool Obj_002BA7C0::Check(int n)
{
    /* range [lo, hi] as one 8-aligned pair: the game passes &r[1] as `ori $a3, $sp, 0x4` (0x2BA7E0) */
    int r[2];
    r[0] = 0;
    r[1] = 0;
    func_002BA688(this, n, &r[0], &r[1]);
    int hi = r[1];
    for (int i = r[0]; i <= hi; i++) {
        if (!ents[i].a || ents[i].b) return true;
    }
    return false;
}
