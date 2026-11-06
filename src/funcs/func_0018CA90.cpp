struct Obj_0018CA90 {
    char pad[0x260];
    void* m260;
    char pad2[0x270 - 0x264];
    float m270[4];
    int m280;
    void Set(int i, float v);
};

void Obj_0018CA90::Set(int i, float v)
{
    if (m260) {
        int n = m280;
        if (i > 0 && i <= n) {
            m270[i - 1] = v;
        }
    }
}
