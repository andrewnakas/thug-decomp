struct Sub_00122E00 {
    int m0;
};

struct Obj_00122E00 {
    int m0;
    int m4;
    Sub_00122E00 m8;
};

extern char D_0035CBD0[];
extern "C" void func_00121FE0(Sub_00122E00* s);
extern "C" void func_00123530(Obj_00122E00* self, const char* name);

extern "C" Obj_00122E00* func_00122E00(Obj_00122E00* self)
{
    self->m4 = 0;
    func_00121FE0(&self->m8);
    func_00123530(self, D_0035CBD0);
    return self;
}
