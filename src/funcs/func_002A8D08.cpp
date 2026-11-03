extern char D_00371C78[];
extern char D_00392130[];

struct Iter_002A8D08 {
    int m0;
    int m4;
    void* m8;
    Iter_002A8D08() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A8D08() { m8 = D_00371C78; }
};

struct Elem_002A8D08;
struct Obj_002A8D08;
extern Obj_002A8D08* D_00392068;
extern "C" int func_001E7E58(void* params, char* name, int* out, int f);
extern "C" Elem_002A8D08* func_002A53F8(Obj_002A8D08* o, Iter_002A8D08* it, int f);
extern "C" Elem_002A8D08* func_002A5490(Obj_002A8D08* o, Iter_002A8D08* it, int f);
extern "C" int func_002B22C8(Elem_002A8D08* e);

extern "C" bool func_002A8D08(void* params)
{
    Iter_002A8D08 it;
    int id;
    Obj_002A8D08* o = D_00392068;
    func_001E7E58(params, D_00392130, &id, 0);
    for (Elem_002A8D08* e = func_002A53F8(o, &it, 0); e; e = func_002A5490(o, &it, 0)) {
        if (func_002B22C8(e) == id)
            return true;
    }
    return false;
}
