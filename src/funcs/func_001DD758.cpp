struct Node_001DD758 {
    char m_pad0[0x10];
    float m10;
};

extern float D_0038E0A8;
extern "C" int func_001DC418(void* a);
extern "C" Node_001DD758* func_001DCA18(void* a, int b);

extern "C" float func_001DD758(void* a, int b)
{
    if (func_001DC418(a))
        return D_0038E0A8;
    Node_001DD758* n = func_001DCA18(a, b);
    if (!n)
        return 0.0f;
    float f = n->m10;
    return (f == 0.0f) ? D_0038E0A8 : f;
}
