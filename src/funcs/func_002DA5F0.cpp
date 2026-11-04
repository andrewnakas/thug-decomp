extern char D_0037CAB8[];
extern char D_0037CAD0[];

struct Node_002DA5F0 {
    int m0;
    void* m4;
    int m8;
    Node_002DA5F0* mC;
    Node_002DA5F0* m10;
    void* m14;
};

struct Head_002DA5F0 : Node_002DA5F0 {
    Head_002DA5F0()
    {
        m14 = D_0037CAB8;
        m4 = this;
        m8 = 0;
        mC = this;
        m10 = this;
    }
};

struct Tail_002DA5F0 : Node_002DA5F0 {
    Tail_002DA5F0()
    {
        m4 = (void*)0xFFFFFFFF;
        m8 = 0;
        mC = this;
        m10 = this;
        m14 = D_0037CAD0;
    }
};

struct Obj_002DA5F0 {
    Head_002DA5F0 a;
    char pad18[0x1C - 0x18];
    Tail_002DA5F0 b;
    Obj_002DA5F0();
};

Obj_002DA5F0::Obj_002DA5F0()
{
}
