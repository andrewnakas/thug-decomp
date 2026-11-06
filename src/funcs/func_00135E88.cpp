struct Rgba_00135E88 {
    unsigned char r, g, b, a;
};

extern Rgba_00135E88 D_003BEB30[];
extern "C" bool func_0014ACD0(int i);

extern "C" bool func_00135E88(int i, Rgba_00135E88* c)
{
    D_003BEB30[i] = *c;
    return func_0014ACD0(i);
}
