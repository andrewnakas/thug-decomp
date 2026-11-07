/* fuzzy: 72.7 */
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
    int lo = 0;
    int hi = 0;
    func_002BA688(this, n, &lo, &hi);
    Ent_002BA7C0* e = &ents[lo];
    for (int i = lo; i <= hi; i++, e++) {
        if (!e->a || e->b) return true;
    }
    return false;
}
