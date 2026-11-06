extern "C" float func_001E5318(unsigned int name, int req);

struct Obj_001B3230 {
    char pad[0x34];
    float m34[4];
    void Method();
};

void Obj_001B3230::Method()
{
    float scale = func_001E5318(0x98CD0C8C, 1);
    float minv = func_001E5318(0x4ABA9798, 1);
    for (int i = 0; i < 4; i++) {
        m34[i] *= scale;
        if (m34[i] < minv)
            m34[i] = 0;
    }
}
