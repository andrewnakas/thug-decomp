struct G_00217E80 {
    char m_pad[0x464];
    float m464;
};
extern G_00217E80* D_0038FC78;
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

extern "C" int func_00217E80(void* params)
{
    float v = 0.0f;
    func_001E7EB0(params, 0, &v, 0);
    D_0038FC78->m464 = v;
    return 1;
}
