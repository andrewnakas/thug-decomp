struct Obj_002B85C8 {
    char pad0[0x410];
    int m410;
    float m414;
    float m418;
    float m41C;
    float m420;
    float m424;
    float m428;
    char pad42C[0x104];
    float m530;
    void Set(int a, float b, float c, float d, float e, float f, float g, float h);
};

void Obj_002B85C8::Set(int a, float b, float c, float d, float e, float f, float g, float h) {
    m410 = a;
    m414 = b;
    m418 = c;
    m41C = d;
    m420 = e;
    m424 = f;
    m428 = g;
    m530 = h;
}
