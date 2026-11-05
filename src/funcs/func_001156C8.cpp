struct Ent_001156C8 {
    short a;
    short b;
    short c;
    short d;
};

extern "C" int func_00110F68(void* buf, int size, int count, void* f);

extern "C" int func_001156C8(void* f, Ent_001156C8* e)
{
    for (int i = 0; i < 256; i++, e++) {
        if (!func_00110F68(&e->a, 2, 1, f)
            || !func_00110F68(&e->b, 2, 1, f)
            || !func_00110F68(&e->c, 2, 1, f)
            || !func_00110F68(&e->d, 2, 1, f)) {
            return 0;
        }
    }
    return 1;
}
