extern char D_00374AA8[];

struct C_002503F0 {
    int m0;
    char* m4;
};

extern "C" void func_0024FF90(C_002503F0* self);

extern "C" C_002503F0* func_002503F0(C_002503F0* self)
{
    func_0024FF90(self);
    self->m4 = D_00374AA8;
    return self;
}
