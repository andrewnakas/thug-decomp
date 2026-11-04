struct Ch_0029A500 {
    int m0;
    Ch_0029A500* m4;
};

struct Obj_0029A500;
extern "C" void func_0029C158(Obj_0029A500* o, int v);
extern "C" void func_00299628(Ch_0029A500* c);

struct Obj_0029A500 {
    char pad[0x24];
    Ch_0029A500* m24;
    void Refresh();
};

void Obj_0029A500::Refresh()
{
    func_0029C158(this, 0);
    for (Ch_0029A500* c = m24; c; c = c->m4)
        func_00299628(c);
    func_0029C158(this, 1);
}
