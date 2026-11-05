extern char D_0037BE30[];

struct List_002D3D78 {
    int m0;
    List_002D3D78* m4;
    int m8;
    List_002D3D78* mC;
    List_002D3D78* m10;
    void* m14;
    char pad18[0x58 - 0x18];
    int m58;
    int m5C;
    int m60;
    List_002D3D78();
};

List_002D3D78::List_002D3D78()
{
    m4 = this;
    m14 = D_0037BE30;
    m8 = 0;
    mC = this;
    m10 = this;
    m58 = 0;
    m5C = 0;
    m60 = 0;
}
