struct Elem_0026EE60 {
    char pad[0x1C];
};

struct Obj_0026EE60 {
    int m0;
    int m4;
    int m8;
    Elem_0026EE60* mC;
    Elem_0026EE60* Get(int i);
};

Elem_0026EE60* Obj_0026EE60::Get(int i)
{
    return &mC[i];
}
