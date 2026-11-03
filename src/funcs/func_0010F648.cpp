struct Elem10F648 {
    int m[4];
};

struct Obj10F648 {
    char pad[0x18];
    Elem10F648 m18[8];
    Elem10F648* Get(int i);
};

Elem10F648* Obj10F648::Get(int i)
{
    return &m18[i];
}
