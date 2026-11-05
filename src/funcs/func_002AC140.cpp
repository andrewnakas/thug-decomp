struct Src_002AC140 {
    int m0;
};

struct Dst_002AC140 {
    char pad0[0x15C];
    int m15C;
};

struct Obj_002AC140 {
    Src_002AC140* m0;
    char pad4[0x1C - 4];
    Dst_002AC140* m1C;
    bool Run();
};

bool Obj_002AC140::Run()
{
    m1C->m15C = m0->m0;
    return true;
}
