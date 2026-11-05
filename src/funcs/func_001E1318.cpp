struct Obj_001E1318 {
    int m0;
};

extern "C" void func_001E1248(Obj_001E1318* p);

extern "C" bool func_001E1318(Obj_001E1318* p)
{
    if (p->m0) {
        func_001E1248(p);
        return true;
    }
    return false;
}
